######################################################
#
#
#
# This is a test for the ai main agent with a loop for response
#
#
#
######################################################

import asyncio
import json
from openai import OpenAI
from mcp import ClientSession, StdioServerParameters
from mcp.client.stdio import stdio_client
from dotenv import load_dotenv

# fo debugging messages

#
load_dotenv()

# open AI client
client = OpenAI()

### this part was added to load the system prompt from external file
from pathlib import Path
system_prompt = Path("../agent/system_prompt").read_text()
tools_list = json.loads(Path("../server/tools_register.json").read_text(encoding="utf-8"))
#load mcp server config
cfg = json.loads(Path("../server/mcp_servers.json").read_text(encoding="utf-8"))

# note : log file and vcd file are always in the "./simulation" directory for now
# also the compilation script , the log file, the vcd file are given to the agent manually in fixed format

async def run_agent_loop():
    # note : call the MCP server that contains all the tools
    server_params = StdioServerParameters(command="python", args=["../server/mcp_server_str_wrapper.py"])

    async with stdio_client(server_params) as (read, write):
        async with ClientSession(read, write) as session:
            await session.initialize()

            ### System prompt for the Agent
            messages = [
                {
                    "role": "system",
                    "content": system_prompt
                },
                {
                    "role": "user",
                    "content": "Investigate the failure in 'sim.log' and explain the code error."
                }
            ]

            ### Tools list defined on the mcp server
            tools = tools_list

            ### Agent loop

            # note : max iterations ofr the agent thingking loop
            max_iterations = 15

            # Main loop
            for i in range(max_iterations):
                print(f"\n[Iteration {i + 1}] [AGENT] : Thinking...")
                # note : get a response from the LLM
                response = client.chat.completions.create(
                    model="gpt-4o",
                    messages=messages,
                    tools=tools,
                    tool_choice="auto"
                )
                ## note : add the LLM response to the message history
                response_message = response.choices[0].message
                messages.append(response_message)

                # debug : this prints the response of the LLM aka the inner thinking of the agent
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
                    fargs = json.loads(tool_call.function.arguments)

                    # debug : printing the function name and arguments to be called :  this is for debug purposes
                    print(f"\n[Iteration {i + 1}] [TOOL] : Tool Calling : {fname}, fargs: {fargs}")

                    # debug : execute the tool from the MCP server
                    result = await session.call_tool(fname, fargs)
                    #print(f"\n[Iteration {i + 1}] [TOOL] : Tool response : \n////\n {result.} \n////\n")

                    # note : add the tool response to the message history
                    messages.append({
                        "role": "tool",
                        "tool_call_id": tool_call.id,
                        "name": fname,
                        "content": result.content[0].text
                    })

if __name__ == "__main__":
    asyncio.run(run_agent_loop())
