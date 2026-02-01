######################################################
#
#
#
# This is a test for the AI main agent with a loop for response
#
#
#
######################################################
import time
import asyncio
import json
import sys
from openai import OpenAI
from mcp import ClientSession, StdioServerParameters
from mcp.client.stdio import stdio_client
from dotenv import load_dotenv
from pathlib import Path
from contextlib import AsyncExitStack

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

## MCP servers
SERVER_CONFIGS = [
    {"command": "python", "args": ["../server/mcp_server_str_wrapper.py"]},
    {"command": "python", "args": ["../server/mcp_server_terminal.py"]}
]

## @NOTE : only loaded in the previous version where the tools are loaded manauly
#tools_list = json.loads(Path("../server/tools_register.json").read_text(encoding="utf-8"))

# @NOTE : load mcp server config :  removed since we are checking the available tools on the server directly with auto check
#cfg = json.loads(Path("../server/mcp_servers.json").read_text(encoding="utf-8"))

# @NOTE : log file and vcd file are always in the "../simulation" directory for now
# also the compilation script , the log file, the vcd file are given to the agent manually in fixed format
async def run_agent_loop():
    async with AsyncExitStack() as stack: # multiple asynchronous context
        sessions = []
        tool_to_session = {}
        openai_tools = []
        print("[INFO] : Loading Connecting to MCP servers ...")

        for cfg in SERVER_CONFIGS:
            params = StdioServerParameters(command=cfg["command"], args=cfg["args"])
            # connect to the stdio transport
            read, write = await stack.enter_async_context(stdio_client(params))
            # create session
            session = await stack.enter_async_context(ClientSession(read, write))
            await session.initialize()
            sessions.append(session)

            # register tools
            res = await session.list_tools()
            for t in res.tools:
                tool_to_session[t.name] = session
                openai_tools.append({
                    "type": "function",
                    "function": {
                        "name": t.name,
                        "description": t.description,
                        "parameters": t.inputSchema
                    }
                })

        print(f"[INFO] : {len(openai_tools)} tools loaded. System ready.")

        # Initialize message history with system prompt
        messages = [{"role": "system", "content": system_prompt}]

        ##### main terminal loop

        # --- LOOP 1: General Interaction Loop ---
        while True:
            user_input = input("\n[USER]: ")

            # User-controlled exit condition
            if user_input.lower() in ["exit", "quit"]:
                print("[INFO] : Shutting down agent. Goodbye!")
                break

            # Add user message to history
            messages.append({"role": "user", "content": user_input})

            # --- LOOP 2: Autonomous Agent Reasoning (Max 20 Iterations) ---
            print(f"[INFO] : Agent is starting work on your request...")

            for i in range(20):
                response = client.chat.completions.create(
                    model=gpt_model,
                    messages=messages,
                    tools=openai_tools if openai_tools else None,
                    tool_choice="auto"
                )

                response_message = response.choices[0].message
                messages.append(response_message)

                # 1. Print Agent's verbal response if it has one
                if response_message.content:
                    print(f"\n[Iteration {i + 1}] [AGENT]: {response_message.content}")

                # 2. Check if the Agent is done (No more tool calls)
                if not response_message.tool_calls:
                    print(f"\n[INFO] : Agent completed the task in {i + 1} steps.")
                    break  # Breaks Loop 2, goes back to Loop 1 for next User input

                # 3. Handle Tool Execution
                if response_message.tool_calls:
                    for tool_call in response_message.tool_calls:
                        fname = tool_call.function.name
                        fargs = json.loads(tool_call.function.arguments)

                        print(f"[Iteration {i + 1}] [TOOL]: ToolCall => {fname} with arguments {fargs}")

                        target_session = tool_to_session[fname]
                        result = await target_session.call_tool(fname, fargs)

                        tool_output = result.content[0].text
                        print(f"[Iteration {i + 1}] [TOOL]: ToolResult => {tool_output}")

                        messages.append({
                            "role": "tool",
                            "tool_call_id": tool_call.id,
                            "name": fname,
                            "content": result.content[0].text
                        })
                else:
                    break
            else:
                # This executes if the for-loop reaches 20 without a 'break'
                print("\n[WARNING] : Agent reached the maximum limit of 20 iterations.")

    """
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
                    fargs = json.loads(tool_call.function.arguments)

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
    """
if __name__ == "__main__":
    start_time = 0
    try:
        start_time = time.perf_counter()
        asyncio.run(run_agent_loop())
    except KeyboardInterrupt:
        print("\n[INFO] : Closing Agent ...")
        end_time = time.perf_counter()
        print(f"Execution time: {end_time - start_time:.4f} seconds")
        sys.exit(0)
