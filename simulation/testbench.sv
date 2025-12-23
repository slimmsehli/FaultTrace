// i2c_uvm_tb.sv
`include "uvm_macros.svh"
import uvm_pkg::*;

// ----------------------------------------------------------------------------
// 1. Interface (CORRECTED)
// ----------------------------------------------------------------------------
interface i2c_if(input logic clk, input logic rst_n);
    // 1. The physical bus lines must be wires (nets) to support pullups
    wire scl;
    wire sda;
    
    // 2. Variables for the Driver to control
    // Logic: 0 = Drive Low, 1 = Float (let pullup pull High)
    logic scl_drive_out; 
    logic sda_drive_out; 

    // 3. Connect Driver variables to the Bus (Open Drain modeling)
    // If drive_out is 0, we drive 0. If 1, we drive Z (High impedance).
    assign scl = (scl_drive_out === 1'b0) ? 1'b0 : 1'bz;
    assign sda = (sda_drive_out === 1'b0) ? 1'b0 : 1'bz;

endinterface

// ----------------------------------------------------------------------------
// 2. Sequence Item
// ----------------------------------------------------------------------------
class i2c_item extends uvm_sequence_item;
    rand logic [6:0] addr;
    rand logic [7:0] data;
    rand logic       rw; // 0 = Write, 1 = Read

    `uvm_object_utils_begin(i2c_item)
        `uvm_field_int(addr, UVM_ALL_ON)
        `uvm_field_int(data, UVM_ALL_ON)
        `uvm_field_int(rw,   UVM_ALL_ON)
    `uvm_object_utils_end

    constraint addr_c { addr == 7'h50; }
    constraint rw_c   { rw == 0; } // Write only

    function new(string name = "i2c_item");
        super.new(name);
    endfunction
endclass

// ----------------------------------------------------------------------------
// 3. Driver (Acts as I2C Master)
// ----------------------------------------------------------------------------
class i2c_driver extends uvm_driver #(i2c_item);
    `uvm_component_utils(i2c_driver)

    virtual i2c_if vif;
    
    // I2C Timing variables (cycles)
    int quarter_period = 5; 

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if(!uvm_config_db#(virtual i2c_if)::get(this, "", "vif", vif))
            `uvm_fatal("DRV", "Could not get interface")
    endfunction

    task run_phase(uvm_phase phase);
        // Initialize lines to Float (High)
        vif.scl_drive_out <= 1'b1;
        vif.sda_drive_out <= 1'b1; 

        forever begin
            seq_item_port.get_next_item(req);
            drive_transaction(req);
            seq_item_port.item_done();
        end
    endtask

    // ---------------------------------------
    // Bit-Banging Logic
    // ---------------------------------------
    task drive_transaction(i2c_item item);
        `uvm_info("DRV", $sformatf("Starting Write: Addr=%0h Data=%0h", item.addr, item.data), UVM_LOW)

        send_start();
        send_byte({item.addr, item.rw});
        check_ack("Address");
        send_byte(item.data);
        check_ack("Data");
        send_stop();
        
        repeat(20) @(posedge vif.clk);
    endtask

    task send_start();
        // Start: SDA falls while SCL is High
        vif.sda_drive_out <= 1'b1;
        vif.scl_drive_out <= 1'b1;
        repeat(quarter_period) @(posedge vif.clk);
        
        vif.sda_drive_out <= 1'b0; // SDA falls
        repeat(quarter_period) @(posedge vif.clk);
        
        vif.scl_drive_out <= 1'b0; // SCL falls
    endtask

    task send_stop();
        // Stop: SDA rises while SCL is High
        vif.sda_drive_out <= 1'b0;
        repeat(quarter_period) @(posedge vif.clk);
        
        vif.scl_drive_out <= 1'b1; // SCL Rises
        repeat(quarter_period) @(posedge vif.clk);
        
        vif.sda_drive_out <= 1'b1; // SDA Rises
        repeat(quarter_period) @(posedge vif.clk);
    endtask

    task send_byte(logic [7:0] byte_data);
        for(int i=7; i>=0; i--) begin
            // Change data while SCL is low
            vif.sda_drive_out <= byte_data[i];
            repeat(quarter_period) @(posedge vif.clk);
            
            // Pulse SCL
            vif.scl_drive_out <= 1'b1;
            repeat(quarter_period*2) @(posedge vif.clk);
            vif.scl_drive_out <= 1'b0;
            repeat(quarter_period) @(posedge vif.clk);
        end
    endtask

    task check_ack(string phase_name);
        // Master releases SDA (float to High) to read ACK from Slave
        vif.sda_drive_out <= 1'b1; 
        
        repeat(quarter_period) @(posedge vif.clk);
        vif.scl_drive_out <= 1'b1; 
        
        // Sample SDA
        repeat(quarter_period) @(posedge vif.clk);
        if(vif.sda === 1'b0) begin
            `uvm_info("DRV", $sformatf("ACK received during %s phase", phase_name), UVM_LOW)
        end else begin
            `uvm_error("DRV", $sformatf("NACK (No ACK) received during %s phase", phase_name))
        end
        repeat(quarter_period) @(posedge vif.clk);

        vif.scl_drive_out <= 1'b0;
    endtask

endclass

// ----------------------------------------------------------------------------
// 4. Agent & Env
// ----------------------------------------------------------------------------
class i2c_agent extends uvm_agent;
    `uvm_component_utils(i2c_agent)
    
    i2c_driver    driver;
    uvm_sequencer #(i2c_item) sequencer;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        driver = i2c_driver::type_id::create("driver", this);
        sequencer = uvm_sequencer#(i2c_item)::type_id::create("sequencer", this);
    endfunction

    function void connect_phase(uvm_phase phase);
        driver.seq_item_port.connect(sequencer.seq_item_export);
    endfunction
endclass

class i2c_env extends uvm_env;
    `uvm_component_utils(i2c_env)
    i2c_agent agent;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        agent = i2c_agent::type_id::create("agent", this);
    endfunction
endclass

// ----------------------------------------------------------------------------
// 5. Sequence (3 Transactions)
// ----------------------------------------------------------------------------
class i2c_3_writes_seq extends uvm_sequence #(i2c_item);
    `uvm_object_utils(i2c_3_writes_seq)

    function new(string name = "i2c_3_writes_seq");
        super.new(name);
    endfunction

    task body();
        i2c_item item;
        repeat(3) begin
            item = i2c_item::type_id::create("item");
            start_item(item);
            if(!item.randomize()) `uvm_error("SEQ", "Randomization Failed")
            finish_item(item);
        end
    endtask
endclass

// ----------------------------------------------------------------------------
// 6. Test
// ----------------------------------------------------------------------------
class i2c_test extends uvm_test;
    `uvm_component_utils(i2c_test)
    i2c_env env;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        env = i2c_env::type_id::create("env", this);
    endfunction

    task run_phase(uvm_phase phase);
        i2c_3_writes_seq seq;
        phase.raise_objection(this);
        seq = i2c_3_writes_seq::type_id::create("seq");
        seq.start(env.agent.sequencer);
        phase.drop_objection(this);
    endtask
endclass

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
