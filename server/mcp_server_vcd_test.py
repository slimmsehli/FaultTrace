######################################################
#
#
#
# This is a test for the mcp server functions based on singal function calls  
#
#
#
######################################################

from typing import Union, Optional, Dict
from vcdvcd import VCDVCD
import mcp_server_vcd as mcp_server

def main():
		logfile = "../simulation/cache/simresult/sim.log"
		vcd_path="../simulation/cache/simresult/sim.vcd"
		sourcecode="../simulation/cache/rtl/mesi_cache.v"

		print(f"\n##################################################################################################")
		print(f"#  ")
		print(f"#  TESTING : vcd parser functions")
		print(f"#  ")
		print(f"##################################################################################################\n")

		print(f"##################################################################################################")
		print(" TEST - vcd_get_simulation_time : ")
		print(mcp_server.vcd_get_simulation_time(vcd_path))
		#print(f"\n[TEST] - Simulation time is {simtime} \n")

		print(f"##################################################################################################")
		print(" TEST - vcd_get_timescale_scal : ")
		print(mcp_server.vcd_get_timescale_scal(vcd_path))
		#print(f"\n[TEST] - Simulation timescale is {timescale_unit}{timescale_mag} \n")

		print(f"##################################################################################################")
		print(" TEST - list_vcd_signals : ")
		print(mcp_server.list_vcd_signals(vcd_path, ""))
		#print(f"\n[TEST] - Simulation Signal list is \n :{signalslist} \n")

		print(f"##################################################################################################")
		# vcd_get_signal_value_at_timestamp(path: str, signal_name: str, timestamp: Union[str, float, int], method: str = "previous") -> Any:
		print(" TEST - vcd_get_signal_value_at_timestamp : ")
		print(mcp_server.vcd_get_signal_value_at_timestamp(vcd_path, "tb_top.dut.u_cache0.bus_grant", 200))
		#print(f"\n[TEST] - Signal top.intf.sda_drive_out value at timestamp 200 {timescale_unit} is {timestamp_val} \n")
		print(mcp_server.vcd_get_signal_value_at_timestamp(vcd_path, "tb_top.dut.u_cache0.bus_out_addr[7:0]", 200))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] value at timestamp 200 {timescale_unit} is {timestamp_val} \n")

		print(f"##################################################################################################")
		#vcd_get_signal_values_in_timeframe(path: str, signal_name: str, start: Optional[Union[str, float, int]], end: Optional[Union[str, float, int]], include_start_prev: bool = True) -> List[Tuple[float, Any]]:
		print(" TEST - vcd_get_signal_values_in_timeframe : ")
		print(mcp_server.vcd_get_signal_values_in_timeframe(vcd_path, "tb_top.dut.u_cache0.bus_grant", 200, 800))
		#print(f"\n[TEST] - Signal top.intf.sda_drive_out value at timewindow 200-800{timescale_unit} is {timestamp_val} \n")
		print(" TEST - vcd_get_signal_values_in_timeframe : ")
		print(mcp_server.vcd_get_signal_values_in_timeframe(vcd_path, "tb_top.dut.u_cache0.bus_out_addr[7:0]", 200, 800))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] value at timewindow 200-800{timescale_unit} is {timestamp_val} \n")

		print(f"##################################################################################################")
		#def vcd_count_signal_all_transitions(path: str, signal_name: str, edge: str, start: Optional[Union[str, float, int]], end: Optional[Union[str, float, int]], bit_index: Optional[int] = None) -> int:
		print(" TEST - vcd_count_signal_all_transitions : ")
		print(mcp_server.vcd_count_signal_all_transitions(vcd_path, "tb_top.dut.u_cache0.bus_out_addr[7:0]", "rising", 200, 800, 3))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] bit 3 rising edges at timewindow 200-800{timescale_unit} are {edges} \n")

		print(f"##################################################################################################")
		#def vcd_next_change_after(path: str, signal_name: str, timestamp: Union[str, float, int]) -> Optional[Tuple[float, Any]]:
		print(" TEST - vcd_next_change_after : ")
		print(mcp_server.vcd_next_change_after(vcd_path, "tb_top.dut.u_cache0.bus_out_addr[7:0]", 200))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] Next value change after 200{timescale_unit} is {val_change} \n")

		print(f"##################################################################################################")
		#def vcd_prev_change_before(path: str, signal_name: str, timestamp: Union[str, float, int]) -> Optional[Tuple[float, Any]]:
		print(" TEST - vcd_prev_change_before : ")
		print(mcp_server.vcd_prev_change_before(vcd_path, "tb_top.dut.u_cache0.bus_out_addr[7:0]", 200))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] Previous value change before 200{timescale_unit} is {val_change} \n")

		print(f"##################################################################################################")
		#def vcd_search_value(path: str, signal_name: str, value: Any, start: Optional[Union[str, float, int]] = None, end: Optional[Union[str, float, int]] = None) -> List[float]:
		print(" TEST - vcd_search_value : ")
		print(mcp_server.vcd_search_value(vcd_path, "tb_top.dut.u_cache0.bus_out_addr[7:0]", "01000001", 0, 4000))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] hit the value 01000001 at {val_change} \n")

		print(f"##################################################################################################")
		#def vcd_count_signal_all_transitions(path: str, signal_name: str, edge: str, start: Optional[Union[str, float, int]], end: Optional[Union[str, float, int]], bit_index: 
		print(" TEST - vcd_count_signal_all_transitions : ")
		print(mcp_server.vcd_count_signal_all_transitions(vcd_path, "tb_top.dut.u_cache0.bus_out_addr[7:0]", "rising", 0, 40000, 2))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] bit 2 count for {val_count} rising edge in timewindow 0-40000{timescale_unit} \n")
		print(" TEST - vcd_count_signal_all_transitions : ")
		print(mcp_server.vcd_count_signal_all_transitions(vcd_path, "tb_top.dut.u_cache0.bus_out_addr[7:0]", "rising", 0, 40000))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] bit 2 count for {val_count} falling edge in timewindow 0-40000{timescale_unit} \n")

		print(f"##################################################################################################")
		#vcd_get_signals_values_at_timestamp(path: str,    signal_names: Iterable[str],timestamp: Union[str, float, int], method: str = "previous") -> Dict[str, Any]:
		print(" TEST - vcd_get_signals_values_at_timestamp : ")
		print(mcp_server.vcd_get_signals_values_at_timestamp(vcd_path, ["tb_top.dut.u_cache0.bus_grant", "tb_top.dut.u_cache0.bus_drive"], 40000))
		#print(f"\n[TEST] - Signals values at 40000{timescale_unit} is : {timestamp_vals} \n")

		print(f"##################################################################################################")
		print(" TEST - vcd_get_signals_aligned_in_window : ")
		print(mcp_server.vcd_get_signals_aligned_in_window(vcd_path, ["tb_top.dut.u_cache0.bus_grant", "tb_top.dut.u_cache0.bus_drive"], 100, 1000))
		#print("Times:", times)
		#for s, vals in aligned.items():
		#		print(s, vals)
    
if __name__ == "__main__":
	main()
