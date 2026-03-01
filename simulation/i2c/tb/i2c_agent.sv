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
