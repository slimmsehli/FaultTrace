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

