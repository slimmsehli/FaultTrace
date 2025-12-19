import bisect
import os
import re
from typing import Any, Dict, List, Optional, Tuple, Union
from typing import Union, Optional, Dict
from vcdvcd import VCDVCD
from decimal import Decimal

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

######################################################################
###### get singal value at a specific timestamp
######################################################################

def get_signal_value_at_timestamp(vcd: VCDVCD, signal_name: str, timestamp: Union[str, float, int], method: str = "previous") -> Any:
    tv = vcd[signal_name].tv  # list of (time, value) tuples. [2](https://github.com/cirosantilli/vcdvcd)
    if not tv: return None
    t_sec = _to_seconds(timestamp)
    times = [float(t) for (t, _) in tv]
    idx = bisect.bisect_right(times, t_sec) - 1
    if method == "exact":
        i = bisect.bisect_left(times, t_sec)
        if 0 <= i < len(times) and times[i] == t_sec:
            return tv[i][1]
        return None
    if idx < 0:
        return None
    return tv[idx][1]

######################################################################
###### get singal value at a specific time frame
######################################################################

def get_signal_values_in_timeframe(vcd: VCDVCD, signal_name: str, start: Optional[Union[str, float, int]], end: Optional[Union[str, float, int]], include_start_prev: bool = True) -> List[Tuple[float, Any]]:
    tv = vcd[signal_name].tv
    s = None if start is None else _to_seconds(start)
    e = None if end is None else _to_seconds(end)
    window = _in_window(tv, s, e)
    out = []
    if include_start_prev and start is not None:
        prev = get_signal_value_at_timestamp(vcd, signal_name, s, method="previous")
        if prev is not None:
            out.append((s, prev))
    out.extend(window)
    return out

######################################################################
###### Count a singal transitions in a time frame
######################################################################
# count_signal_all_transitions (vcd: VCDVCD, signal_name: str, edge: str, start:etr, end:str, bit_index:int)
def count_signal_all_transitions(vcd: VCDVCD, signal_name: str, edge: str, start: Optional[Union[str, float, int]], end: Optional[Union[str, float, int]], bit_index: Optional[int] = None) -> int:
    tv = vcd[signal_name].tv
    s = None if start is None else _to_seconds(start)
    e = None if end is None else _to_seconds(end)
    window = _in_window(tv, s, e)
    if not window: return 0
    last = _bit(window[0][1], None, bit_index)
    cnt = 0
    for _, v in window[1:]:
        cur = _bit(v, None, bit_index)
        if last is None or cur is None:
            last = cur
            continue
        if edge == "rising" and last == 0 and cur == 1:
            cnt += 1
        elif edge == "falling" and last == 1 and cur == 0:
            cnt += 1
        last = cur
    return cnt

######################################################################
###### Get Frquency of a signal
######################################################################

### @TODO need to fix the calaculation loop

def get_clock_frequency(vcd: VCDVCD, signal_name: str, start: Optional[Union[str, float, int]] = None, end: Optional[Union[str, float, int]] = None, bit_index: Optional[int] = None) -> Optional[float]:
    changes = get_signal_values_in_timeframe(vcd, signal_name, start, end, include_start_prev=True)
    rising_times: List[float] = []
    prev_b = _bit(changes[0][1], None, bit_index)
    for t, v in changes[1:]:
        b = _bit(v, None, bit_index)
        if prev_b is not None and b is not None and prev_b == 0 and b == 1:
            rising_times.append(t)
        prev_b = b
    if len(rising_times) < 2: return None
    periods = [rising_times[i] - rising_times[i-1] for i in range(1, len(rising_times))]
    avg = sum(periods) / len(periods)
    return None if avg <= 0 else 1.0 / avg

######################################################################
###### Get the first edge after a timestamp
######################################################################
### @TODO need add the first value and the value after the transition in the output results
def next_change_after(vcd: VCDVCD, signal_name: str, timestamp: Union[str, float, int]) -> Optional[Tuple[float, Any]]:
    tv = vcd[signal_name].tv
    if not tv: return None
    t_sec = _to_seconds(timestamp)
    times = [float(t) for (t, _) in tv]
    idx = bisect.bisect_right(times, t_sec)
    if idx < len(tv):
        t, v = tv[idx]
        return (float(t), v)
    return None

######################################################################
###### Get the first edge after a timestamp
######################################################################
### @TODO need add the first value and the value after the transition in the output results
def prev_change_before(vcd: VCDVCD, signal_name: str, timestamp: Union[str, float, int]) -> Optional[Tuple[float, Any]]:
    tv = vcd[signal_name].tv
    if not tv: return None
    t_sec = _to_seconds(timestamp)
    times = [float(t) for (t, _) in tv]
    idx = bisect.bisect_left(times, t_sec) - 1
    if idx >= 0:
        t, v = tv[idx]
        return (float(t), v)
    return None

######################################################################
###### Search for a vlaue of a singal 
######################################################################
### @TODO  need to add the entire timeframe where the signal has the extracted value not only the transition
def search_value(vcd: VCDVCD, signal_name: str, value: Any, start: Optional[Union[str, float, int]] = None, end: Optional[Union[str, float, int]] = None) -> List[float]:
    changes = get_signal_values_in_timeframe(vcd, signal_name, start, end, include_start_prev=False)
    target = value.lower() if isinstance(value, str) else value
    return [t for (t, v) in changes if (v.lower() if isinstance(v, str) else v) == target]








