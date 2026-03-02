
**************************************
* install ollama

sudo apt install zstd
curl -fsSL https://ollama.com/install.sh | sh

ollama --version

systemctl status ollama

**************************************
* choose a model

RAM									Model							Size
8G									Bqwen 2.5:7b			~4.7GB
16 GB								llama3.1:8b				~4.9 GB
32 GB+							llama3.1:70b			~40 GB
Any (coding focus)	qwen2.5-coder:7b	~4.7 GB

* pull a model using ollama
ollama pull llama3.1:8b
ollama list
ollama run llama3.1 "who you are?"
==> ollama automatically uses http://localhost:11434

* Sanity check for the ollama server 
curl http://localhost:11434/v1/models

**************************************
* use ollama for faulttrace agent 
* setting environement variables
export FAULTTRACE_PROVIDER=ollama
export FAULTTRACE_MODEL=llama3.1
python agent.py

* add setup to .env
FAULTTRACE_PROVIDER=ollama
FAULTTRACE_MODEL=llama3.1
OLLAMA_BASE_URL=http://localhost:11434/v1





