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
import mcp_server_terminal as mcp_server
import os
cpath = os.path.abspath(os.environ.get("PWD", "."))  # set explicitly
print(f"Current path is : ", cpath)

def main():
		logfile = "simulation/sim.log"
		sourcecode = "simulation/design.sv"
		vcd_path="simulation/sim.vcd"

		print(f"\n##################################################################################################")
		print(f"#  ")
		print(f"#  TESTING : unix terminal functions")
		print(f"#  ")
		print(f"##################################################################################################\n")

		print(f"##################################################################################################")
		print(f"### TEST1 : ls")
		result = mcp_server.ls({"path":""})
		print(result)
		
		print(f"##################################################################################################")
		print(f"### TEST2 : grep ")
		result = mcp_server.grep({"path":"", "opts":"-ri", "regr":"mcp_server*.py"})
		print(result)
		
		print(f"##################################################################################################")
		print(f"### TEST3 : find ")
		result = mcp_server.find({"path":"", "args":'-name "mcp_server*.py" -type f'})
		print(result)
		

    
if __name__ == "__main__":
	main()
