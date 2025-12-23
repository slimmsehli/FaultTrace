import bisect

from mcp.server.fastmcp import FastMCP
from typing import Any, Dict, List, Optional, Tuple, Union, Iterable
from vcdvcd import VCDVCD
from decimal import Decimal
import re
import os

######################################################
# This is a MCP server code for the toolsbox needed for parsing the vcd file and log file
# and extracting the needed information

mcp = FastMCP("RTL_Toolbox")


### load only one time the vcd object to be resuded later
vcdobj : Optional[VCDVCD] = None
@mcp.tool()
def load_vcd(path: str, store_scopes: bool = False) -> str:
	if not os.path.exists(path):
		return f"Error: Log file '{path}' not found."
	else:
		vcdobj = VCDVCD(path, store_tvs=True, store_scopes=store_scopes)
		return f"Info : VCD file loaded correctly"
 
@mcp.tool()
def get_vcd():
	if vcdobj is None:
		raise RuntimeError("VCD not loaded yet. Call load_vcd_once(path) first.")
		return vcdobj
############################################## VCD parsing

######################################################################
###### time parsing helpers ----
######################################################################

_UNIT_TO_SEC = {
    "s": 1.0, "ms": 1e-3, "us": 1e-6, "ns": 1e-9, "ps": 1e-12, "fs": 1e-15,
}

def _to_seconds(t: Union[str, float, int]) -> float:
    if isinstance(t, (int, float)): return float(t)
    s = str(t).strip()
    m = re.match(r"^\s*([0-9]+(\.[0-9]+)?)\s*([a-zA-Z]+)\s*$", s)
    if m:
        val = float(m.group(1))
        unit = m.group(3).lower()
        if unit not in _UNIT_TO_SEC:
            raise ValueError(f"Unknown time unit '{unit}' in '{t}'")
        return val * _UNIT_TO_SEC[unit]
    return float(s)  # assume seconds

def _in_window(tv: List[Tuple[int, str]], start_s: Optional[float], end_s: Optional[float]) -> List[Tuple[float, str]]:
    """Filter tv changes between start and end (given in seconds). `vcdvcd` stores times in raw units;
       we don't know the timescale multiplier here, so treat times as seconds already.
       If your simulator uses integer timesteps as raw units (e.g. ns), pass values consistently.
    """
    # vcdvcd gives times as int (raw) — we will treat them as seconds unless you rescale externally.
    s = -float("inf") if start_s is None else start_s
    e = float("inf") if end_s is None else end_s
    return [(float(t), v) for (t, v) in tv if s <= float(t) <= e]

def _bit(value: str, size_hint: Optional[int], bit_index: Optional[int]) -> Optional[int]:
    """Return scalar bit 0/1 from a scalar ('0','1','x','z') or binary string for vectors."""
    v = value.lower()
    if v in ("0", "1"): return int(v)
    if v in ("x", "z"): return None
    # vector like '1010'
    if bit_index is None: return None
    if not all(ch in "01xz" for ch in v): return None
    # LSB is rightmost
    if bit_index < 0 or bit_index >= len(v): return None
    ch = v[-1 - bit_index]
    if ch in ("0", "1"): return int(ch)
    return None

##########################################
###### Get the timescale from a vcd file
##########################################

@mcp.tool()
def vcd_get_timescale_scal(store_scopes: bool = False) -> List[Tuple[Any, Any]]:
    """ Get the magnitude and the unit of the timescale of a vcd file and output as two string format """
    ts = vcdobj.timescale  # {'magnitude': 1, 'unit': 'ns'}
    return ts['magnitude'], ts['unit']

@mcp.tool()
def vcd_get_timescale_str(store_scopes: bool = False) -> str:
    """ Get the magnitude and the unit of the timescale of a vcd file and output as two string format """
    ts = vcdobj.timescale  # {'magnitude': 1, 'unit': 'ns'}
    return f"{ts['magnitude']} {ts['unit']}"

######################################################################
###### get simulation time
######################################################################
@mcp.tool()
def vcd_get_simulation_time(store_scopes: bool = False) -> float:
    """
    Return total simulation time in seconds (float).
    Accepts a VCD file path.
    """
    vcd = get_vcd()
    ts = vcd.timescale
    magnitude = ts['magnitude']
    unit = ts['unit']
    #magnitude, unit = vcd_get_timescale(path)
    # Parse or reuse object // old function used to read the vcd file
    # vcd = VCDVCD(vcd_input, store_tvs=True) if isinstance(vcd_input, str) else vcd_input

    # Timescale -> seconds per unit as Decimal
    ts = vcd.timescale
    magnitude = Decimal(ts["magnitude"])
    unit = ts["unit"].lower()
    unit_to_sec = {
        "s":  Decimal("1"),
        "ms": Decimal("1e-3"),
        "us": Decimal("1e-6"),
        "ns": Decimal("1e-9"),
        "ps": Decimal("1e-12"),
        "fs": Decimal("1e-15"),
    }
    if unit not in unit_to_sec:
        raise ValueError(f"Unsupported VCD timescale unit: {unit}")
    seconds_per_unit = magnitude * unit_to_sec[unit]

    # Find the largest timestamp across all signals
    # vcd.signals is a list of full signal names; vcd[ref].tv -> [(time_raw, value), ...]
    max_time_raw = Decimal(0)
    for ref in getattr(vcd, "signals", []):
        sig = vcd[ref]
        tv = getattr(sig, "tv", [])
        if tv:
            # last change time (raw units, typically int)
            last_t = Decimal(tv[-1][0])
            if last_t > max_time_raw:
                max_time_raw = last_t

    # Convert to seconds & return as float
    sim_time_seconds = max_time_raw * seconds_per_unit
    return float(sim_time_seconds)


if __name__ == "__main__":
    mcp.run()
