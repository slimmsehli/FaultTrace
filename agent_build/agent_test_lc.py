######################################################
#
#
#
# This is a test for the AI main agent with a loop for response
#
#
#
######################################################

#import asyncio
#import json
#from openai import OpenAI
#from mcp import ClientSession, StdioServerParameters
#from mcp.client.stdio import stdio_client
#from dotenv import load_dotenv

import asyncio
from pathlib import Path
from langchain_mcp_adapters.client import MultiServerMCPClient
from langchain_openai import ChatOpenAI
import json
from dotenv import load_dotenv
### @NOTE this was a new update : message from error : Please update your import to `from langchain.agents import create_agent`. Deprecated in LangGraph V1.0 to be removed in V2.0.
from langchain.agents import create_agent 
#from langgraph.prebuilt import create_react_agent

async def run_agent():
	# load prompts : the mainsystem prompt and then first user prompt with the simulation details
	print(f"[INFO] : Loading prompts.")
	system_prompt = Path("../prompts/system_prompt").read_text() # load system prompt
	user_prompt = Path("../prompts/user_prompt").read_text() #this is only to be able to change the initial request made to the agent 
	
	# connect to MCP servers : linux terminal server and the second for the simulation tools
	print(f"[INFO] : Connecting to MCP servers.")
	client = MultiServerMCPClient({
		"Linux_terminal_tools_server": {
			"transport": "stdio", # @NOTE this is added because by default longchain client does not know how to talk to the mcp srvers  
			"command": "python3",
			"args": ["../server/mcp_server_terminal.py"],
		},
		"Simulation_tools_server": {
			"transport": "stdio", # @NOTE this is added because by default longchain client does not know how to talk to the mcp srvers  
			"command": "python3",
			"args": ["../server/mcp_server_str_wrapper.py"],
		}
	})
	
	# fetch the available tools from both servers and print a message
	tools = await client.get_tools()
	print(f"[INFO] : Connectd tools to the client found : {len(tools)} .")
	tools_list = []
	for tool in tools:
		one_tool = {
			"name" : tool.name,
			"description": tool.description,
			"args": tool.args 
		}
		tools_list.append(one_tool)
	
	with open("tools.json", "w") as f:
		json.dump(tools_list, f, indent=4)
	print(f"[INFO] : Tools dumped to tools.json file.")
	
	# init model
	load_dotenv() # load the API key from the .env file locally 
	print(f"[INFO] : Initialize Model : OpenAI - gpt-4o .")
	llm = ChatOpenAI(model="gpt-4o", temperature=0)
	
	# create agent 
	print(f"[INFO] : Creating the Agent.")
	agent = create_agent(model=llm, tools=tools, system_prompt=system_prompt) #@NOTE : this was modified in the last version of langchain 
	
	print(f"[INFO] : Running Agent ...")
	response = await agent.ainvoke({
		"message": [
			{"role": "user", "content": user_prompt}
		]
	})








"""
# load the .env variables 
load_dotenv()

# open AI client
client = OpenAI()

## load external prompts
from pathlib import Path
system_prompt = Path("../prompts/system_prompt").read_text() # load system prompt
user_prompt = Path("../prompts/user_prompt").read_text() #this is only to be able to change the initial request made to the agent

# GPT model to be used
gpt_model = "gpt-5-mini" #"gpt-4o"

## @NOTE : only loaded in the previous version where the tools are loaded manauly
#tools_list = json.loads(Path("../server/tools_register.json").read_text(encoding="utf-8"))

# @NOTE : load mcp server config :  removed since we are checking the available tools on the server directly with auto check
#cfg = json.loads(Path("../server/mcp_servers.json").read_text(encoding="utf-8"))

# @NOTE : log file and vcd file are always in the "../simulation" directory for now
# also the compilation script , the log file, the vcd file are given to the agent manually in fixed format

async def run_agent_loop():
    # @NOTE : call the MCP servers, only two now , one for RTL parsing files, vcs and logs 
    # and the other for linux terminal commands
    server_params1 = StdioServerParameters(command="python", args=["../server/mcp_server_str_wrapper.py"])
    server_params2 = StdioServerParameters(command="python", args=["../server/mcp_server_terminal.py"])

    async with stdio_client(server_params1) as (read1, write1), \
            stdio_client(server_params2) as (read2, write2):
        async with ClientSession(read1, write1) as session1, \
                ClientSession(read2, write2) as session2:
            # initialize the session
            await session1.initialize()
            await session2.initialize()

            mcp_tools = []
            tool_to_session = {}

            # Get tools from Server 1
            res1 = await session1.list_tools()
            for t in res1.tools:
                mcp_tools.append(t)
                tool_to_session[t.name] = session1

            # Get tools from Server 2
            res2 = await session2.list_tools()
            for t in res2.tools:
                mcp_tools.append(t)
                tool_to_session[t.name] = session2

            # Format for OpenAI and save to file
            openai_tools = [
                {"type": "function",
                 "function": {"name": t.name, "description": t.description, "parameters": t.inputSchema}}
                for t in mcp_tools
            ]
            
            print(f"[INFO] : Successfully loaded {len(openai_tools)} tools from MCP server.")
            with open("loaded_tools.log", "w", encoding="utf-8") as f:
                f.write(f"Total tools found: {len(mcp_tools)}\n")
                f.write("-" * 30 + "\n")
                for tool in mcp_tools:
                    f.write(f"Tool Name: {tool.name}\n")
                    f.write(f"Description: {tool.description}\n")
                    f.write(f"Parameters Schema: {json.dumps(tool.inputSchema, indent=2)}\n")
                    f.write("-" * 30 + "\n")

            print("[INFO] : Successfully saved tool list to 'loaded_tools'.")

            # System prompt for the Agent with the MCP tools
            messages = [
                {
                    "role": "system",
                    "content": system_prompt
                },
                {
                    "role": "user",
                    "content": user_prompt
                }
            ]

            ### Agent loop : for now it is 15 iterations but this will be changed to internal loop
            max_iterations = 50
            print(f"[INFO] : Starting the Agent ...")
            # Main loop
            for i in range(max_iterations):
                print(f"\n[Iteration {i + 1}] [AGENT] : Thinking...")
                # note : get a response from the LLM
                response = client.chat.completions.create(
                    model=gpt_model,
                    messages=messages,
                    tools=openai_tools,
                    tool_choice="auto"
                )
                ## note : add the LLM response to the message history
                response_message = response.choices[0].message
                messages.append(response_message)

                # debug : this prints the response of the LLM the inner thinking of the agent
                if response_message.content:
                    print(f"\n[Iteration {i + 1}] [AGENT] : {response_message.content}")

                # debug : check if the agent want to end the diagnosis so we end the program
                if not response_message.tool_calls:
                    print(f"\n[Iteration {i + 1}] [AGENT] : Root Cause Analysis Ended ")
                    print(response_message.content)
                    break

                # note : handleing tools calls
                for tool_call in response_message.tool_calls:
                    # debug : extracting the tool name and arguments to be passed to the tool function
                    fname = tool_call.function.name
                    try:
                     fargs = json.loads(tool_call.function.arguments)
                    except json.JSONDecodeError:
                     print(f"[ERROR] Failed to parse JSON arguments for {fname}. Skipping.")
                     continue

                    # debug : printing the function name and arguments to be called :  this is for debug purposes
                    print(f"\n[Iteration {i + 1}] [TOOL] : Tool Calling : {fname}, fargs: {fargs}")

                    # debug : execute the tool from the MCP server
                    #result = await session.call_tool(fname, fargs) ### removed
                    # ROUTING: Use the dictionary to pick the right session
                    target_session = tool_to_session[fname]
                    result = await target_session.call_tool(fname, fargs)
                    print(f"\n[Iteration {i + 1}] [TOOL] : Tool response : \n////\n {result} \n////\n")

                    # note : add the tool response to the message history
                    messages.append({
                        "role": "tool",
                        "tool_call_id": tool_call.id,
                        "name": fname,
                        "content": result.content[0].text
                    })

if __name__ == "__main__":
    asyncio.run(run_agent_loop())

"""

if __name__ == "__main__":
    asyncio.run(run_agent())
