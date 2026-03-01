// =============================================================================
// bus_arbiter.v — Round-robin bus arbiter for N caches
// =============================================================================
// Grants the bus to one requester at a time.
// Grant is held until the master de-asserts bus_req.
// =============================================================================

module bus_arbiter #(
    parameter N = 2   // number of caches
)(
    input  wire         clk,
    input  wire         rst,
    input  wire [N-1:0] req,     // request from each cache
    output reg  [N-1:0] grant    // one-hot grant
);
    reg [$clog2(N)-1:0] last;

    always @(posedge clk) begin
        if (rst) begin
            grant <= 0;
            last  <= 0;
        end else begin
            if (|(grant & req)) begin
                // Current grantee still requesting — hold grant
            end else begin
                grant <= 0;
                // Round-robin: start searching from last+1
                begin : arb
                    integer i, j;
                    for (i = 1; i <= N; i = i+1) begin
                        j = (last + i) % N;
                        if (req[j] && !(|grant)) begin
                            grant <= (1 << j);
                            last  <= j;
                        end
                    end
                end
            end
        end
    end
endmodule
