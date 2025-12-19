
// -------------------------------------------------------------
// Register Bank with single address bus and bidirectional data bus
// - rnw = 1 -> READ: bank drives 'data' with the addressed register
// - rnw = 0 -> WRITE: external master must drive 'data'
// - en  gates a transaction (both read and write)
// - rst is active-high synchronous reset
// - clk is the rising-edge clock
//
// Note: In FPGAs, tri-states are only supported at top-level I/O pins.
//       This module is suitable as a top-level interface or for ASICs.
// -------------------------------------------------------------
module reg_bank #(
    parameter integer ADDR_WIDTH = 4,                // number of address bits
    parameter integer DATA_WIDTH = 32,               // data bus width
    parameter integer DEPTH      = (1 << ADDR_WIDTH),// number of registers
    parameter         SYNC_READ  = 1                 // 1=registered read, 0=combinational
)(
    input  wire                        clk,
    input  wire                        rst,   // active-high synchronous reset
    input  wire                        en,    // enable transaction
    input  wire                        rnw,   // 1=read, 0=write
    input  wire [ADDR_WIDTH-1:0]       addr,  // address line
    inout  wire [DATA_WIDTH-1:0]       data   // bidirectional data line
);

    // Storage
    reg [DATA_WIDTH-1:0] mem [0:DEPTH-1];

    // Read datapath register
    reg [DATA_WIDTH-1:0] read_q;

    // Tri-state drive:
    // Drive 'data' only when en && rnw (read), else float (Z)
    assign data = (en && rnw) ? read_q : {DATA_WIDTH{1'bz}};

    // Read path: configurable as synchronous (registered) or combinational
    generate
        if (SYNC_READ) begin : g_sync_read
            // Synchronous read: output updates after clk edge
            always @(posedge clk) begin
                if (rst) begin
                    read_q <= {DATA_WIDTH{1'b0}};
                end else if (en && rnw) begin
                    read_q <= mem[addr];
                end
            end
        end else begin : g_comb_read
            // Combinational read: output follows the addressed register
            // Note: no reset for combinational logic
            always @* begin
                read_q = mem[addr];
            end
        end
    endgenerate

    // Write path: capture data on rising edge when en && !rnw
    integer i;
    always @(posedge clk) begin
        if (rst) begin
            // Synchronous clear of all registers
            for (i = 0; i < DEPTH; i = i + 1) begin
                mem[i] <= {DATA_WIDTH{1'b0}};
            end
        end else if (en && !rnw) begin
            // External master must be driving 'data' during writes
            mem[addr] <= data;
        end
    end

endmodule

