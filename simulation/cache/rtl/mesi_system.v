// =============================================================================
// mesi_system.v — Top-level: 2 cores, 2 caches, arbiter, main memory
// =============================================================================

module mesi_system #(
    parameter CACHE_LINES = 8,
    parameter LINE_WORDS  = 4,
    parameter ADDR_BITS   = 8,
    parameter N_CORES     = 2
)(
    input wire clk,
    input wire rst,

    // Core 0 CPU interface
    input  wire                 c0_req,
    input  wire                 c0_we,
    input  wire [ADDR_BITS-1:0] c0_addr,
    input  wire [31:0]          c0_wdata,
    output wire [31:0]          c0_rdata,
    output wire                 c0_ack,

    // Core 1 CPU interface
    input  wire                 c1_req,
    input  wire                 c1_we,
    input  wire [ADDR_BITS-1:0] c1_addr,
    input  wire [31:0]          c1_wdata,
    output wire [31:0]          c1_rdata,
    output wire                 c1_ack
);

    // -------------------------------------------------------------------------
    // Shared bus wires
    // -------------------------------------------------------------------------
    wire [1:0]             bus_grant;
    wire [1:0]             bus_req_w;

    // Each cache drives these when it owns the bus
    wire [ADDR_BITS-1:0]   bus_addr_c0, bus_addr_c1;
    wire [1:0]             bus_cmd_c0,  bus_cmd_c1;
    wire [LINE_WORDS*32-1:0] bus_data_c0, bus_data_c1;
    wire                   bus_drive_c0, bus_drive_c1;

    // Shared bus (muxed from whoever has the grant)
    wire                   bus_valid_w;
    wire [ADDR_BITS-1:0]   bus_addr_w;
    wire [1:0]             bus_cmd_w;
    wire [LINE_WORDS*32-1:0] bus_wdata_w;

    assign bus_valid_w = bus_drive_c0 | bus_drive_c1;
    assign bus_addr_w  = bus_drive_c0 ? bus_addr_c0 : bus_addr_c1;
    assign bus_cmd_w   = bus_drive_c0 ? bus_cmd_c0  : bus_cmd_c1;
    assign bus_wdata_w = bus_drive_c0 ? bus_data_c0 : bus_data_c1;

    // Snoop response wires (any cache can assert these)
    wire [LINE_WORDS*32-1:0] snoop_rdata_c0, snoop_rdata_c1;
    wire                     snoop_shared_c0, snoop_shared_c1;
    wire                     snoop_dirty_c0,  snoop_dirty_c1;

    // Merged snoop signals — OR of all caches' responses
    wire snoop_shared_any = snoop_shared_c0 | snoop_shared_c1;
    wire snoop_dirty_any  = snoop_dirty_c0  | snoop_dirty_c1;
    // Dirty cache supplies data; otherwise memory supplies it
    wire [LINE_WORDS*32-1:0] snoop_rdata_any =
        snoop_dirty_c0 ? snoop_rdata_c0 :
        snoop_dirty_c1 ? snoop_rdata_c1 : 0;

    // Memory read data
    wire [LINE_WORDS*32-1:0] mem_rdata_w;
    wire                     mem_valid_w;

    // Data delivered to caches on a miss = dirty snoop data OR memory data
    wire [LINE_WORDS*32-1:0] fill_data = snoop_dirty_any ? snoop_rdata_any : mem_rdata_w;

    // -------------------------------------------------------------------------
    // Arbiter
    // -------------------------------------------------------------------------
    bus_arbiter #(.N(N_CORES)) u_arb (
        .clk   (clk),
        .rst   (rst),
        .req   (bus_req_w),
        .grant (bus_grant)
    );

    // -------------------------------------------------------------------------
    // Cache 0
    // -------------------------------------------------------------------------
    mesi_cache #(
        .CACHE_LINES (CACHE_LINES),
        .LINE_WORDS  (LINE_WORDS),
        .ADDR_BITS   (ADDR_BITS),
        .ID          (0)
    ) u_cache0 (
        .clk           (clk),
        .rst           (rst),
        .cpu_req       (c0_req),
        .cpu_we        (c0_we),
        .cpu_addr      (c0_addr),
        .cpu_wdata     (c0_wdata),
        .cpu_rdata     (c0_rdata),
        .cpu_ack       (c0_ack),
        .bus_req       (bus_req_w[0]),
        .bus_grant     (bus_grant[0]),
        .bus_valid     (bus_valid_w),
        .bus_addr      (bus_addr_w),
        .bus_cmd       (bus_cmd_w),
        .bus_wdata     (fill_data),        // data from memory or dirty snoop
        .bus_rdata     (snoop_rdata_c0),
        .bus_shared    (snoop_shared_c0),
        .bus_dirty     (snoop_dirty_c0),
        .bus_drive     (bus_drive_c0),
        .bus_out_addr  (bus_addr_c0),
        .bus_out_cmd   (bus_cmd_c0),
        .bus_out_data  (bus_data_c0)
    );

    // -------------------------------------------------------------------------
    // Cache 1
    // -------------------------------------------------------------------------
    mesi_cache #(
        .CACHE_LINES (CACHE_LINES),
        .LINE_WORDS  (LINE_WORDS),
        .ADDR_BITS   (ADDR_BITS),
        .ID          (1)
    ) u_cache1 (
        .clk           (clk),
        .rst           (rst),
        .cpu_req       (c1_req),
        .cpu_we        (c1_we),
        .cpu_addr      (c1_addr),
        .cpu_wdata     (c1_wdata),
        .cpu_rdata     (c1_rdata),
        .cpu_ack       (c1_ack),
        .bus_req       (bus_req_w[1]),
        .bus_grant     (bus_grant[1]),
        .bus_valid     (bus_valid_w),
        .bus_addr      (bus_addr_w),
        .bus_cmd       (bus_cmd_w),
        .bus_wdata     (fill_data),
        .bus_rdata     (snoop_rdata_c1),
        .bus_shared    (snoop_shared_c1),
        .bus_dirty     (snoop_dirty_c1),
        .bus_drive     (bus_drive_c1),
        .bus_out_addr  (bus_addr_c1),
        .bus_out_cmd   (bus_cmd_c1),
        .bus_out_data  (bus_data_c1)
    );

    // -------------------------------------------------------------------------
    // Main memory
    // -------------------------------------------------------------------------
    main_memory #(
        .ADDR_BITS  (ADDR_BITS),
        .LINE_WORDS (LINE_WORDS),
        .DEPTH      (256)
    ) u_mem (
        .clk       (clk),
        .rst       (rst),
        .bus_valid (bus_valid_w),
        .bus_addr  (bus_addr_w),
        .bus_cmd   (bus_cmd_w),
        .bus_wdata (bus_wdata_w),
        .bus_dirty (snoop_dirty_any),
        .mem_rdata (mem_rdata_w),
        .mem_valid (mem_valid_w)
    );

endmodule
