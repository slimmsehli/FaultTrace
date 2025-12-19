
from typing import Union, Optional, Dict
from vcdvcd import VCDVCD
import vcd_getinfo as vcdinfo
import vcd_getsignal as vcdsignal

def main():
    tmp = "simulation/simdir/sim.vcd"
    simscale_mag, simscale_unit = vcdinfo.get_timescale(tmp)
    print(f" [TEST] - Simulation timescale unit : {simscale_mag}{simscale_unit}")
    simtime = vcdinfo.get_simulation_time(tmp)
    print(f" [TEST] - Simulation time duration : {simtime}s")
    print()
    
    ## paring vcd file 
    vcd = vcdinfo.parse_vcd(tmp, store_scopes=True)
    print(" [TEST] - Parsing vcd file :", tmp)
    signals = vcdinfo.list_signals(vcd)
    print(" [TEST] - Signals list:")
    print(signals)
    print()
    
    ## get hiearchy
    hier = vcdinfo.load_hierarchy(vcd)
    print(" [TEST] - Design Hierarchy from vcd  :")
    vcdinfo.print_hierarchy(hier)
    print()
    
    ## get singal values at different parts of simulation
    ## get_signal_value_at_timestamp
    value = vcdsignal.get_signal_value_at_timestamp(vcd, signals[0], 2000)
    print(f" [TEST] - singal value of {signals[0]} at timestamp 2us is : {value}")
    value = vcdsignal.get_signal_value_at_timestamp(vcd, signals[0], 6000)
    print(f" [TEST] - singal value of {signals[0]} at timestamp 6us is : {value}")
    value = vcdsignal.get_signal_value_at_timestamp(vcd, signals[0], 18000)
    print(f" [TEST] - singal value of {signals[0]} at timestamp 18us is : {value}")
    print()

    ## get_signal_values_in_timeframe
    value = vcdsignal.get_signal_values_in_timeframe(vcd, signals[0], 2000, 9000) #, include_start_prev=False)
    print(f" [TEST] - singal value of {signals[0]} between 2us and 9us is : {value}")
    print()
    
    ## count the number of transition (vcd: VCDVCD, signal_name: str, edge: str, start:etr, end:str, bit_index:int)
    value = vcdsignal.count_signal_all_transitions(vcd, signals[0], "rising", 0, 29000, 2) #, include_start_prev=False)
    print(f" [TEST] - Number of rising edge of bit 2 of signal {signals[0]} between 2us and 9us is : {value}")
    value = vcdsignal.count_signal_all_transitions(vcd, signals[0], "falling", 0, 29000, 2) #, include_start_prev=False)
    print(f" [TEST] - Number of falling edge of bit 2 of signal {signals[0]} between 2us and 9us is : {value}")
    print()
    
    ## get frequency of a signal
    value = vcdsignal.get_clock_frequency(vcd, signals[1], 0, 29000)
    print(f" [TEST] - frequency of signal {signals[1]} between 0 and 29us is {value}")
    print()
    
    ## get the first edge after a timestamp
    value = vcdsignal.next_change_after(vcd, signals[0], 14000)
    print(f" [TEST] - first change of signal {signals[1]} after 14us is at {value[0]}{simscale_unit} to x'b{value[1]}")
    value = vcdsignal.prev_change_before(vcd, signals[0], 14000)
    print(f" [TEST] - first change of signal {signals[1]} before 14us is at {value[0]}{simscale_unit} to x'b{value[1]}")
    print()
    
    ## checkj a vlaue on a signal
    value = vcdsignal.search_value(vcd, signals[0], "1001", 0, 29000)
    print(f" [TEST] - first change of signal {value}")
    value = vcdsignal.get_signal_values_in_timeframe(vcd, signals[0], 0, 29000) 
    print(f" [TEST] - singal value of {signals[0]} between 2us and 9us is : {value}")
    
    
if __name__ == "__main__":
	main()
