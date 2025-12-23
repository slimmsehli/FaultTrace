Root cause analysis Debug Agent for RTL verification 

This is an an agent project for RTL verification debug, it is built on MCP and openAI's GPT-4o
the main purpose of this agent is to parse a log file based on a UVM/Systemverilog simulation and try to debug the found errors
the prompt entry is that this agent is like a verification engineer that will try to use different tools to explore the environement and root cause the failure 

It uses the Reason+Act loop to call the log files, the source code and the vcd waveform to debug the errors 

It can open verilog/systemverilog files, vcd waveform files and log files to extract simulation details and information
Due to the possibility of having huge files to parse, multiple python functions are used to do the parsing in small chunks that the agent could handle 

Performed Main actions
waveform analysis, open a vcd file and extract different values of a different signals and transitions using multiple functions 
log files : open log files and extract related source code files and paths and simulation messages 
source code files : open verilog and systemverilog files to identify the context of different signals and what is the signal to probe 

Project Structure
engine_test.py: The Agent Client. Contains the OpenAI loop and logic.
server_test.py: The MCP Server. Hosts the Python tools for file and VCD manipulation.
sim.log / top.sv / wave.vcd: some examples from a simulation to test the code

Setup & Installation
Clone the Repo:Bashgit clone https://github.com/slimmsehli/RCAnalysis.git
cd RCAnalysis
Install Dependencies: Bashpip install mcp openai vcdvcd
OPENAI_API_KEY is set to be read from .env file so make sure that you add it to your .env and it is already removed from git 

Current status :
it can perform 15 iteration to extract a UVM erros from a log file, search the related source code and check the signal in question from the vcd 
multiple functions need to be added to this inorder to enahnce the agent, feel free to add what you can see fits 
