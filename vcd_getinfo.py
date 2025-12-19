
from typing import Union, Optional, Dict
from vcdvcd import VCDVCD
from decimal import Decimal
#from __future__ import annotations
import bisect
import os
import re
from typing import Any, Dict, List, Optional, Tuple, Union

######################################################################
###### get simulation time scale 
######################################################################

def get_timescale(vcd_input: Union[str, VCDVCD]) -> str:
    """
    Return timescale as a string, e.g. '1 ns'.
    Accepts either a VCD file path or a VCDVCD object.
    """
    vcd = VCDVCD(vcd_input) if isinstance(vcd_input, str) else vcd_input
    ts = vcd.timescale  # {'magnitude': 1, 'unit': 'ns'}
    return f"{ts['magnitude']}", f"{ts['unit']}"

######################################################################
###### get simulation time
######################################################################

def get_simulation_time(vcd_input: Union[str, VCDVCD]) -> float:
    """
    Return total simulation time in seconds (float).
    Accepts either a VCD file path or a VCDVCD object.
    """
    # Parse or reuse object
    vcd = VCDVCD(vcd_input, store_tvs=True) if isinstance(vcd_input, str) else vcd_input

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


######################################################################
###### get vcd file
######################################################################

def parse_vcd(path: str, only_sigs: Optional[List[str]] = None, store_scopes: bool = False) -> VCDVCD:
    """
    Parse VCD using vcdvcd. If only_sigs is provided, vcdvcd will still parse the file,
    but you can later access only signals you care about.
    """
    # vcdvcd supports storing scopes and exposes signal tv pairs. [2](https://github.com/cirosantilli/vcdvcd)
    return VCDVCD(path, store_tvs=True, store_scopes=store_scopes)

######################################################################
###### get all signals list
######################################################################

def list_signals(vcd: VCDVCD, pattern: Optional[str] = None) -> List[str]:
    sigs = list(vcd.signals)  # full references
    if not pattern: return sorted(sigs)
    rx = re.compile(pattern)
    return sorted([s for s in sigs if rx.search(s)])

######################################################################
###### get Hierarchy from vcd
######################################################################

from typing import Dict, Any
from vcdvcd import VCDVCD


from typing import Any, Dict, Union
from vcdvcd import VCDVCD

def load_hierarchy(vcd_input: Union[str, VCDVCD]) -> Dict[str, Any]:
    """
    Build a hierarchy tree from a VCD.
    Accepts either a VCD file path or an already-parsed VCDVCD object.

    Returns a nested dict structure like:
    {
      'top': {
        '_signals': ['top.clk', 'top.reset', ...],
        'subA': {
          '_signals': ['top.subA.sig1', ...],
          'subB': {
            '_signals': [...],
          }
        }
      }
    }
    """
    # Parse if we received a path, otherwise reuse the object
    vcd = VCDVCD(vcd_input, store_tvs=False, store_scopes=True) if isinstance(vcd_input, str) else vcd_input

    tree: Dict[str, Any] = {}

    def ensure_scope_path(scope_parts):
        """
        Ensure nested dicts exist for the given scope path and
        always keep a '_signals' list at each node.
        """
        node = tree
        for part in scope_parts:
            node = node.setdefault(part, {})
            node.setdefault("_signals", [])
        return node

    # vcdvcd provides full hierarchical names in vcd.signals (e.g., 'top.sub.sig')
    for full_name in getattr(vcd, "signals", []):
        parts = full_name.split(".")
        if len(parts) == 1:
            # signal directly under root
            root = ensure_scope_path([])
            root.setdefault("_signals", []).append(full_name)
        else:
            scope_node = ensure_scope_path(parts[:-1])
            scope_node["_signals"].append(full_name)

    return tree

import vcd_getinfo as vcdinfo
from typing import Any, Dict, Union
def print_hierarchy(tree: Dict[str, Any], indent: int = 0) -> None:
    for name, node in tree.items():
        if name == "_signals":
            continue
        print("  " * indent + name)
        for sig in node.get("_signals", []):
            print("  " * (indent + 1) + f"- {sig}")
        print_hierarchy(node, indent + 1)
