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
