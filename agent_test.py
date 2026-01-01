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

load_dotenv()

client = OpenAI()

log_file = "./simulation/sim.log"
vcd_file = "./simulation/sim.vcd"

async def run_agent_loop():
    server_params = StdioServerParameters(command="python", args=["mcp_server_std_wrapper.py"])

    async with stdio_client(server_params) as (read, write):
        async with ClientSession(read, write) as session:
            await session.initialize()

            ### System prompt for the Agent
            messages = [
                {
                    "role": "system",
                    "content": (
                        "**Role:** You are an expert RTL Verification Engineer specializing in UVM (Universal Verification Methodology) and SystemVerilog. Your goal is to identify the root cause of UVM_ERRORs and suggest precise fixes.\n"
                        ""
                        "**Available Environment:**"
                        "You have access to an MCP server providing tools for file reading, log analysis and vcd waveform file parsing. You MUST use these tools to investigate the codebase and simulation artifacts.\n"
                        "\n"
                        "**Debugging Protocol:** \n"
                        "1. **Log Analysis:** Start by reading the simulation log. Use tools to find the specific UVM_ERROR message and the simulation time it occurred.\n"
                        "2. **Context Gathering:** Identify which UVM component (driver, monitor, scoreboard) reported the error. and in which file the component is declared, the signals to look for.\n"
                        "3. **Traceability:** Use the different tools to \n"
                        "    - check the available signals list in the vcd file before looking for more details about signals in the vcd itself.\n"
                        "    - Open source files and extract the needed context and code related to the error and for debug from them.\n"
                        "    - Examine the relevant SystemVerilog/UVM files.\n"
                        "    - Check the configuration database (uvm_config_db) and factory overrides if the error relates to connectivity or types.\n"
                        "    - Understand the testbench structure and the components.\n"
                        "    - use tools to extract signals transitions and values during the simulation to identify the issue.\n"
                        "4. **Hypothesis:** Formulate a theory on why the error occurred (e.g., protocol violation, timing mismatch, or incorrect constraint).\n"
                        "5. **Verification:** Use your tools to check related source code files, log files and waveform vcd files to confirm your hypothesis.\n"
                        "\n"
                        "**Constraints:** \n"
                        "- The vcd file does not contain the waveforms of the signals and variables inside the uvm classes .\n"
                        "- The VCD file contains only the signals from the modules and the interfaces.\n"
                        "- Do not hallucinate file paths check if the paths already exist in the environment files.\n"
                        "- Always provide the file path and line number when suggesting a fix.\n"
                        "- If the error is due to a DUT (Device Under Test) bug vs. a Testbench bug, clearly state your reasoning.\n"
                        "\n"
                        "**Tone:** Professional, analytical, and concise. Focus on technical evidence over general advice.\n"
                        "all files are inside the directory ./simulation \n"
                        "the name of the log file and the waveform vcd file are sim.log and sim.vcd"
                    )
                },
                {
                    "role": "user",
                    "content": "Investigate the failure in 'sim.log' and explain the code error."
                }
            ]

            ### Tools list defined on the mcp server
            tools = [
                # search_log_keyword
                {
                    "type": "function",
                    "function": {
                        "name": "search_log_keyword",
                        "description": "Search log for keywords and get surrounding context.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "log_path": {"type": "string"},
                                "keyword": {"type": "string"},
                                "context_lines": {"type": "integer"}
                            },
                            "required": ["log_path", "keyword"]
                        }
                    }
                },
                # get_source_snippet
                {
                    "type": "function",
                    "function": {
                        "name": "get_source_snippet",
                        "description": "Extract a portion of the Verilog/SystemVerilog source code.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "file_path": {"type": "string"},
                                "line_number": {"type": "integer"},
                                "context": {"type": "integer", "default": 5}
                            },
                            "required": ["file_path", "line_number"]
                        }
                    }
                },
                # vcd_get_simulation_time
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_get_simulation_time",
                        "description": "Returns the total simulation time (duration) of the VCD file.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string", "description": "Path to the VCD file."}
                            },
                            "required": ["path"]
                        }
                    }
                },
                # vcd_get_timescale_str
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_get_timescale_str",
                        "description": "Returns the magnitude and unit of the simulation timescale (e.g., 1 ns).",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"}
                            },
                            "required": ["path"]
                        }
                    }
                },
                # vcd_get_signal_value_at_timestamp
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_get_signal_value_at_timestamp",
                        "description": "Get the value of a specific signal at a precise timestamp.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "signal_name": {"type": "string",
                                                "description": "Full hierarchical name, e.g., 'top.dut.clk'"},
                                "timestamp": {"type": "number", "description": "The simulation time to query."}
                            },
                            "required": ["path", "signal_name", "timestamp"]
                        }
                    }
                },
                # vcd_get_signal_values_in_timeframe
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_get_signal_values_in_timeframe",
                        "description": "Returns all signal changes and values within a specified time window.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "signal_name": {"type": "string"},
                                "start": {"type": "integer"},
                                "end": {"type": "integer"}
                            },
                            "required": ["path", "signal_name", "start", "end"]
                        }
                    }
                },
                # vcd_count_signal_all_transitions
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_count_signal_all_transitions",
                        "description": "Counts the number of signal edges (posedge/negedge) in a time window.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "signal_name": {"type": "string"},
                                "edge": {"type": "string", "enum": ["posedge", "negedge", "both"]},
                                "start": {"type": "number"},
                                "end": {"type": "number"},
                                "bit_index": {"type": "integer",
                                              "description": "Optional bit index if the signal is a bus."}
                            },
                            "required": ["path", "signal_name", "edge", "start", "end"]
                        }
                    }
                },
                # vcd_next_change_after
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_next_change_after",
                        "description": "Find the very next time a signal changes after a given timestamp.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "signal_name": {"type": "string"},
                                "timestamp": {"type": "number"}
                            },
                            "required": ["path", "signal_name", "timestamp"]
                        }
                    }
                },
                # vcd_prev_change_before
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_prev_change_before",
                        "description": "Find the most recent time a signal changed before a given timestamp.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "signal_name": {"type": "string"},
                                "timestamp": {"type": "number"}
                            },
                            "required": ["path", "signal_name", "timestamp"]
                        }
                    }
                },
                # vcd_search_value
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_search_value",
                        "description": "Searches for occurrences of a specific value on a signal within a time range.",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "signal_name": {"type": "string"},
                                "value": {"type": "string",
                                          "description": "The value to search for (e.g. '1', '0', '4'hAF')."},
                                "start": {"type": "number"},
                                "end": {"type": "number"}
                            },
                            "required": ["path", "signal_name", "value"]
                        }
                    }
                },
                # list_vcd_signals
                {
                    "type": "function",
                    "function": {
                        "name": "list_vcd_signals",
                        "description": "List all signal names in the VCD. Use a pattern to filter (e.g. 'dut').",
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "pattern": {"type": "string"}
                            },
                            "required": ["path"]
                        }
                    }
                },
                # vcd_get_signals_aligned_in_window
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_get_signals_aligned_in_window",
                        "description": """
                            Returns (times, values_by_signal):
                            - times: sorted list including 'start' and all change times of the requested signals
                                     that fall within (start, end].
                            - values_by_signal: {signal_name: [v0, v1, ...]} aligned to 'times'
                              using step/hold semantics (previous value up to next change).
                            """,
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "signal_names": {"type": "string"},
                                "start": {"type": "integer"},
                                "end": {"type": "integer"}

                            },
                            "required": ["path", "signal_names", "start", "end"]
                        }
                    }
                },
                # vcd_get_signals_values_at_timestamp
                {
                    "type": "function",
                    "function": {
                        "name": "vcd_get_signals_values_at_timestamp",
                        "description": """
                            Return a dict {signal_name: value_at_timestamp} for multiple signals.
                            - method='previous': last value at or before timestamp (step/hold semantics)
                            - method='exact': only return a value if there is an event exactly at timestamp; else None
                            """,
                        "parameters": {
                            "type": "object",
                            "properties": {
                                "path": {"type": "string"},
                                "signal_names": {"type": "string"},
                                "timestamp": {"type": "integer"}
                            },
                            "required": ["path", "signal_names", "timestamp"]
                        }
                    }
                }
            ]

            ### Agent ReAct loop

            # max iterations ofr the agent thingking loop
            max_iterations = 15

            # Main loop
            for i in range(max_iterations):
                print(f"\n\n\n\n[Iteration {i + 1}] Thinking...")

                response = client.chat.completions.create(
                    model="gpt-4o",
                    messages=messages,
                    tools=tools,
                    tool_choice="auto"
                )

                response_message = response.choices[0].message
                messages.append(response_message)

                # this prints the agent inner thinking
                if response_message.content:
                    print(f"\n\n[REASONING]: {response_message.content}")

                # Check if the LLM wants to finish or call a tool
                if not response_message.tool_calls:
                    print("\n\n--- Final Diagnosis ---")
                    print(response_message.content)
                    break

                # Handle tool calls
                for tool_call in response_message.tool_calls:
                    fname = tool_call.function.name
                    fargs = json.loads(tool_call.function.arguments)

                    # LOGGING FOR YOU TO TRACK PROGRESS
                    print(f"\n\n[Iteration {i + 1}] LLM calls {fname}, fargs {fargs}")

                    # Execute the MCP tool (which calls your vcdvcd wrapper)
                    result = await session.call_tool(fname, fargs)
                    print(f"\n\n[Iteration {i + 1}] LLM results from function \n////\n {result} \n////\n")

                    messages.append({
                        "role": "tool",
                        "tool_call_id": tool_call.id,
                        "name": fname,
                        "content": result.content[0].text
                    })

if __name__ == "__main__":
    asyncio.run(run_agent_loop())
