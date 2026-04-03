

default: echo "Nothing to run"

# nee to add the API keys before running,

clean:
	rm -rf output sessions logs ./agent/output ./agent/logs ./agent/sessions

run_ollama:
	export FAULTTRACE_PROVIDER=ollama
	export FAULTTRACE_MODEL=llama3.1
	cd agent ;\
	python3 agent.py --run-id cache

run_gpt:
	export FAULTTRACE_PROVIDER=openai
	export FAULTTRACE_MODEL=gpt-4o
	python3 agent/agent.py --run-id cache


run_anthropic:
	export FAULTTRACE_PROVIDER=anthropic
	export ANTHROPIC_API_KEY=
	python3 agent/agent.py --run-id cache

run_vllm:
	export FAULTTRACE_PROVIDER=vllm 
	export VLLM_BASE_URL=http://my-server:8000/v1
	export AULTTRACE_MODEL=mistral
	python3 agent/agent.py --run-id cache


