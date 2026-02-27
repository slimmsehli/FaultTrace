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
