// =============================================================================
// mesi_cache.v — Direct-mapped write-invalidate cache with MESI coherence
// =============================================================================
//
// MESI State Machine per cache line:
//
//   M (Modified)  — this cache has the only valid copy, it is dirty
//   E (Exclusive) — this cache has the only valid copy, it is clean
//   S (Shared)    — multiple caches may hold clean copies
//   I (Invalid)   — line is not present / stale
//
// Topology: shared snooping bus
//
//   Every cache drives and observes the same bus signals.
//   A transaction is broadcast to ALL caches simultaneously.
//   Each cache snoops the bus and updates its own state accordingly.
//
// Parameters:
//   CACHE_LINES  — number of lines (must be power of 2, default 8)
//   LINE_WORDS   — 32-bit words per line                (default 4 = 16 bytes)
//   ADDR_BITS    — address width                        (default 8)
//
// CPU-side interface (one per cache instance):
//   cpu_req      — CPU wants to do a transaction
//   cpu_we       — 1=write, 0=read
//   cpu_addr     — byte address (word-aligned)
//   cpu_wdata    — write data
//   cpu_rdata    — read data returned to CPU
//   cpu_ack      — cache acknowledges request (1 cycle pulse)
//
// Shared bus interface (connected to all caches and main memory):
//   bus_req      — this cache is requesting the bus
//   bus_grant    — arbiter grants the bus to this cache
//   bus_valid    — a transaction is on the bus (driven by current bus master)
//   bus_addr     — address being transacted
//   bus_cmd      — BUS_READ / BUS_WRITE / BUS_INVALIDATE / BUS_WRITEBACK
//   bus_data     — data payload (cache line)
//   bus_shared   — any snooping cache asserts this if it holds the line
//   bus_dirty    — snooping cache asserts this if it is supplying data (M→S)
//
// =============================================================================

`define MESI_M 2'b11   // Modified
`define MESI_E 2'b10   // Exclusive
`define MESI_S 2'b01   // Shared
`define MESI_I 2'b00   // Invalid

`define BUS_IDLE        2'b00
`define BUS_READ        2'b01   // BusRd  — requesting a clean copy
`define BUS_INVALIDATE  2'b10   // BusInv — demand all others invalidate
`define BUS_WRITEBACK   2'b11   // BusWB  — writing dirty line back to memory

module mesi_cache #(
    parameter CACHE_LINES = 8,
    parameter LINE_WORDS  = 4,
    parameter ADDR_BITS   = 8,
    parameter ID          = 0    // cache/core index for debug
)(
    input  wire                          clk,
    input  wire                          rst,

    // ---- CPU interface ----
    input  wire                          cpu_req,
    input  wire                          cpu_we,
    input  wire [ADDR_BITS-1:0]          cpu_addr,
    input  wire [31:0]                   cpu_wdata,
    output reg  [31:0]                   cpu_rdata,
    output reg                           cpu_ack,

    // ---- Shared bus (all signals shared across all caches) ----
    output reg                           bus_req,    // request bus ownership
    input  wire                          bus_grant,  // arbiter grants ownership
    input  wire                          bus_valid,  // a cmd is on the bus
    input  wire [ADDR_BITS-1:0]          bus_addr,   // address on bus
    input  wire [1:0]                    bus_cmd,    // command
    input  wire [LINE_WORDS*32-1:0]      bus_wdata,  // data from bus master
    output reg  [LINE_WORDS*32-1:0]      bus_rdata,  // data this cache supplies
    output reg                           bus_shared, // I have this line (S/E hint)
    output reg                           bus_dirty,  // I have dirty copy (M state)

    // When we own the bus we drive these:
    output reg                           bus_drive,  // we are the bus master
    output reg [ADDR_BITS-1:0]           bus_out_addr,
    output reg [1:0]                     bus_out_cmd,
    output reg [LINE_WORDS*32-1:0]       bus_out_data
);

    // -------------------------------------------------------------------------
    // Address breakdown
    //   [ ADDR_BITS-1 : INDEX_BITS+OFFSET_BITS ]  tag
    //   [ INDEX_BITS+OFFSET_BITS-1 : OFFSET_BITS ] index
    //   [ OFFSET_BITS-1 : 0 ]                      word offset (2 bits for 4 words)
    // -------------------------------------------------------------------------
    localparam INDEX_BITS  = $clog2(CACHE_LINES);
    localparam OFFSET_BITS = $clog2(LINE_WORDS);
    localparam TAG_BITS    = ADDR_BITS - INDEX_BITS - OFFSET_BITS;

    // Convenience functions to decode an address
    function [OFFSET_BITS-1:0] f_offset(input [ADDR_BITS-1:0] a);
        f_offset = a[OFFSET_BITS-1:0];
    endfunction
    function [INDEX_BITS-1:0] f_index(input [ADDR_BITS-1:0] a);
        f_index = a[OFFSET_BITS +: INDEX_BITS];
    endfunction
    function [TAG_BITS-1:0] f_tag(input [ADDR_BITS-1:0] a);
        f_tag = a[ADDR_BITS-1 : OFFSET_BITS+INDEX_BITS];
    endfunction

    // -------------------------------------------------------------------------
    // Cache storage
    // -------------------------------------------------------------------------
    reg [TAG_BITS-1:0]         tag   [0:CACHE_LINES-1];
    reg [1:0]                  mesi  [0:CACHE_LINES-1];   // MESI state
    reg [LINE_WORDS*32-1:0]    data  [0:CACHE_LINES-1];   // cache line data

    // -------------------------------------------------------------------------
    // Internal wires for current CPU request
    // -------------------------------------------------------------------------
    wire [OFFSET_BITS-1:0] cpu_offset = f_offset(cpu_addr);
    wire [INDEX_BITS-1:0]  cpu_index  = f_index (cpu_addr);
    wire [TAG_BITS-1:0]    cpu_tag    = f_tag   (cpu_addr);

    wire hit = cpu_req &&
               (mesi[cpu_index] != `MESI_I) &&
               (tag[cpu_index]  == cpu_tag);

    // -------------------------------------------------------------------------
    // Snoop logic — applied to bus transactions we did NOT initiate
    // -------------------------------------------------------------------------
    wire [INDEX_BITS-1:0]  snoop_index  = f_index (bus_addr);
    wire [TAG_BITS-1:0]    snoop_tag    = f_tag   (bus_addr);
    wire snoop_hit = bus_valid && !bus_drive &&
                     (mesi[snoop_index] != `MESI_I) &&
                     (tag[snoop_index]  == snoop_tag);

    // -------------------------------------------------------------------------
    // State machine
    // -------------------------------------------------------------------------
    localparam ST_IDLE      = 3'd0;
    localparam ST_HIT       = 3'd1;   // process a cache hit
    localparam ST_MISS_ARB  = 3'd2;   // wait for bus grant (need a fetch)
    localparam ST_MISS_TX   = 3'd3;   // drive BusRd or BusInv on the bus
    localparam ST_MISS_WAIT = 3'd4;   // wait for memory/other cache to respond
    localparam ST_WB_ARB    = 3'd5;   // need to writeback before eviction
    localparam ST_WB_TX     = 3'd6;   // drive BusWB

    reg [2:0] state;
    reg       pending_we;
    reg [ADDR_BITS-1:0] pending_addr;
    reg [31:0]          pending_wdata;

    integer i;

    always @(posedge clk) begin
        if (rst) begin
            state      <= ST_IDLE;
            cpu_ack    <= 0;
            bus_req    <= 0;
            bus_drive  <= 0;
            bus_shared <= 0;
            bus_dirty  <= 0;
            bus_rdata  <= 0;
            for (i = 0; i < CACHE_LINES; i = i+1) begin
                mesi[i] <= `MESI_I;
                tag[i]  <= 0;
                data[i] <= 0;
            end
        end else begin
            // Defaults — deassert strobes each cycle
            cpu_ack    <= 0;
            bus_shared <= 0;
            bus_dirty  <= 0;
            bus_drive  <= 0;

            // =================================================================
            // SNOOP — handle other caches' bus transactions every cycle
            // regardless of our own state (except when we are driving the bus)
            // =================================================================
            if (snoop_hit) begin
                case (bus_cmd)

                    `BUS_READ: begin
                        // Another cache wants our line
                        if (mesi[snoop_index] == `MESI_M) begin
                            // We have the dirty copy — supply it and go S
                            bus_rdata  <= data[snoop_index];
                            bus_dirty  <= 1;           // signal: we are providing data
                            mesi[snoop_index] <= `MESI_S;
                        end else begin
                            // S or E — just signal shared, transition E→S
                            bus_shared <= 1;
                            if (mesi[snoop_index] == `MESI_E)
                                mesi[snoop_index] <= `MESI_S;
                        end
                    end

                    `BUS_INVALIDATE: begin
                        // Someone is writing — we must invalidate our copy
                        mesi[snoop_index] <= `MESI_I;
                    end

                    `BUS_WRITEBACK: begin
                        // Another cache is writing back; nothing to do for us
                    end

                endcase
            end

            // =================================================================
            // MAIN STATE MACHINE
            // =================================================================
            case (state)

                // -------------------------------------------------------------
                ST_IDLE: begin
                    if (cpu_req) begin
                        pending_we    <= cpu_we;
                        pending_addr  <= cpu_addr;
                        pending_wdata <= cpu_wdata;

                        if (hit) begin
                            state <= ST_HIT;
                        end else begin
                            // Check if the line to evict is dirty (needs WB first)
                            if (mesi[cpu_index] == `MESI_M) begin
                                state   <= ST_WB_ARB;
                                bus_req <= 1;
                            end else begin
                                state   <= ST_MISS_ARB;
                                bus_req <= 1;
                            end
                        end
                    end
                end

                // -------------------------------------------------------------
                ST_HIT: begin
                    if (!pending_we) begin
                        // Read hit — extract the right word from the line
                        cpu_rdata <= data[f_index(pending_addr)]
                                         [f_offset(pending_addr)*32 +: 32];
                        cpu_ack   <= 1;
                        state     <= ST_IDLE;
                    end else begin
                        // Write hit
                        case (mesi[f_index(pending_addr)])
                            `MESI_M: begin
                                // Already owned — just write
                                data[f_index(pending_addr)]
                                    [f_offset(pending_addr)*32 +: 32] <= pending_wdata;
                                cpu_ack <= 1;
                                state   <= ST_IDLE;
                            end
                            `MESI_E: begin
                                // Exclusive — upgrade to M silently (no bus needed)
                                data[f_index(pending_addr)]
                                    [f_offset(pending_addr)*32 +: 32] <= pending_wdata;
                                mesi[f_index(pending_addr)] <= `MESI_M;
                                cpu_ack <= 1;
                                state   <= ST_IDLE;
                            end
                            `MESI_S: begin
                                // Shared — must broadcast BusInv before writing
                                bus_req <= 1;
                                state   <= ST_MISS_ARB;  // reuse miss path for BusInv
                            end
                            default: state <= ST_IDLE;
                        endcase
                    end
                end

                // -------------------------------------------------------------
                ST_WB_ARB: begin
                    // Waiting for bus grant to do a writeback of dirty evicted line
                    if (bus_grant) begin
                        bus_drive    <= 1;
                        bus_out_cmd  <= `BUS_WRITEBACK;
                        // Reconstruct the address of the dirty line being evicted
                        bus_out_addr <= {tag[f_index(pending_addr)],
                                         f_index(pending_addr),
                                         {OFFSET_BITS{1'b0}}};
                        bus_out_data <= data[f_index(pending_addr)];
                        mesi[f_index(pending_addr)] <= `MESI_I;
                        state <= ST_WB_TX;
                    end
                end

                ST_WB_TX: begin
                    // Writeback done — now go fetch the new line
                    bus_drive  <= 0;
                    bus_req    <= 1;
                    state      <= ST_MISS_ARB;
                end

                // -------------------------------------------------------------
                ST_MISS_ARB: begin
                    if (bus_grant) begin
                        bus_drive <= 1;
                        if (pending_we && mesi[f_index(pending_addr)] == `MESI_S) begin
                            // S→M upgrade: BusInv (we already have the data)
                            bus_out_cmd  <= `BUS_INVALIDATE;
                            bus_out_addr <= pending_addr;
                            bus_out_data <= 0;
                        end else begin
                            // Cold miss or read miss: BusRd
                            bus_out_cmd  <= `BUS_READ;
                            bus_out_addr <= pending_addr;
                            bus_out_data <= 0;
                        end
                        state <= ST_MISS_TX;
                    end
                end

                // -------------------------------------------------------------
                ST_MISS_TX: begin
                    bus_drive <= 0;
                    bus_req   <= 0;

                    if (bus_out_cmd == `BUS_INVALIDATE) begin
                        // BusInv issued: we can now write (we keep our S data, upgrade to M)
                        data[f_index(pending_addr)]
                            [f_offset(pending_addr)*32 +: 32] <= pending_wdata;
                        mesi[f_index(pending_addr)] <= `MESI_M;
                        cpu_ack <= 1;
                        state   <= ST_IDLE;
                    end else begin
                        // BusRd issued: wait one cycle for memory/snoop to provide data
                        state <= ST_MISS_WAIT;
                    end
                end

                // -------------------------------------------------------------
                ST_MISS_WAIT: begin
                    // Data arrives on bus_wdata (from memory controller or snooping cache)
                    // bus_shared tells us if another cache also has this line
                    tag [f_index(pending_addr)] <= f_tag(pending_addr);
                    data[f_index(pending_addr)] <= bus_wdata;

                    if (pending_we) begin
                        // Write-miss: load line then immediately write and go M
                        data[f_index(pending_addr)]
                            [f_offset(pending_addr)*32 +: 32] <= pending_wdata;
                        mesi[f_index(pending_addr)] <= `MESI_M;
                    end else begin
                        // Read-miss: go E if no other cache has it, else S
                        mesi[f_index(pending_addr)] <= bus_shared ? `MESI_S : `MESI_E;
                        cpu_rdata <= bus_wdata[f_offset(pending_addr)*32 +: 32];
                    end

                    cpu_ack <= 1;
                    state   <= ST_IDLE;
                end

            endcase
        end
    end

endmodule
