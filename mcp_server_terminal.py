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

class ToolError(Exception):
    pass

def _normalize_and_guard(path: str) -> str:
    """Ensure path is within the allowed workspace."""
    #if not path:
    #    raise ToolError("Path is required.")
    p = os.path.abspath(os.path.join(WORKSPACE_ROOT, path))
    if not p.startswith(WORKSPACE_ROOT):
        raise ToolError(f"Path escapes workspace: {path}")
    return p

def ls(input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `ls -lrth` on a path and return raw terminal output as a dict contains the path, the command and the output.
    """
    return_dict = 0
    path = _normalize_and_guard(input.get("path", "."))

    if not os.path.exists(path):
        raise ToolError(f"Path does not exist: {path}")

    result = subprocess.run(
        ["ls", "-lrth", path],
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
        "path": path,
        "command": "ls -lrth",
        "output": output
    }
    if return_dict==1:
      return res
    else:
      temp =        f" PATH 		: " + res["path"] + "\n"
      temp = temp + f" COMMAND 	: " + res["command"] + "\n"
      temp = temp + f" OUTPUT 	: \n" + res["output"] + "\n"
      return temp
    

def grep (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `grep {opts} {regr} {path}` on a path and return raw terminal output.
    """
    return_dict = 0
    path = _normalize_and_guard(input.get("path", "."))
    opts = input.get("opts", ".")
    regr = input.get("regr", ".")
    
    if not os.path.exists(path):
        raise ToolError(f"Path does not exist: {path}")
    
    result = subprocess.run(
        ["grep", opts, regr, path],
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
        "path": path,
        "command": f"grep {opts} {regr} {path}" ,
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
def find (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `find {path} {args} ` on a path and return raw terminal output.
    """
    return_dict = 0
    path = _normalize_and_guard(input.get("path", "."))
    args = input.get("args")
    #print (f"args are : ", args)
    #cmd = ["find", path, args]
    #cmd2 =  ["find", ".", "-name mcp_server*.py"]
    cmd = f"find {path} {args}"
    #print (f"cmd : {cmd3}")
    
    if not os.path.exists(path):
        raise ToolError(f"Path does not exist: {path}")
    
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
      "path": path,
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

def cat (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `cat {file path} {args} ` on a file path and return raw terminal output from that file.
    """
    return_dict = 0
    path = _normalize_and_guard(input.get("path", "."))
    args = input.get("args")
    cmd = f"cat {path} {args}"
    
    if not os.path.exists(path):
        raise ToolError(f"Path does not exist: {path}")
    
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
      "path": path,
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

def head (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `head {file path} {args}` on a file path and return raw terminal output from that file.
    """
    return_dict = 0
    path = _normalize_and_guard(input.get("path", "."))
    args = input.get("args")
    cmd = f"head {path} {args}"
    
    if not os.path.exists(path):
        raise ToolError(f"Path does not exist: {path}")
    
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
      "path": path,
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

def tail (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `tail {file path} {args}` on a file path and return raw terminal output from that file.
    """
    return_dict = 0
    path = _normalize_and_guard(input.get("path", "."))
    args = input.get("args")
    cmd = f"tail {path} {args}"
    
    if not os.path.exists(path):
        raise ToolError(f"Path does not exist: {path}")
    
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
      "path": path,
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

def ps (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `ps {args}` on a file path and return raw terminal output from that file.
    """
    return_dict = 0
    args = input.get("args")
    cmd = f"ps {args}"
    
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

def which (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `which {args}` on a file path and return raw terminal output from that file.
    """
    return_dict = 0
    args = input.get("args")
    cmd = f"which {args}"
    
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

def env (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `env {args}` on a file path and return raw terminal output from that file.
    """
    return_dict = 0
    args = input.get("args")
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

def diff (input: Dict[str, Any]) -> Dict[str, Any]:

    """
    Run `diff {args} {path1} {path2} ` on a file path and return raw terminal output from that file.
    """
    return_dict = 0
    args = input.get("args")

    path1 = _normalize_and_guard(input.get("path1", "."))
    if not os.path.exists(path1):
        raise ToolError(f"Path1 does not exist: {path1}")
    
    path2 = _normalize_and_guard(input.get("path2", "."))
    if not os.path.exists(path2):
        raise ToolError(f"Path2 does not exist: {path2}")
    
    
    cmd = f"diff {args} {path1} {path2}"
    
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
      "path1": path1 ,
      "path2": path2 ,
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


# cat
# less :  not usable in this context
# more  :  not usable in this context
# tail
# tree
# ps 

# which
# env

# diff
# cmp

# printenv


if __name__ == "__main__":
    mcp.run()
    
