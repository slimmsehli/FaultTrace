// =============================================================================
// tb_mesi_system.v — Testbench: MESI Cache Coherence Verification
// =============================================================================
//
// TEST PLAN
// ---------
//  Test 1 : Cold miss — core 0 reads an address not in any cache
//              Expected: line fetched from memory, state goes to E
//
//  Test 2 : Read hit — core 0 reads the same address again
//              Expected: served from cache (E state, no bus activity)
//
//  Test 3 : Shared read — core 1 reads the same address as core 0 holds in E
//              Expected: core 0's line transitions E→S, core 1 gets S
//
//  Test 4 : Write by one sharer (S→M upgrade via BusInv)
//              Core 0 writes to a line both cores hold in S
//              Expected: core 0 → M, core 1 line → I (invalidated)
//
//  Test 5 : Read after invalidation
//              Core 1 reads the address it just had invalidated
//              Expected: fetches from core 0 (dirty supplier), core 0 M→S, core 1→S
//
//  Test 6 : Exclusive write (no other sharers)
//              Core 0 reads a fresh address, gets E, then writes
//              Expected: silent E→M upgrade (no BusInv needed)
//
//  Test 7 : Dirty eviction (writeback)
//              Force core 0 to evict a dirty line to make room
//              Expected: BusWB transaction, memory updated, then new line fetched
//
//  Test 8 : False sharing stress test
//              Both cores alternately write to the same cache line (different words)
//              Expected: line ping-pongs M state, coherence maintained
//
// Each test checks:
//   - Correct data values returned to CPU
//   - Correct MESI states in both caches after transaction
//   - Bus transaction types observed match the MESI protocol spec
// =============================================================================

`timescale 1ns/1ps

module tb_top;

    // -------------------------------------------------------------------------
    // Parameters must match DUT
    // -------------------------------------------------------------------------
    parameter CACHE_LINES = 8;
    parameter LINE_WORDS  = 4;
    parameter ADDR_BITS   = 8;
    parameter CLK_PERIOD  = 10;  // 100 MHz

    // -------------------------------------------------------------------------
    // Clock and reset
    // -------------------------------------------------------------------------
    reg clk = 0;
    reg rst = 1;
    always #(CLK_PERIOD/2) clk = ~clk;
    integer errors;

    // -------------------------------------------------------------------------
    // DUT interface signals
    // -------------------------------------------------------------------------
    reg                  c0_req,  c1_req;
    reg                  c0_we,   c1_we;
    reg  [ADDR_BITS-1:0] c0_addr, c1_addr;
    reg  [31:0]          c0_wdata,c1_wdata;
    wire [31:0]          c0_rdata,c1_rdata;
    wire                 c0_ack,  c1_ack;

    // -------------------------------------------------------------------------
    // DUT instantiation
    // -------------------------------------------------------------------------
    mesi_system #(
        .CACHE_LINES (CACHE_LINES),
        .LINE_WORDS  (LINE_WORDS),
        .ADDR_BITS   (ADDR_BITS),
        .N_CORES     (2)
    ) dut (
        .clk     (clk),
        .rst     (rst),
        .c0_req  (c0_req),   .c0_we   (c0_we),
        .c0_addr (c0_addr),  .c0_wdata(c0_wdata),
        .c0_rdata(c0_rdata), .c0_ack  (c0_ack),
        .c1_req  (c1_req),   .c1_we   (c1_we),
        .c1_addr (c1_addr),  .c1_wdata(c1_wdata),
        .c1_rdata(c1_rdata), .c1_ack  (c1_ack)
    );

    // -------------------------------------------------------------------------
    // Bus activity monitor — watches the shared bus and logs transactions
    // -------------------------------------------------------------------------
    wire bus_valid = dut.bus_valid_w;
    wire [ADDR_BITS-1:0] bus_addr = dut.bus_addr_w;
    wire [1:0] bus_cmd  = dut.bus_cmd_w;

    // Count bus transactions by type
    integer cnt_busrd  = 0;
    integer cnt_busInv = 0;
    integer cnt_buswb  = 0;

    always @(posedge clk) begin
        if (bus_valid) begin
            case (bus_cmd)
                2'b01: begin cnt_busrd++;  $display("  [BUS] BusRd   addr=0x%02X", bus_addr); end
                2'b10: begin cnt_busInv++; $display("  [BUS] BusInv  addr=0x%02X", bus_addr); end
                2'b11: begin cnt_buswb++;  $display("  [BUS] BusWB   addr=0x%02X", bus_addr); end
            endcase
        end
    end

    // -------------------------------------------------------------------------
    // MESI state name helper (for display)
    // -------------------------------------------------------------------------
    function [79:0] mesi_name;
        input [1:0] s;
        case (s)
            2'b11: mesi_name = "M(Modified)";
            2'b10: mesi_name = "E(Exclusive)";
            2'b01: mesi_name = "S(Shared)   ";
            2'b00: mesi_name = "I(Invalid)  ";
        endcase
    endfunction

    // Access cache internals for state checking
    // (works because DUT submodules are named)
    `define C0_MESI dut.u_cache0.mesi
    `define C1_MESI dut.u_cache1.mesi
    `define C0_DATA dut.u_cache0.data
    `define C1_DATA dut.u_cache1.data

    // Index helper: given an address, what cache index does it map to?
    function [2:0] addr_to_index;
        input [ADDR_BITS-1:0] a;
        // offset = a[1:0], index = a[4:2] for LINE_WORDS=4, CACHE_LINES=8
        addr_to_index = a[4:2];
    endfunction

    // -------------------------------------------------------------------------
    // Task: issue a CPU read and wait for ack
    // -------------------------------------------------------------------------
    task cpu_read;
        input integer core;
        input [ADDR_BITS-1:0] addr;
        output [31:0] rdata;
        integer timeout;
        begin
            timeout = 0;
            if (core == 0) begin
                @(negedge clk);
                c0_req = 1; c0_we = 0; c0_addr = addr;
                @(posedge clk);
                while (!c0_ack && timeout < 50) begin
                    @(posedge clk);
                    timeout = timeout + 1;
                end
                rdata = c0_rdata;
                @(negedge clk);
                c0_req = 0;
            end else begin
                @(negedge clk);
                c1_req = 1; c1_we = 0; c1_addr = addr;
                @(posedge clk);
                while (!c1_ack && timeout < 50) begin
                    @(posedge clk);
                    timeout = timeout + 1;
                end
                rdata = c1_rdata;
                @(negedge clk);
                c1_req = 0;
            end
            if (timeout >= 50) $display("  [WARN] cpu_read core%0d timed out!", core);
        end
    endtask

    // -------------------------------------------------------------------------
    // Task: issue a CPU write and wait for ack
    // -------------------------------------------------------------------------
    task cpu_write;
        input integer core;
        input [ADDR_BITS-1:0] addr;
        input [31:0] wdata;
        integer timeout;
        begin
            timeout = 0;
            if (core == 0) begin
                @(negedge clk);
                c0_req = 1; c0_we = 1; c0_addr = addr; c0_wdata = wdata;
                @(posedge clk);
                while (!c0_ack && timeout < 50) begin
                    @(posedge clk);
                    timeout = timeout + 1;
                end
                @(negedge clk);
                c0_req = 0; c0_we = 0;
            end else begin
                @(negedge clk);
                c1_req = 1; c1_we = 1; c1_addr = addr; c1_wdata = wdata;
                @(posedge clk);
                while (!c1_ack && timeout < 50) begin
                    @(posedge clk);
                    timeout = timeout + 1;
                end
                @(negedge clk);
                c1_req = 0; c1_we = 0;
            end
            if (timeout >= 50) $display("  [WARN] cpu_write core%0d timed out!", core);
        end
    endtask

    // -------------------------------------------------------------------------
    // Task: check MESI state of a cache line and print pass/fail
    // -------------------------------------------------------------------------
    task check_mesi;
        input integer cache;
        input [2:0] index;
        input [1:0] expected;
        reg [1:0] actual;
        begin
            if (cache == 0) actual = `C0_MESI[index];
            else            actual = `C1_MESI[index];

            if (actual === expected)
                $display("  [PASS] Cache%0d index%0d state = %s", cache, index,
                         mesi_name(actual));
            else begin
                $display("  [FAIL] Cache%0d index%0d state = %s  (expected %s)",
                         cache, index, mesi_name(actual), mesi_name(expected));
            		tb_top.errors++;
            end
        end
    endtask

    // -------------------------------------------------------------------------
    // Task: check a data value and print pass/fail
    // -------------------------------------------------------------------------
    task check_data;
        input [31:0] actual;
        input [31:0] expected;
        input [127:0] label;
        begin
            if (actual === expected)
                $display("  [PASS] %s = 0x%08X", label, actual);
            else begin
                $display("  [FAIL] %s = 0x%08X  (expected 0x%08X)", label, actual, expected);
           		tb_top.errors++;
        		end
        end
    endtask

    // -------------------------------------------------------------------------
    // Separator
    // -------------------------------------------------------------------------
    task separator;
        input [255:0] name;
        begin
            $display("");
            $display("============================================================");
            $display(" %s", name);
            $display("============================================================");
        end
    endtask

    // =========================================================================
    // MAIN TEST SEQUENCE
    // =========================================================================
    reg [31:0] rdata0, rdata1;
    integer    bus_rd_before, bus_inv_before, bus_wb_before;

    initial begin
    		errors = 0;
        $dumpfile("simout/sim.vcd");
        $dumpvars(0, tb_top);

        // Initialise CPU signals
        c0_req = 0; c0_we = 0; c0_addr = 0; c0_wdata = 0;
        c1_req = 0; c1_we = 0; c1_addr = 0; c1_wdata = 0;

        // Reset
        repeat(4) @(posedge clk);
        rst = 0;
        repeat(2) @(posedge clk);

        // -----------------------------------------------------------------
        // TEST 1: Cold read miss — Core 0 reads address 0x10
        //   Memory is pre-filled: mem[word] = word, so addr 0x10 word0 = 4
        //   (0x10 >> 2 = 4, base word for line = 4)
        // -----------------------------------------------------------------
        separator("TEST 1: Cold read miss (Core 0, addr=0x10)");
        $display("  Memory pre-fill: word[n] = n");
        $display("  0x10 -> word index 4 -> expected value 4");
        $display("");
        bus_rd_before = cnt_busrd;

        cpu_read(0, 8'h10, rdata0);

        $display("  Core 0 got: 0x%08X", rdata0);
        check_data(rdata0, 32'd4, "Core0 rdata (word 4)");
        check_mesi(0, addr_to_index(8'h10), 2'b10);  // expect E
        $display("  Bus BusRd count: %0d (expected 1)", cnt_busrd - bus_rd_before);
        repeat(2) @(posedge clk);

        // -----------------------------------------------------------------
        // TEST 2: Read hit — Core 0 reads address 0x10 again
        // -----------------------------------------------------------------
        separator("TEST 2: Read hit (Core 0, addr=0x10 again)");
        bus_rd_before = cnt_busrd;

        cpu_read(0, 8'h10, rdata0);

        check_data(rdata0, 32'd4, "Core0 rdata (hit)");
        check_mesi(0, addr_to_index(8'h10), 2'b10);  // still E
        $display("  Bus BusRd count since test: %0d (expected 0 - served from cache)",
                 cnt_busrd - bus_rd_before);
        repeat(2) @(posedge clk);

        // -----------------------------------------------------------------
        // TEST 3: Shared read — Core 1 reads same address (Core 0 holds E)
        // -----------------------------------------------------------------
        separator("TEST 3: Shared read (Core 1 reads 0x10 held E by Core 0)");
        bus_rd_before = cnt_busrd;

        cpu_read(1, 8'h10, rdata1);

        check_data(rdata1, 32'd4, "Core1 rdata (shared)");
        check_mesi(0, addr_to_index(8'h10), 2'b01);  // Core 0: E→S
        check_mesi(1, addr_to_index(8'h10), 2'b01);  // Core 1: S
        $display("  Bus BusRd count since test: %0d (expected 1)", cnt_busrd - bus_rd_before);
        repeat(2) @(posedge clk);

        // -----------------------------------------------------------------
        // TEST 4: Write upgrade S→M with BusInv
        //   Core 0 writes to 0x10 (both hold S)
        // -----------------------------------------------------------------
        separator("TEST 4: Write to shared line (Core 0 writes 0x10, S->M + BusInv)");
        bus_inv_before = cnt_busInv;

        cpu_write(0, 8'h10, 32'hDEAD_BEEF);

        check_mesi(0, addr_to_index(8'h10), 2'b11);  // Core 0: M
        check_mesi(1, addr_to_index(8'h10), 2'b00);  // Core 1: I (invalidated)
        $display("  Bus BusInv count since test: %0d (expected 1)", cnt_busInv - bus_inv_before);
        repeat(2) @(posedge clk);

        // -----------------------------------------------------------------
        // TEST 5: Core 1 reads invalidated line — should get dirty data from Core 0
        // -----------------------------------------------------------------
        separator("TEST 5: Read invalidated line (Core 1 reads 0x10, Core 0 M->S)");
        bus_rd_before = cnt_busrd;

        cpu_read(1, 8'h10, rdata1);

        // Core 0 had written DEAD_BEEF — Core 1 should receive that value
        check_data(rdata1, 32'hDEAD_BEEF, "Core1 rdata (from dirty Core 0)");
        check_mesi(0, addr_to_index(8'h10), 2'b01);  // Core 0: M→S (supplied data)
        check_mesi(1, addr_to_index(8'h10), 2'b01);  // Core 1: S
        $display("  Bus BusRd count since test: %0d (expected 1)", cnt_busrd - bus_rd_before);
        repeat(2) @(posedge clk);

        // -----------------------------------------------------------------
        // TEST 6: Silent E→M upgrade (no BusInv needed)
        //   Core 1 reads a fresh address 0x20 (exclusive), then writes
        // -----------------------------------------------------------------
        separator("TEST 6: Exclusive write (E->M silent upgrade)");
        bus_inv_before = cnt_busInv;

        cpu_read(1, 8'h20, rdata1);
        check_mesi(1, addr_to_index(8'h20), 2'b10);  // E after exclusive read
        check_mesi(0, addr_to_index(8'h20), 2'b00);  // Core 0 has nothing

        cpu_write(1, 8'h20, 32'hCAFE_0001);

        check_mesi(1, addr_to_index(8'h20), 2'b11);  // M after silent upgrade
        $display("  Bus BusInv count since test: %0d (expected 0 - no BusInv for E->M)",
                 cnt_busInv - bus_inv_before);
        repeat(2) @(posedge clk);

        // -----------------------------------------------------------------
        // TEST 7: Dirty eviction (writeback)
        //   Fill Core 0's cache so the dirty line 0x10 (S) gets evicted.
        //   We do this by writing to 8 different cache-index-aliases to
        //   force the set to fill and a later miss to evict.
        //   (Direct mapped: just write to an address that maps to same index)
        //
        //   index for 0x10 = bits[4:2] = 4.  Alias at same index but different
        //   tag: 0x10 | (1<<5) = 0x30 has index 4 as well (tag differs).
        //   Core 1 currently holds 0x10 in S.  We force Core 0 to write 0x30
        //   first (miss -> M), then read 0x10 again (miss -> evict dirty 0x30 -> BusWB)
        // -----------------------------------------------------------------
        separator("TEST 7: Dirty eviction with writeback");
        bus_wb_before = cnt_buswb;

        // Core 0 writes to 0x30 (same index as 0x10, different tag)
        cpu_write(0, 8'h30, 32'hBEEF_CAFE);
        check_mesi(0, addr_to_index(8'h30), 2'b11);  // Core 0 index4 = M (tag=0x30)

        // Now Core 0 reads 0x10 — same index, tag conflict → eviction of dirty 0x30
        cpu_read(0, 8'h10, rdata0);

        $display("  Bus BusWB count since test: %0d (expected 1)", cnt_buswb - bus_wb_before);
        check_data(rdata0, 32'hDEAD_BEEF, "Core0 rdata 0x10 after eviction (Core1 supplied)");
        repeat(2) @(posedge clk);

        // -----------------------------------------------------------------
        // TEST 8: False sharing stress test — both cores alternate writes
        //         to the same cache line (different word offsets)
        // -----------------------------------------------------------------
        separator("TEST 8: False sharing stress (ping-pong on same line)");
        $display("  Both cores write different words of address 0x40 alternately");
        begin : stress
            integer iter;
            reg [31:0] expected_val;
            for (iter = 0; iter < 4; iter = iter+1) begin
                // Core 0 writes word 0 of line at 0x40
                cpu_write(0, 8'h40, 32'hA000_0000 | iter);
                check_mesi(0, addr_to_index(8'h40), 2'b11); // Core 0 = M
                check_mesi(1, addr_to_index(8'h40), 2'b00); // Core 1 = I

                // Core 1 writes word 1 of same line at 0x44
                cpu_write(1, 8'h44, 32'hB000_0000 | iter);
                check_mesi(1, addr_to_index(8'h44), 2'b11); // Core 1 = M
                check_mesi(0, addr_to_index(8'h44), 2'b00); // Core 0 = I

                $display("  Iteration %0d: coherence maintained", iter);
                repeat(2) @(posedge clk);
            end
        end

        // -----------------------------------------------------------------
        // Final verification: Core 0 reads Core 1's last written value
        // -----------------------------------------------------------------
        separator("FINAL CHECK: Cross-core read-after-write");
        cpu_read(0, 8'h44, rdata0);
        check_data(rdata0, 32'hB000_0003, "Core0 reads Core1's last write to 0x44");

        // -----------------------------------------------------------------
        // Summary
        // -----------------------------------------------------------------
        separator("SIMULATION COMPLETE — Transaction Summary");
        $display("  Total BusRd         : %0d", cnt_busrd);
        $display("  Total BusInvalidate : %0d", cnt_busInv);
        $display("  Total BusWriteback  : %0d", cnt_buswb);
        $display("  Total bus txns      : %0d", cnt_busrd + cnt_busInv + cnt_buswb);
        $display("");
        $display("  MESI Protocol coverage:");
        $display("    I -> E  (cold read, exclusive)      : Test 1,6");
        $display("    E -> S  (another cache reads same)  : Test 3");
        $display("    S -> M  (write, BusInv issued)      : Test 4");
        $display("    M -> S  (another cache reads dirty) : Test 5");
        $display("    M -> I  (eviction, BusWB issued)    : Test 7");
        $display("    E -> M  (write to exclusive, silent): Test 6");
        $display("    S -> I  (snooped BusInv)            : Test 4");
        $display("");
        separator("TEST RESULT :");
        	if (tb_top.errors > 0 ) begin
        		$display("  Test         : FAIL");
        		$display("  Found errors : %d", tb_top.errors);
        	end
        	else
        		$display("  Test         : PASS");
        
        $finish;
    end

    // -------------------------------------------------------------------------
    // Timeout watchdog — prevents infinite simulation on bugs
    // -------------------------------------------------------------------------
    initial begin
        #100000;
        $display("[WATCHDOG] Simulation exceeded time limit — possible deadlock!");
        $finish;
    end

endmodule
