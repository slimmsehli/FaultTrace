import asyncio
import json
import sys
import time
from typing import List, Dict, Optional
from dataclasses import dataclass, field
from pathlib import Path
from contextlib import AsyncExitStack
from openai import OpenAI
from mcp import ClientSession, StdioServerParameters
from mcp.client.stdio import stdio_client
from dotenv import load_dotenv

load_dotenv()
client = OpenAI()

# --- 1. CONFIGURATION ---
GPT_MODEL = "gpt-4o"  # Recommended for production over gpt-5-mini
SUMMARY_MODEL = "gpt-4o-mini"  # Cheaper model for housekeeping tasks
SYSTEM_PROMPT_PATH = "../prompts/system_prompt"

SERVER_CONFIGS = [
    {"command": "python", "args": ["../server/mcp_server_str_wrapper.py"]},
    {"command": "python", "args": ["../server/mcp_server_terminal.py"]}
]


@dataclass
class AgentState:
    messages: List[Dict] = field(default_factory=list)
    iteration_count: int = 0
    max_iterations: int = 20
    last_tool_call: Optional[str] = None


# --- 2. MCP MANAGER ---
class MCPManager:
    def __init__(self):
        self.exit_stack = AsyncExitStack()
        self.tool_to_session: Dict[str, ClientSession] = {}
        self.openai_tools = []

    async def connect(self, configs: List[Dict]):
        print("[INIT] Connecting to MCP Servers...")
        for cfg in configs:
            params = StdioServerParameters(command=cfg["command"], args=cfg["args"])
            transport = await self.exit_stack.enter_async_context(stdio_client(params))
            read, write = transport
            session = await self.exit_stack.enter_async_context(ClientSession(read, write))
            await session.initialize()

            res = await session.list_tools()
            for t in res.tools:
                self.tool_to_session[t.name] = session
                self.openai_tools.append({
                    "type": "function",
                    "function": {"name": t.name, "description": t.description, "parameters": t.inputSchema}
                })
        print(f"[INIT] {len(self.openai_tools)} tools ready.")

    async def cleanup(self):
        await self.exit_stack.aclose()


# --- 3. CORE UTILITIES (Parallelism & Cleanup) ---

async def execute_tool_task(name, args, call_id, session):
    """Helper to execute a single tool for parallel gathering."""
    try:
        result = await session.call_tool(name, args)
        content = result.content[0].text
    except Exception as e:
        content = f"Tool Error: {str(e)}"

    return {
        "role": "tool",
        "tool_call_id": call_id,
        "name": name,
        "content": content
    }


async def summarize_history(messages: List[Dict]) -> List[Dict]:
    """Condenses old messages to keep the context window lean."""
    if len(messages) < 12:  # Only summarize if context gets deep
        return messages

    print("🧠 [CONTEXT] Summarizing older iterations to optimize speed...")
    # Keep System Prompt [0], First User Goal [1], and last 4 messages for context
    to_summarize = messages[2:-4]
    retained_recent = messages[-4:]

    summary_prompt = [
        {"role": "system", "content": "Summarize the technical findings and actions taken so far. Be concise."},
        {"role": "user", "content": json.dumps(to_summarize)}
    ]

    summary = client.chat.completions.create(model=SUMMARY_MODEL, messages=summary_prompt)
    summary_msg = {"role": "system", "content": f"Summary of previous discovery: {summary.choices[0].message.content}"}

    return [messages[0], messages[1], summary_msg] + retained_recent


# --- 4. THE PRODUCTION REASONING LOOP ---

async def run_autonomous_reasoning(state: AgentState, mcp: MCPManager):
    for i in range(state.max_iterations):
        state.iteration_count = i + 1

        # Periodic Context Cleanup
        if i > 0 and i % 5 == 0:
            state.messages = await summarize_history(state.messages)

        response = client.chat.completions.create(
            model=GPT_MODEL,
            messages=state.messages,
            tools=mcp.openai_tools if mcp.openai_tools else None
        )

        msg = response.choices[0].message
        state.messages.append(msg)

        if msg.content:
            print(f"\n[REASONING] Iteration {state.iteration_count}: {msg.content}")

        if not msg.tool_calls:
            print("✅ Task Completed.")
            break

        # PARALLEL EXECUTION BLOCK
        tool_tasks = []
        for tool_call in msg.tool_calls:
            fname = tool_call.function.name
            fargs = json.loads(tool_call.function.arguments)

            # Simple Guardrail
            sig = f"{fname}({tool_call.function.arguments})"
            if sig == state.last_tool_call:
                print(f"⚠️  Loop Detected in {fname}. Skipping repeat.")
                continue

            print(f"🛠️  ACTION (Parallel): {fname}")
            tool_tasks.append(execute_tool_task(fname, fargs, tool_call.id, mcp.tool_to_session[fname]))
            state.last_tool_call = sig

        # Wait for all tools in this turn to finish at once
        if tool_tasks:
            tool_results = await asyncio.gather(*tool_tasks)
            state.messages.extend(tool_results)


# --- 5. MAIN INTERFACE ---

async def main():
    mcp = MCPManager()
    sys_prompt = Path(SYSTEM_PROMPT_PATH).read_text()
    state = AgentState(messages=[{"role": "system", "content": sys_prompt}])

    try:
        await mcp.connect(SERVER_CONFIGS)
        while True:
            user_input = input("\n[USER]: ").strip()
            if user_input.lower() in ["exit", "quit"]: break

            state.messages.append({"role": "user", "content": user_input})
            await run_autonomous_reasoning(state, mcp)
    finally:
        await mcp.cleanup()


if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print("\n[INFO] Exiting...")