######################################################
#
#
#
# This is a test for the mcp server functions based on singal function calls  
#
# ls, grep, find, cat, head, tail, ps, which, env, diff
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
		
		print(f"##################################################################################################")
		print(f"### TEST4 : cat ")
		result = mcp_server.cat({"path":"README.md", "args":""})
		print(result)
		
		print(f"##################################################################################################")
		print(f"### TEST5 : head ")
		result = mcp_server.head({"path":"README.md", "args":""})
		print(result)
		
		print(f"##################################################################################################")
		print(f"### TEST6 : tail ")
		result = mcp_server.tail({"path":"README.md", "args":""})
		print(result)
		
		print(f"##################################################################################################")
		print(f"### TEST7 : ps ")
		result = mcp_server.ps({"args":"aux"})
		print(result)
		
		print(f"##################################################################################################")
		print(f"### TEST8 : which ")
		result = mcp_server.which({"args":"vcs"})
		print(result)
		
		print(f"##################################################################################################")
		print(f"### TEST9 : env ")
		result = mcp_server.env({"args":""})
		print(result)
		
		print(f"##################################################################################################")
		print(f"### TEST10 : diff ")
		#result = mcp_server.diff({"path1":"mcp_server.py","path2":"mcp_server_str_wrapper_test.py","args":""})
		#print(result)
		#result = mcp_server.diff({"path1":"simulation","path2":"Specs","args":""}) # for dirrectories
		#print(result)
		

    
if __name__ == "__main__":
	main()
