
import json
from typing import List, Dict, Any
from openai import OpenAI



class VeriDebugAgent:
    #def __init__(self, api_key: str, model: str = "gpt-4o"):
    def __init__(self, model: str = "gpt-4o"):
        self.client = OpenAI() #api_key=api_key)
        self.model = model
        # The System Prompt is the "Mindset"
        self.system_prompt = (
            "You are a Senior Silicon Verification Application Engineer. Your goal is to debug RTL failures "
            "using a systematic triangulation approach: Log Analysis -> Waveform Inspection -> Source Code Analysis.\n\n"
            "MINDSET RULES:\n"
            "1. NEVER assume a fix without seeing the relevant signals in the VCD.\n"
            "2. ALWAYS check the 'Reset' and 'Clock' state if a signal is behaving unexpectedly.\n"
            "3. VERIFY your hypothesis. If you think it's a FIFO overflow, you MUST call 'get_waveform_context' "
            "to prove the 'full' signal was high during a write.\n"
            "4. SELF-QUESTIONING: After every tool observation, ask yourself: 'Does this data support my current theory?'\n\n"
            "RESPONSE FORMAT:\n"
            "Thought: [Your reasoning and what you plan to do next]\n"
            "Action: [The tool name to call]\n"
            "Action Input: [The parameters for the tool]\n"
        )
        self.history = [{"role": "system", "content": self.system_prompt}]

    def run_debug_flow(self, log_path: str, vcd_path: str):
        print(f"--- Starting Autonomous Debug: {log_path} ---")

        # Initial trigger: Find the error
        user_input = f"Debug the failure in log file: {log_path}. The associated waveform is {vcd_path}."
        self.history.append({"role": "user", "content": user_input})

        iteration = 0
        max_iterations = 7  # Preventing infinite loops

        while iteration < max_iterations:
            iteration += 1
            print(f"\n[Iteration {iteration}] Thinking...")

            # 1. Get Agent's Thought and Action
            response = self.client.chat.completions.create(
                model=self.model,
                messages=self.history,
                tools=self.get_mcp_tool_definitions(),
                tool_choice="auto"
            )

            message = response.choices[0].message
            self.history.append(message)

            # 2. Check if the Agent wants to provide a final diagnosis
            if not message.tool_calls:
                print("\n[!] FINAL DIAGNOSIS:")
                print(message.content)
                break

            # 3. Execute Tool Calls (The "Act" phase)
            for tool_call in message.tool_calls:
                tool_result = self.execute_tool(tool_call, log_path, vcd_path)

                # 4. Feed Observation back to Agent
                print(f"[Action] Called {tool_call.function.name}")
                self.history.append({
                    "role": "tool",
                    "tool_call_id": tool_call.id,
                    "name": tool_call.function.name,
                    "content": json.dumps(tool_result)
                })

    def execute_tool(self, tool_call, log_path, vcd_path) -> Any:
        """Dispatches the tool call to your actual parser functions."""
        name = tool_call.function.name
        args = json.loads(tool_call.function.arguments)

        # Map LLM calls to your specific Parser Blocks
        if name == "analyze_log":
            # return log_parser.extract_errors(log_path)
            return {"time": 550, "msg": "UVM_ERROR: FIFO Overflow", "file": "fifo_top.sv", "line": 42}

        elif name == "get_waveform":
            # return vcd_parser.get_signal_snapshot(vcd_path, args['signals'], args['time'])
            return {"clk": 1, "fifo_full": 1, "wr_en": 1, "data_in": "0xDEADBEEF"}

        elif name == "read_source":
            # return source_parser.get_code_slice(args['file'], args['line'])
            return "always @(posedge clk) if (wr_en && fifo_full) report_error();"

        return {"error": "Tool not found"}

    def get_mcp_tool_definitions(self):
        """Standard JSON schemas for MCP tools."""
        return [
            {
                "type": "function",
                "function": {
                    "name": "analyze_log",
                    "description": "Extracts failure timestamp and location from simulation logs."
                }
            },
            {
                "type": "function",
                "function": {
                    "name": "get_waveform",
                    "description": "Gets signal values at a specific time from VCD.",
                    "parameters": {
                        "type": "object",
                        "properties": {
                            "signals": {"type": "array", "items": {"type": "string"}},
                            "time": {"type": "number"}
                        }
                    }
                }
            },
            {
                "type": "function",
                "function": {
                    "name": "read_source",
                    "description": "Reads RTL source code to understand logic.",
                    "parameters": {
                        "type": "object",
                        "properties": {
                            "file": {"type": "string"},
                            "line": {"type": "integer"}
                        }
                    }
                }
            }
        ]