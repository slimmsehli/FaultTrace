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
	##############################################################################################
	# load prompts : the mainsystem prompt and then first user prompt with the simulation details
	print(f"[INFO] : Loading prompts.")
	system_prompt = Path("../prompts/system_prompt").read_text() # load system prompt
	user_prompt = Path("../prompts/user_prompt").read_text() #this is only to be able to change the initial request made to the agent 
	
	##############################################################################################
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
	
	##############################################################################################
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
	
	##############################################################################################
	# init model
	load_dotenv() # load the API key from the .env file locally 
	print(f"[INFO] : Initialize Model : OpenAI - gpt-4o .")
	llm = ChatOpenAI(model="gpt-4o", temperature=0)
	
	##############################################################################################
	# create agent 
	print(f"[INFO] : Creating the Agent.")
	agent = create_agent(model=llm, tools=tools, system_prompt=system_prompt) #@NOTE : this was modified in the last version of langchain 
	
	print(f"[INFO] : Running Agent ...")
	"""
	response = await agent.ainvoke({
		"message": [
			{"role": "user", "content": user_prompt}
		]
	})
	"""
	async for chunk in agent.astream(
		{"messages": [("user", user_prompt)]}, 
		stream_mode="updates"
	):
		for node_name, data in chunk.items():
			print(f"\n--- [Node: {node_name}] ---")

			# The 'data' usually contains a list of messages added in this step
			if "messages" in data:
				last_msg = data["messages"][-1]

			# Check if it's a Tool Call (The Agent is deciding to use a tool)
			if hasattr(last_msg, "tool_calls") and last_msg.tool_calls:
				for tool_call in last_msg.tool_calls:
					print(f" ACTION: Calling tool '{tool_call['name']}'")
					print(f"    Args: {tool_call['args']}")

			# Check if it's a Tool Result (The MCP server responded)
			elif last_msg.type == "tool":
				print(f" OBSERVATION: Tool returned data.")
				# print(f"    Result: {last_msg.content[:200]}...") # Optional: see snippet of result

			# Check if it's the final Answer or Thought
			else:
				print(f" THOUGHT/RESPONSE: {last_msg.content}")

if __name__ == "__main__":
    asyncio.run(run_agent())
