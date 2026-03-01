// i2c_slave_dut.sv
module i2c_slave_dut (
    input  wire clk,      // System clock
    input  wire rst_n,    // Active low reset
    input  wire scl,      // I2C Clock
    inout  wire sda       // I2C Data
);

    // Hardcoded Slave Address (7-bit)
    localparam [6:0] SLAVE_ADDR = 7'h50;

    // FSM States
    typedef enum logic [2:0] {
        IDLE,
        MATCH_ADDR,
        ACK_ADDR,
        READ_DATA,
        ACK_DATA
    } state_t;

    state_t state;
    logic [7:0] shift_reg;
    logic [3:0] bit_cnt;
    logic sda_out_en;     // Controls driving SDA low

    // Start/Stop Detection
    // In I2C, Start = SDA falling while SCL is high
    // Stop = SDA rising while SCL is high
    logic sda_d, scl_d;
    logic start_detected, stop_detected;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            sda_d <= 1'b1;
            scl_d <= 1'b1;
        end else begin
            sda_d <= sda;
            scl_d <= scl;
        end
    end

    assign start_detected = (scl && scl_d) && (sda_d && !sda);
    assign stop_detected  = (scl && scl_d) && (!sda_d && sda);

    // Open-drain logic: only drive 0, otherwise float (z)
    assign sda = (sda_out_en) ? 1'b0 : 1'bz;
	
    logic scl_falling; logic scl_rising;
    // Main FSM
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            sda_out_en <= 1'b0;
            bit_cnt <= 0;
            shift_reg <= 0;
        end else begin
            if (start_detected) begin
                state <= MATCH_ADDR;
                bit_cnt <= 0;
                sda_out_en <= 1'b0;
            end else if (stop_detected) begin
                state <= IDLE;
            end else begin
                
                // Sampling on rising edge of SCL (Standard I2C behavior)
                // Note: Simplified sampling logic using system clock edge detection of SCL
                scl_rising = (scl && !scl_d);

                scl_falling = (!scl && scl_d);

                case (state)
                    IDLE: begin
                        sda_out_en <= 1'b0;
                    end

                    MATCH_ADDR: begin
                        if (scl_rising) begin
                            shift_reg <= {shift_reg[6:0], sda};
                            if (bit_cnt == 7) begin
                                // 7 bits addr + 1 bit R/W. 
                                // We check top 7 bits against SLAVE_ADDR
                                if (shift_reg[6:0] == SLAVE_ADDR) begin
                                    state <= ACK_ADDR;
                                end else begin
                                    state <= IDLE; // Not our address
                                end
                                bit_cnt <= 0;
                            end else begin
                                bit_cnt <= bit_cnt + 1;
                            end
                        end
                    end

                    ACK_ADDR: begin
                        // Drive ACK (Low) during the 9th clock pulse
                        if (!scl) sda_out_en <= 1'b1; // Setup before rising edge
                        
                        if (scl_falling) begin
                            sda_out_en <= 1'b0; // Release after clock falls
                            state <= READ_DATA;
                            bit_cnt <= 0;
                        end
                    end

                    READ_DATA: begin
                        if (scl_rising) begin
                            shift_reg <= {shift_reg[6:0], sda};
                            if (bit_cnt == 7) begin
                                state <= ACK_DATA;
                                bit_cnt <= 0;
                            end else begin
                                bit_cnt <= bit_cnt + 1;
                            end
                        end
                    end

                    ACK_DATA: begin
                         // Drive ACK (Low)
                        if (!scl) sda_out_en <= 1'b1;
                        
                        if (scl_falling) begin
                            sda_out_en <= 1'b0;
                            state <= IDLE; // Transaction done for this simple example
                        end
                    end
                endcase
            end
        end
    end

endmodule