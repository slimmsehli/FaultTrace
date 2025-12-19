
"""
VCD analysis utilities built on the `vcdvcd` library.

APIs:
OK- get_simulation_time(vcd: VCDVCD) -> float:
- get_signal_value_at_timestamp(vcd, signal_name, timestamp, method='previous')
- get_signal_values_in_timeframe(vcd, signal_name, start, end, include_start_prev=True)
- count_signal_all_transitions(vcd, signal_name, edge, start, end, bit_index=None)
- get_glitches(vcd, signal_name, min_pulse_width, start=None, end=None, bit_index=None)
- measure_high_low_time(vcd, signal_name, start=None, end=None, bit_index=None)
- get_clock_frequency(vcd, signal_name, start=None, end=None, bit_index=None)
- next_change_after(vcd, signal_name, timestamp)
- prev_change_before(vcd, signal_name, timestamp)
- search_value(vcd, signal_name, value, start=None, end=None)
- export_csv(vcd, signal_name, start=None, end=None, path='signal.csv')

Local test: `_run_local_test()` creates a tiny VCD, parses it, and exercises APIs.
"""

from __future__ import annotations
import bisect
import os
import re
from typing import Any, Dict, List, Optional, Tuple, Union

# ---- time parsing helpers ----

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

# ---- main API using vcdvcd ----
from vcdvcd import VCDVCD  # [2](https://github.com/cirosantilli/vcdvcd)

def parse_vcd(path: str, only_sigs: Optional[List[str]] = None, store_scopes: bool = False) -> VCDVCD:
    """
    Parse VCD using vcdvcd. If only_sigs is provided, vcdvcd will still parse the file,
    but you can later access only signals you care about.
    """
    # vcdvcd supports storing scopes and exposes signal tv pairs. [2](https://github.com/cirosantilli/vcdvcd)
    return VCDVCD(path, store_tvs=True, store_scopes=store_scopes)


"""
def get_simulation_time(vcd: VCDVCD) -> float:
    #vcd = VCDVCD(vcd_path, store_tvs=True)
    # Collect all timestamps from all signals
    max_time = max(
        (sig.tv[-1][0] for sig in vcd.signals.values() if sig.tv),
        default=0
    )
    return max_time  # raw units (usually ns if timescale is 1 ns)



def list_signals(vcd: VCDVCD, pattern: Optional[str] = None) -> List[str]:
    sigs = list(vcd.signals)  # full references
    if not pattern: return sorted(sigs)
    rx = re.compile(pattern)
    return sorted([s for s in sigs if rx.search(s)])
"""
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

def get_glitches(vcd: VCDVCD, signal_name: str, min_pulse_width: Union[str, float, int], start: Optional[Union[str, float, int]] = None, end: Optional[Union[str, float, int]] = None, bit_index: Optional[int] = None) -> List[Tuple[float, float, int]]:
    pw = _to_seconds(min_pulse_width)
    changes = get_signal_values_in_timeframe(vcd, signal_name, start, end, include_start_prev=True)
    out = []
    if not changes: return out
    prev_t, prev_v = changes[0]
    prev_b = _bit(prev_v, None, bit_index)
    for t, v in changes[1:]:
        b = _bit(v, None, bit_index)
        if b is None or prev_b is None:
            prev_t, prev_v, prev_b = t, v, b
            continue
        if b != prev_b:
            width = t - prev_t
            if width < pw:
                out.append((prev_t, t, prev_b))
            prev_t, prev_v, prev_b = t, v, b
    return out

def measure_high_low_time(vcd: VCDVCD, signal_name: str, start: Optional[Union[str, float, int]] = None, end: Optional[Union[str, float, int]] = None, bit_index: Optional[int] = None) -> Dict[str, float]:
    changes = get_signal_values_in_timeframe(vcd, signal_name, start, end, include_start_prev=True)
    totals = {"high": 0.0, "low": 0.0, "unknown": 0.0}
    if not changes: return totals
    prev_t, prev_v = changes[0]
    prev_b = _bit(prev_v, None, bit_index)
    for i in range(1, len(changes)):
        t, v = changes[i]
        dur = t - prev_t
        if prev_b is None: totals["unknown"] += dur
        elif prev_b == 1: totals["high"] += dur
        else: totals["low"] += dur
        prev_t, prev_b = t, _bit(v, None, bit_index)
    tail_end = _to_seconds(end) if end is not None else changes[-1][0]
    if tail_end > prev_t:
        dur = tail_end - prev_t
        if prev_b is None: totals["unknown"] += dur
        elif prev_b == 1: totals["high"] += dur
        else: totals["low"] += dur
    return totals

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

def search_value(vcd: VCDVCD, signal_name: str, value: Any, start: Optional[Union[str, float, int]] = None, end: Optional[Union[str, float, int]] = None) -> List[float]:
    changes = get_signal_values_in_timeframe(vcd, signal_name, start, end, include_start_prev=False)
    target = value.lower() if isinstance(value, str) else value
    return [t for (t, v) in changes if (v.lower() if isinstance(v, str) else v) == target]

def export_csv(vcd: VCDVCD, signal_name: str, start: Optional[Union[str, float, int]] = None, end: Optional[Union[str, float, int]] = None, path: str = "signal.csv") -> None:
    changes = get_signal_values_in_timeframe(vcd, signal_name, start, end, include_start_prev=True)
    with open(path, "w", encoding="utf-8") as fh:
        fh.write("time_seconds,value\n")
        for t, v in changes:
            fh.write(f"{t},{v}\n")

# ---- local self-test ----

_SAMPLE_VCD = """$date
  today
$end
$version
  vcd_lib_wrapper test
$end
$timescale 1 ns $end
$scope module top $end
$var wire 1 ! clk $end
$var wire 4 " data[3:0] $end
$upscope $end
$enddefinitions $end
$dumpvars
0!
b0000 "
$end
#5
1!
#10
0!
b0001 "
#15
1!
#20
0!
b0011 "
#25
1!
#30
0!
b0111 "
#35
1!
#40
0!
b1111 "
"""

def _write_sample_vcd(path: str) -> None:
    with open(path, "w", encoding="utf-8") as fh:
        fh.write(_SAMPLE_VCD)

def _run_local_test():
    tmp = "simulation/simdir/sim.vcd"
    #_write_sample_vcd(tmp)
    #print(f"[test] created {tmp}")
    vcd = parse_vcd(tmp, store_scopes=True)
    print(" [TEST] :  Parsing vcd file :", tmp)
    signals = list_signals(vcd)
    print(" [TEST] :  signals:", signals)
    
    ### show a signal 
    print(f" [TEST] :  signal 1 : ", signals[0])
    ### get simulation time 
    sim_time = get_simulation_time(vcd)
    print(f" [TEST] :  VCD simulation time is : ", sim_time)
    
    """
    print("[test] val data[3:0] @12ns:", get_signal_value_at_timestamp(vcd, "top.data[3:0]", "12ns"))
    print("[test] val clk @12ns:", get_signal_value_at_timestamp(vcd, "top.clk", "12ns"))

    ch = get_signal_values_in_timeframe(vcd, "top.data[3:0]", "0ns", "30ns")
    print("[test] data changes [0ns,30ns]:", ch)

    rc = count_signal_all_transitions(vcd, "top.clk", edge="rising", start="0ns", end="40ns")
    print("[test] clk rising count [0ns,40ns]:", rc)

    hl = measure_high_low_time(vcd, "top.clk", "0ns", "40ns")
    print("[test] clk high/low:", hl)

    freq = get_clock_frequency(vcd, "top.clk", "0ns", "40ns")
    print("[test] clk freq (Hz):", freq)

    glitches = get_glitches(vcd, "top.clk", "7ns", "0ns", "40ns")
    print("[test] clk glitches (<7ns):", glitches)

    export_csv(vcd, "top.data[3:0]", "0ns", "40ns", path="data_changes.csv")
    print("[test] wrote data_changes.csv")

    try:
        os.remove(tmp)
    except Exception:
        pass
    """

if __name__ == "__main__":
    _run_local_test()

