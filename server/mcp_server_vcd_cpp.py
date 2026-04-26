import os
import sys
from typing import Dict
from mcp.server.fastmcp import FastMCP

# Ensure Python can find your compiled C++ .so file
# If your .so file is in a 'build' folder, uncomment the next line:
# sys.path.append('./build') 

try:
    import vcd_cpp 
except ImportError:
    print("Error: vcd_cpp module not found. Ensure the .so filename matches the name in PYBIND11_MODULE.")
    sys.exit(1)

mcp = FastMCP("VCD_Parsing")

# Cache to store { "path/to/file.vcd": VCDParser_Object }
vcd_cache: Dict[str, vcd_cpp.VCDParser] = {}

def get_vcd_instance(path: str) -> vcd_cpp.VCDParser:
    """Helper to load the VCD into C++ memory only if it hasn't been loaded yet."""
    if not os.path.exists(path):
        raise FileNotFoundError(f"VCD file not found at: {path}")
    
    if path not in vcd_cache:
        print(f"First time seeing {path}. Loading into C++ memory...")
        # This calls the C++ constructor we defined earlier
        vcd_cache[path] = vcd_cpp.VCDParser(path)
    
    return vcd_cache[path]

@mcp.tool()
def vcd_get_simulation_time(path: str) -> str:
    """
    Returns total simulation time for a specific VCD file.
    The agent must provide the full path to the .vcd file.
    """
    try:
        vcd = get_vcd_instance(path)
        return f"File: {path} | Simulation time: {vcd.max_time} {vcd.timescale_unit}"
    except Exception as e:
        return f"Error: {str(e)}"

@mcp.tool()
def vcd_get_signal_value_at_timestamp(path: str, signal_name: str, timestamp: int) -> str:
    """
    Finds a signal value at a specific time. 
    Fast C++ binary search is used after the first load.
    """
    try:
        vcd = get_vcd_instance(path)
        val = vcd.get_value_at(signal_name, timestamp)
        return f"In {path}, signal {signal_name} at {timestamp} is {val}"
    except Exception as e:
        return f"Error: {str(e)}"

@mcp.tool()
def list_vcd_signals(path: str, pattern: str = "") -> str:
    """Lists signals from the specified VCD file."""
    try:
        vcd = get_vcd_instance(path)
        matched = [s for s in vcd.signals.keys() if pattern in s]
        return f"Signals in {path}:\n" + "\n".join(matched[:20])
    except Exception as e:
        return f"Error: {str(e)}"

if __name__ == "__main__":
    mcp.run()
