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
