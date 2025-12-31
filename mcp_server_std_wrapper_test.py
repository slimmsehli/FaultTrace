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
import mcp_server_std_wrapper as mcp_server

def main():
		logfile = "simulation/sim.log"
		sourcecode = "simulation/design.sv"
		vcd_path="simulation/sim.vcd"

		print(f"\n##################################################################################################")
		print(f"#  ")
		print(f"#  TESTING : log parser functions")
		print(f"#  ")
		print(f"##################################################################################################\n")


		## testing the function calls individually for log and source code parsing
		#def parse_log_for_errors(log_path: str) -> str:
		print(f"##################################################################################################")
		print(mcp_server.parse_log_for_errors(logfile))
		#print(f"\n\n[TEST] - Parsing Simulation log {logfile}, found errors : \n {errors}")

		#def find_first_uvm_error(log_path: str) -> str: 
		print(f"##################################################################################################")
		print(mcp_server.find_first_uvm_error(logfile))
		#print(f"\n\n[TEST] - Parsing Simulation log {logfile}, first error found : \n Error line :{error_line} \n Error content: {error_text}")

		#def get_error_context(log_path: str, error_line: int, window: int = 20) -> str:
		print(f"##################################################################################################")
		print(mcp_server.get_error_context(logfile, 7, 5))
		#print(f"\n\n[TEST] - Parsing Simulation log {logfile}, error context with previous 5 lines : \n {context}")

		#def search_log_keyword(log_path: str, keyword: str, context_lines: int = 10) -> str:
		print(f"##################################################################################################")
		print(mcp_server.search_log_keyword(sourcecode, "sda_out_en", 5))
		#print(f"\n\n[TEST] - Parsing source code {sourcecode}, searchin for keyword sda_out_en with previous 5 lines : \n {context}")

		#def get_source_snippet(file_path: str, line_number: int, context: int = 5) -> str:
		print(mcp_server.get_source_snippet(sourcecode, 83, 10))
		print(f"##################################################################################################")
		#print(f"\n\n[TEST] - Parsing source code {sourcecode}, searchin for keyword sda_out_en with previous 5 lines : \n {context}")


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
		print(mcp_server.vcd_get_signal_value_at_timestamp(vcd_path, "top.intf.sda_drive_out", 200))
		#print(f"\n[TEST] - Signal top.intf.sda_drive_out value at timestamp 200 {timescale_unit} is {timestamp_val} \n")
		print(mcp_server.vcd_get_signal_value_at_timestamp(vcd_path, "top.dut.shift_reg[7:0]", 200))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] value at timestamp 200 {timescale_unit} is {timestamp_val} \n")

		print(f"##################################################################################################")
		#vcd_get_signal_values_in_timeframe(path: str, signal_name: str, start: Optional[Union[str, float, int]], end: Optional[Union[str, float, int]], include_start_prev: bool = True) -> List[Tuple[float, Any]]:
		print(" TEST - vcd_get_signal_values_in_timeframe : ")
		print(mcp_server.vcd_get_signal_values_in_timeframe(vcd_path, "top.intf.sda_drive_out", 200, 800))
		#print(f"\n[TEST] - Signal top.intf.sda_drive_out value at timewindow 200-800{timescale_unit} is {timestamp_val} \n")
		print(" TEST - vcd_get_signal_values_in_timeframe : ")
		print(mcp_server.vcd_get_signal_values_in_timeframe(vcd_path, "top.dut.shift_reg[7:0]", 200, 800))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] value at timewindow 200-800{timescale_unit} is {timestamp_val} \n")

		print(f"##################################################################################################")
		#def vcd_count_signal_all_transitions(path: str, signal_name: str, edge: str, start: Optional[Union[str, float, int]], end: Optional[Union[str, float, int]], bit_index: Optional[int] = None) -> int:
		print(" TEST - vcd_count_signal_all_transitions : ")
		print(mcp_server.vcd_count_signal_all_transitions(vcd_path, "top.dut.shift_reg[7:0]", "rising", 200, 800, 3))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] bit 3 rising edges at timewindow 200-800{timescale_unit} are {edges} \n")

		print(f"##################################################################################################")
		#def vcd_next_change_after(path: str, signal_name: str, timestamp: Union[str, float, int]) -> Optional[Tuple[float, Any]]:
		print(" TEST - vcd_next_change_after : ")
		print(mcp_server.vcd_next_change_after(vcd_path, "top.dut.shift_reg[7:0]", 200))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] Next value change after 200{timescale_unit} is {val_change} \n")

		print(f"##################################################################################################")
		#def vcd_prev_change_before(path: str, signal_name: str, timestamp: Union[str, float, int]) -> Optional[Tuple[float, Any]]:
		print(" TEST - vcd_prev_change_before : ")
		print(mcp_server.vcd_prev_change_before(vcd_path, "top.dut.shift_reg[7:0]", 200))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] Previous value change before 200{timescale_unit} is {val_change} \n")

		print(f"##################################################################################################")
		#def vcd_search_value(path: str, signal_name: str, value: Any, start: Optional[Union[str, float, int]] = None, end: Optional[Union[str, float, int]] = None) -> List[float]:
		print(" TEST - vcd_search_value : ")
		print(mcp_server.vcd_search_value(vcd_path, "top.dut.shift_reg[7:0]", "01000001", 0, 4000))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] hit the value 01000001 at {val_change} \n")

		print(f"##################################################################################################")
		#def vcd_count_signal_all_transitions(path: str, signal_name: str, edge: str, start: Optional[Union[str, float, int]], end: Optional[Union[str, float, int]], bit_index: 
		print(" TEST - vcd_count_signal_all_transitions : ")
		print(mcp_server.vcd_count_signal_all_transitions(vcd_path, "top.dut.shift_reg[7:0]", "rising", 0, 40000, 2))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] bit 2 count for {val_count} rising edge in timewindow 0-40000{timescale_unit} \n")
		print(" TEST - vcd_count_signal_all_transitions : ")
		print(mcp_server.vcd_count_signal_all_transitions(vcd_path, "top.dut.shift_reg[7:0]", "rising", 0, 40000))
		#print(f"\n[TEST] - Signal top.dut.shift_reg[7:0] bit 2 count for {val_count} falling edge in timewindow 0-40000{timescale_unit} \n")

		print(f"##################################################################################################")
		#vcd_get_signals_values_at_timestamp(path: str,    signal_names: Iterable[str],timestamp: Union[str, float, int], method: str = "previous") -> Dict[str, Any]:
		print(" TEST - vcd_get_signals_values_at_timestamp : ")
		print(mcp_server.vcd_get_signals_values_at_timestamp(vcd_path, ["top.intf.scl", "top.intf.sda"], 40000))
		#print(f"\n[TEST] - Signals values at 40000{timescale_unit} is : {timestamp_vals} \n")

		print(f"##################################################################################################")
		print(" TEST - vcd_get_signals_aligned_in_window : ")
		print(mcp_server.vcd_get_signals_aligned_in_window(vcd_path, ["top.intf.scl", "top.intf.sda"], 100, 1000))
		#print("Times:", times)
		#for s, vals in aligned.items():
		#		print(s, vals)
    
if __name__ == "__main__":
	main()
