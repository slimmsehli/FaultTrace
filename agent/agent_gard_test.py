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

class AgentState:
    def __init__(self, sys_prompt):
        self.messages = [{"role": "system", "content": sys_prompt}]
        self.iteration_count = 0
        self.max_iterations = 20
        self.finished = False


## @NOTE : only loaded in the previous version where the tools are loaded manauly
#tools_list = json.loads(Path("../server/tools_register.json").read_text(encoding="utf-8"))

# @NOTE : load mcp server config :  removed since we are checking the available tools on the server directly with auto check
#cfg = json.loads(Path("../server/mcp_servers.json").read_text(encoding="utf-8"))

# @NOTE : log file and vcd file are always in the "../simulation" directory for now
# also the compilation script , the log file, the vcd file are given to the agent manually in fixed format

async def autonomous_reasoning_cycle(state, user_input, openai_tools, tool_to_session):
    state.messages.append({"role": "user", "content": user_input})
    state.iteration_count = 0
    last_action = None  # To detect infinite loops

    while state.iteration_count < state.max_iterations:
        state.iteration_count += 1

        # 1. GENERATE NEXT STEP (Reasoning)
        response = client.chat.completions.create(
            model=gpt_model,
            messages=state.messages,
            tools=openai_tools,
            tool_choice="auto"
        )

        msg = response.choices[0].message
        state.messages.append(msg)

        # 2. PRINT REASONING (Transparency)
        if msg.content:
            print(f"\n[STEP {state.iteration_count}] THOUGHT: {msg.content}")

        # 3. EVALUATE & ACT
        if not msg.tool_calls:
            print(f"✅ GOAL REACHED")
            return msg.content  # Final Answer

        for tool_call in msg.tool_calls:
            fname = tool_call.function.name
            fargs = json.loads(tool_call.function.arguments)

            # GUARDRAIL: Simple loop detection
            current_action = f"{fname}:{tool_call.function.arguments}"
            if current_action == last_action:
                error_msg = "Error: You are repeating the exact same tool call. Try a different approach."
                state.messages.append(
                    {"role": "tool", "tool_call_id": tool_call.id, "name": fname, "content": error_msg})
                print(f"⚠️  LOOP DETECTED: Forcing agent to pivot...")
                continue

            last_action = current_action

            # 4. EXECUTE (Action)
            print(f"🛠️  ACTION: {fname}...")
            try:
                target_session = tool_to_session[fname]
                result = await target_session.call_tool(fname, fargs)
                observation = result.content[0].text

                # 5. LOG OBSERVATION
                print(f"👁️  OBSERVATION: {observation[:100]}...")  # Print first 100 chars

                state.messages.append({
                    "role": "tool",
                    "tool_call_id": tool_call.id,
                    "name": fname,
                    "content": observation
                })
            except Exception as e:
                print(f"❌ TOOL ERROR: {str(e)}")
                state.messages.append({
                    "role": "tool",
                    "tool_call_id": tool_call.id,
                    "name": fname,
                    "content": f"Error executing tool: {str(e)}"
                })

    return "Agent timed out after 20 iterations."


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
