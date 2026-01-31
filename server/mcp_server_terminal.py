######################################################
#
#
#
# This is a mcp server with function calls (tools) linux termianl navigation
#
######################################################

import bisect

from mcp.server.fastmcp import FastMCP
from typing import Any, Dict, List, Optional, Tuple, Union, Iterable
from vcdvcd import VCDVCD
from decimal import Decimal
import re
import os
from mcp.server.fastmcp.exceptions import ToolError

# mcp_linux_tools.py
import os
import re
import fnmatch
import hashlib
import json
import time
from typing import List, Dict, Any, Optional

######################################################

mcp = FastMCP("RTL_Toolbox")

##########################################
###### 1. 
##########################################

import os
import subprocess
from typing import Dict, Any

WORKSPACE_ROOT = os.path.abspath(os.environ.get("PWD", "."))


def _normalize_and_guard(path: str) -> str:
    """Ensure path is within the allowed workspace."""
    #if not path:
    #    raise ToolError("Path is required.")
    p = os.path.abspath(os.path.join(WORKSPACE_ROOT, path))
    if not p.startswith(WORKSPACE_ROOT):
        raise ToolError(f"Path escapes workspace: {path}")
    return p


@mcp.tool()
def pwd() -> str:
    """
    This function Runs `pwd` in the terminal and returns terminal output.
    """
    return_dict = 0

    cmd = f"pwd"
    result = subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
    )

    if result.returncode != 0:
        raise ToolError(result.stderr.strip())

    output = result.stdout.rstrip("\n")

    res = {
        "command": cmd,
        "output": output
    }
    if return_dict == 1:
        return res
    else:
        temp = f" COMMAND 	: " + res["command"] + "\n"
        temp = temp + f" OUTPUT 	: \n" + res["output"] + "\n"
        return temp

@mcp.tool()
def ls(path: str = ".", args: str = "") -> str:
    """
    This function Runs `ls {args} {path}` in the terminal and returns terminal output.
    
    :param path: The directory path to list files for. Defaults to current directory.
    :param args: Additional ls command arguments (e.g., "-l or -lrt").
    """
    return_dict = 0
    path_in = path #_normalize_and_guard(input.get("path", "."))
    args_in = args
    if not os.path.exists(path_in):
        raise ToolError(f"Path does not exist: {path_in}")
	
    cmd = f"ls {args_in} {path_in}"
    result = subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
    )

    if result.returncode != 0:
        raise ToolError(result.stderr.strip())

    output = result.stdout.rstrip("\n")

    res = {
        "path": path,
        "command": cmd,
        "output": output
    }
    if return_dict==1:
      return res
    else:
      temp =        f" PATH 		: " + res["path"] + "\n"
      temp = temp + f" COMMAND 	: " + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"] + "\n"
      return temp

import shlex

@mcp.tool()
def grep(regr: str, path: str, opts: str = "-ri") -> str:
    """
    Runs `grep {opts} {regr} {path}` in the terminal and returns the output.

    :param regr: The regular expression or pattern to search for.
    :param path: The file or directory path to search within.
    :param opts: Grep options (e.g., '-i' for case-insensitive, '-l' for filenames only). Defaults to '-ri'.
    """
    return_dict = 0
    path_in = path #_normalize_and_guard(input.get("path", "."))
    opts_in = opts #input.get("opts", ".")
    regr_in = shlex.quote(regr) #input.get("regr", ".")
    
    if not os.path.exists(path_in):
        raise ToolError(f"Path does not exist: {path_in}")
    
    cmd = f"grep {opts_in} {regr_in} {path_in}"
    result = subprocess.run(
        cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
    )
    
    if result.returncode != 0:
       raise ToolError(result.stderr.strip())

    # IMPORTANT: preserve formatting exactly
    output = result.stdout.rstrip("\n")
    
    res = {
        "path": path_in,
        "command": cmd,
        "output": output        
    }
    if return_dict==1:
      return res
    else:
      temp =        f" PATH 		: " + res["path"] + "\n"
      temp = temp + f" COMMAND 	: " + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"] + "\n"
      return temp


# @TODO I need to change the argv passed tot he subprocess for the moment this is working!!!
@mcp.tool()
def find(path: str = ".", args: str = "") -> str:
    """
    Runs `find {path} {args}` in the terminal and returns output.

    :param path: The directory path to start the search.
    :param args: Additional find command arguments (e.g., '-name *.py').
    """
    return_dict = 0
    path_in = path #_normalize_and_guard(path)
    args_in = args
    #print (f"args are : ", args)
    #cmd = ["find", path, args]
    #cmd2 =  ["find", ".", "-name mcp_server*.py"]
    cmd = f"find {path_in} {args_in}"
    #print (f"cmd : {cmd3}")
    
    if not os.path.exists(path_in):
        raise ToolError(f"Path does not exist: {path_in}")
    
    result = subprocess.run(
        args=cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
        shell=True,
    )
    
    if result.returncode != 0:
       print("ERROR")
       #raise ToolError(result.stderr.strip())

    output = result.stdout.rstrip("\n")
    res = {
      "path": path_in,
      "command": cmd ,
      "output": output        
      }
    if return_dict==1:
      return res
    else:
      temp =        f" PATH 		: " + res["path"] + "\n"
      temp = temp + f" COMMAND 	: " + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"] + "\n"
      return temp

@mcp.tool()
def cat(path: str, args: str = "") -> str:
    """
    This function Runs `cat {args} {path}` in the terminal and returns terminal output.
    
    :param path: The path to the file you want to read.
    :param args: Additional cat flags (e.g., '-n' for line numbers).
    """
    return_dict = 0
    path_in = path #_normalize_and_guard(input.get("path", "."))
    args_in = args #input.get("args")
    cmd = f"cat {path_in} {args_in}"
    
    if not os.path.exists(path_in):
        raise ToolError(f"Path does not exist: {path_in}")
    
    cmd = f"cat {args_in} {path_in}"
    result = subprocess.run(
        args=cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
        shell=True,
    )
    
    if result.returncode != 0:
       print("ERROR")
       #raise ToolError(result.stderr.strip())

    output = result.stdout.rstrip("\n")
    res = {
      "path": path_in,
      "command": cmd ,
      "output": output        
      }
    if return_dict==1:
      return res
    else:
      temp =        f" PATH 		: " + res["path"] + "\n"
      temp = temp + f" COMMAND 	: " + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"] + "\n"
      return temp

@mcp.tool()
def head(path: str, args: str = "-n 20") -> str:
    """
    This function Runs `head {args} {path}` in the terminal and returns the first part of a file.
    
    :param path: The path to the file you want to inspect.
    :param args: Flags for head (e.g., '-n 50' for 50 lines). Defaults to '-n 20'.
    """
    return_dict = 0
    path_in = path #_normalize_and_guard(input.get("path", "."))
    args_in = args #input.get("args")
    
    if not os.path.exists(path_in):
        raise ToolError(f"Path does not exist: {path_in}")
    
    cmd = f"head {args_in} {path_in}"
    result = subprocess.run(
        args=cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
        shell=True,
    )
    
    if result.returncode != 0:
       print("ERROR")

    output = result.stdout.rstrip("\n")
    res = {
      "path": path_in,
      "command": cmd ,
      "output": output        
      }
    if return_dict==1:
      return res
    else:
      temp =        f" PATH 		: " + res["path"] + "\n"
      temp = temp + f" COMMAND 	: " + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"] + "\n"
      return temp

@mcp.tool()
def tail(path: str, args: str = "-n 20") -> str:
    """
    This function Runs `tail {args} {path}` in the terminal and returns the last part of a file.
    
    :param path: The path to the file you want to inspect.
    :param args: Flags for tail (e.g., '-n 50' for the last 50 lines). Defaults to '-n 20'.
    """
    return_dict = 0
    path_in = path #_normalize_and_guard(input.get("path", "."))
    args_in = args #input.get("args")
    
    
    if not os.path.exists(path_in):
        raise ToolError(f"Path does not exist: {path_in}")
    
    cmd = f"tail {args_in} {path_in}"
    result = subprocess.run(
        args=cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
        shell=True,
    )
    
    if result.returncode != 0:
       print("ERROR")

    output = result.stdout.rstrip("\n")
    res = {
      "path": path_in,
      "command": cmd ,
      "output": output        
      }
    if return_dict==1:
      return res
    else:
      temp =        f" PATH 		: " + res["path"] + "\n"
      temp = temp + f" COMMAND 	: " + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"] + "\n"
      return temp

@mcp.tool()
def ps(args: str = "ux") -> str:
    """
    This function runs `ps {args}` in the terminal and returns the process status output.
    
    :param args: Flags for the ps command (e.g., 'ux', '-ef', or '-aux'). Defaults to 'ux'.
    """
    return_dict = 0
    args_in = args #input.get("args")
    cmd = f"ps {args_in}"
    
    result = subprocess.run(
        args=cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
        shell=True,
    )
    
    if result.returncode != 0:
       print("ERROR")

    output = result.stdout.rstrip("\n")
    res = {
      "command": cmd ,
      "output": output        
      }
    if return_dict==1:
      return res
    else:
      temp =        f" COMMAND 	: "   + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"]  + "\n"
      return temp

@mcp.tool()
def which(args: str) -> str:
    """
    Runs `which {args}` to find the executable path of a command.
    
    :param command_name: The name of the executable to locate (e.g., 'python3', 'ls', 'vcs').
    """
    return_dict = 0
    args_in = args #input.get("args")
    cmd = f"which {args_in}"
    
    result = subprocess.run(
        args=cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
        shell=True,
    )
    
    if result.returncode != 0:
       print("ERROR")

    output = result.stdout.rstrip("\n")
    res = {
      "command": cmd ,
      "output": output        
      }
    if return_dict==1:
      return res
    else:
      temp =        f" COMMAND 	: "   + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"]  + "\n"
      return temp

@mcp.tool()
def env(args: str = "") -> str:
    """
    This function runs `env {args}` in the terminal and returns the environment variables.
    
    :param args: Optional flags for the env command, or use 'grep' with it to filter.
    """
    return_dict = 0
    args_in = args #input.get("args")
    cmd = f"env {args}"
    
    result = subprocess.run(
        args=cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
        shell=True,
    )
    
    if result.returncode != 0:
       print("ERROR")

    output = result.stdout.rstrip("\n")
    res = {
      "command": cmd ,
      "output": output        
      }
    if return_dict==1:
      return res
    else:
      temp =        f" COMMAND 	: "   + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"]  + "\n"
      return temp

@mcp.tool()
def diff(path1: str, path2: str, args: str = "-u") -> str:
    """
    Runs `diff {args} {path1} {path2}` in the terminal and returns the differences.
    
    :param path1: The first file or directory path to compare.
    :param path2: The second file or directory path to compare.
    :param args: Flags for diff (e.g., '-u' for unified format, '-y' for side-by-side). Defaults to '-u'.
    """
    return_dict = 0
    args_in = args #input.get("args")

    path1_in = path1 #_normalize_and_guard(input.get("path1", "."))
    if not os.path.exists(path1_in):
        raise ToolError(f"Path1 does not exist: {path1_in}")
    
    path2_in = path2 #_normalize_and_guard(input.get("path2", "."))
    if not os.path.exists(path2_in):
        raise ToolError(f"Path2 does not exist: {path2_in}")
    
    
    cmd = f"diff {args_in} {path1_in} {path2_in}"
    
    result = subprocess.run(
        args=cmd,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=5,
        shell=True,
    )
    
    #@TODO :  need to fix this since it raisie an error even with the correct results 
    #if result.returncode != 0:
    #   raise ToolError(f"ERROR from returned command resulrs")

    output = result.stdout.rstrip("\n")
    res = {
      "path1": path1_in ,
      "path2": path2_in ,
      "command": cmd ,
      "output": output        
      }
    if return_dict==1:
      return res
    else:
      temp =        f" PATH1 	: "   + res["path1"] + "\n"
      temp = temp + f" PATH2 	: "   + res["path2"] + "\n"
      temp = temp + f" COMMAND 	: "   + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"]  + "\n"
      return temp


if __name__ == "__main__":
    mcp.run()
    
