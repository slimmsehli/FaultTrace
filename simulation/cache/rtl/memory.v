// =============================================================================
// main_memory.v — Simple word-addressed memory that responds to BusRd/BusWB
// =============================================================================
// One cycle latency for reads, immediate for writes.
// In a real system this would be DRAM with many more cycles.
// =============================================================================

module main_memory #(
    parameter ADDR_BITS  = 8,
    parameter LINE_WORDS = 4,
    parameter DEPTH      = 256
)(
    input  wire                       clk,
    input  wire                       rst,

    // Shared bus observation (memory is always a slave, never a master)
    input  wire                       bus_valid,
    input  wire [ADDR_BITS-1:0]       bus_addr,
    input  wire [1:0]                 bus_cmd,
    input  wire [LINE_WORDS*32-1:0]   bus_wdata,  // used on BUS_WRITEBACK
    input  wire                       bus_dirty,  // a cache is supplying data

    // Memory provides read data the cycle after BusRd
    output reg  [LINE_WORDS*32-1:0]   mem_rdata,
    output reg                        mem_valid   // rdata is valid this cycle
);

    `define BUS_READ       2'b01
    `define BUS_WRITEBACK  2'b11

    localparam LINE_BYTES  = LINE_WORDS * 4;
    localparam LINES       = DEPTH / LINE_WORDS;

    reg [31:0] mem [0:DEPTH-1];

    integer k;
    initial begin
        for (k = 0; k < DEPTH; k = k+1)
            mem[k] = k;   // pre-fill with address value for easy checking
    end

    // Word-aligned line base index
    wire [$clog2(DEPTH)-1:0] base = (bus_addr >> (2 + $clog2(LINE_WORDS))) * LINE_WORDS; //FIX
    //wire [$clog2(DEPTH)-1:0] base = bus_addr[ADDR_BITS-1:2] * LINE_WORDS;

    always @(posedge clk) begin
        mem_valid <= 0;
        if (bus_valid) begin
            case (bus_cmd)
                `BUS_READ: begin
                    // Only respond if no cache is supplying dirty data
                    if (!bus_dirty) begin
                        mem_rdata[  0 +: 32] <= mem[base+0];
                        mem_rdata[ 32 +: 32] <= mem[base+1];
                        mem_rdata[ 64 +: 32] <= mem[base+2];
                        mem_rdata[ 96 +: 32] <= mem[base+3];
                        mem_valid <= 1;
                    end
                end
                `BUS_WRITEBACK: begin
                    // Write dirty data back into memory
                    mem[base+0] <= bus_wdata[  0 +: 32];
                    mem[base+1] <= bus_wdata[ 32 +: 32];
                    mem[base+2] <= bus_wdata[ 64 +: 32];
                    mem[base+3] <= bus_wdata[ 96 +: 32];
                end
            endcase
        end
    end

endmodule
