
OPENAI_API_KEY=sk-... python agent.py

# Or explicitly
FAULTTRACE_PROVIDER=openai FAULTTRACE_MODEL=gpt-4o python agent.py

# Ollama local
FAULTTRACE_PROVIDER=ollama FAULTTRACE_MODEL=llama3.1 python agent.py

# Anthropic
FAULTTRACE_PROVIDER=anthropic ANTHROPIC_API_KEY=sk-ant-... python agent.py

# vLLM on-prem
FAULTTRACE_PROVIDER=vllm VLLM_BASE_URL=http://my-server:8000/v1 FAULTTRACE_MODEL=mistral python agent.py
