module top;
	parameter integer ADDR_WIDTH = 4;                // number of address bits
  parameter integer DATA_WIDTH = 4;               // data bus width
  parameter integer DEPTH      = (1 << ADDR_WIDTH);// number of registers
  parameter         SYNC_READ  = 1 ;                // 1=registered read, 0=combinational
  
	real vdd;
	real vss;
	
	reg en;
	reg [ADDR_WIDTH-1:0] addr;
	wire [DATA_WIDTH-1:0] data;
	reg [DATA_WIDTH-1:0] data_drive;
	reg drive_en;
	reg rnw;
	
	assign #1us vdd = 1.9;
	assign vss = 0.0;
	
	reg rst, clk;
	initial begin clk=0; rst = 0;#1us;rst = 1;rst = 0; end
	always #2us clk=~clk;
	
	reg_bank #( .ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH), .DEPTH(DEPTH), .SYNC_READ(SYNC_READ))
	reg_bank_i(.clk(clk), .rst(rst), .en(en), .rnw(rnw), .addr(addr), .data(data));
	assign data = drive_en ? data_drive : {DATA_WIDTH{1'bz}};
	
	always @(negedge clk) begin	
	// WRITE
		addr     <= $urandom_range(0, 15);
		rnw      <= 1'b0;
		en       <= 1'b1;
		drive_en <= 1'b1;
		data_drive <= $urandom_range(0, 15);
		@(posedge clk);
		en <= 0; drive_en <= 0;
	end
	
	initial begin
	 #30us;
	 $finish;
	end
	
	initial begin
		$dumpfile("sim.vcd"); // Specify the VCD file name
    $dumpvars(0, top);    // Dump all signals in the current module and below
	end
endmodule

