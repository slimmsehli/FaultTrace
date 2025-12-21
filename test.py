from engine import VeriDebugAgent

# 1. Initialize the Agent with your API Key
# If using a local model or Claude, the setup is slightly different
OPENAI_API_KEY = "your-api-key-here"
agent = VeriDebugAgent(api_key=OPENAI_API_KEY)

# 2. Run the flow
# Even if these files don't exist yet, the 'Mock' logic in execute_tool will handle it
agent.run_debug_flow(
    log_path="sim_vcs.log",
    vcd_path="waveform.vcd"
)