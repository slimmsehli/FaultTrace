from mcp.server.fastmcp import FastMCP
import vcd_parser_module as vcd_lib # Your existing code

# Initialize MCP Server
mcp = FastMCP("VeriSight-AI")

# --- TOOL: Log Parsing ---
@mcp.tool()
def analyze_log_for_errors(log_path: str):
    """Scans log file for UVM_ERROR or Fails and returns (time, file, line, msg)."""
    # Call your log parser here
    return {"status": "error", "time": "550ns", "file": "fifo_ctrl.sv", "line": 84}

# --- TOOL: VCD Signal Query ---
@mcp.tool()
def get_waveform_context(vcd_path: str, signals: list, time_ns: float):
    """Returns a snapshot of signal values at a specific timestamp."""
    # Call your vcd_lib.get_signal_snapshot here
    return {"clk": 1, "rst_n": 1, "data_valid": 1, "fifo_full": 1}

# --- TOOL: Source Code Lookup ---
@mcp.tool()
def read_source_code(file_path: str, line_number: int, context_lines: int = 10):
    """Reads RTL source code around a specific line to understand logic."""
    # Call your source parser here
    return "always @(posedge clk) if (data_valid && fifo_full) error_flag <= 1;"

if __name__ == "__main__":
    mcp.run()