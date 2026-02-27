// ----------------------------------------------------------------------------
// 7. Top Module
// ----------------------------------------------------------------------------
module top;
    
    logic clk;
    logic rst_n;

    // Clock Generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Reset Generation
    initial begin
        rst_n = 0;
        #20 rst_n = 1;
    end

    // Interface
    i2c_if intf(clk, rst_n);

    // Pull-up resistors
    // Now valid because intf.scl and intf.sda are wires
    pullup(intf.sda);
    pullup(intf.scl);

    // DUT Instantiation
    i2c_slave_dut dut (
        .clk(clk),
        .rst_n(rst_n),
        .scl(intf.scl), 
        .sda(intf.sda)  
    );

    // UVM Start
    initial begin
      $dumpfile("sim.vcd");
      //$dumpvars(0);
      $dumpvars(0, top);
        uvm_config_db#(virtual i2c_if)::set(null, "*", "vif", intf);
        run_test("i2c_test");
    end

endmodule
