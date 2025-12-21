from engine import VeriDebugAgent
from dotenv import load_dotenv
from openai import OpenAI
#client = OpenAI(api_key=OPENAI_API_KEY)


load_dotenv()

# 1. Initialize the Agent with your API Key
# If using a local model or Claude, the setup is slightly different
#OPENAI_API_KEY = ""
agent = VeriDebugAgent() #api_key=OPENAI_API_KEY)

# 2. Run the flow
# Even if these files don't exist yet, the 'Mock' logic in execute_tool will handle it
agent.run_debug_flow(
    log_path="sim_vcs.log",
    vcd_path="waveform.vcd"
)