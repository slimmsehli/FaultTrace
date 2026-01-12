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
		print(f"#  TESTING : unix functions")
		print(f"#  ")
		print(f"##################################################################################################\n")

		print(f"##################################################################################################")
		print(f"### TEST1 : ls")
		temp1 = mcp_server.ls({"path":""})
		temp = f" PATH 		: " + temp1["path"] + "\n"
		temp = temp + f" COMMAND 	: " + temp1["command"] + "\n"
		temp = temp + f" OUTPUT 	: \n" + temp1["output"] + "\n"
		print(temp)
		
		print(f"##################################################################################################")
		print(f"### TEST2 : grep ")
		temp1 = mcp_server.grep({"path":"", "opts":"-ri", "regr":"mcp_server*.py"})
		temp =        f" PATH 		: " + temp1["path"] + "\n"
		temp = temp + f" COMMAND 	: " + temp1["command"] + "\n"
		temp = temp + f" OUTPUT 	: \n" + temp1["output"] + "\n"
		print(temp)
		
		print(f"##################################################################################################")
		print(f"### TEST2 : find ")
		temp1 = mcp_server.find({"path":"", "args":'-name "mcp_server*.py" -type f'})
		temp =        f" PATH 		: " + temp1["path"] + "\n"
		temp = temp + f" COMMAND 	: " + temp1["command"] + "\n"
		temp = temp + f" OUTPUT 	: \n" + temp1["output"] + "\n"
		print(temp)
		

    
if __name__ == "__main__":
	main()
