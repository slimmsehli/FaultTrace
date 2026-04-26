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
import mcp_server_codeparser as mcp_server

def main():
		logfile = "../simulation/cache/simresult/sim.log"
		vcd_path="../simulation/cache/simresult/sim.vcd"
		sourcecode="../simulation/cache/rtl/mesi_cache.v"

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
		print(mcp_server.get_source_snippet(sourcecode, 237, 10))
		print(f"##################################################################################################")
		#print(f"\n\n[TEST] - Parsing source code {sourcecode}, searchin for keyword sda_out_en with previous 5 lines : \n {context}")
    
if __name__ == "__main__":
	main()
