Root cause analysis Debug Agent for RTL verification 

This is an an agent project for RTL verification debug, it is built on MCP and openAI's GPT-4o
the main purpose of this agent is to parse a log file based on a UVM/Systemverilog simulation and try to debug the found errors
the prompt entry is that this agent is like a verification engineer that will try to use different tools to explore the environement and root cause the failure 

* Current status
 This is in dev project so it is no clean and not fully production, it has multiple features but yet an open project 

* Supported AI models
Currently this supports GPT using openai API or ollama local llm models 

** For GPT
	- Add the OPENAI_API_KEY=  to the .env file in the main directory
** For Ollama
	- Use the readme file in the ./models/readme.md to download and install local ollama and pull a model and run it
		choose a model Bqwen 2.5:7b(8Gb RAM) or llama3.1:8b(16Gb RAM)
		ollama pull llama3.1:8b
		ollama list
		ollama run llama3.1 
		by default it runs on http://localhost:11434

* How to run this agent 
	after setting up the LLM model to use 
	cd ./agent_prod
	change the paths to the simulation resources in the ./prompts/user_prompt
	use the Makefile to run using ollama or gpt (make run_gpt or make run_ollama )
	after the agent finishes, check the output report at ./outputs/report/<>.html
	checl all the sessions run in ./sessions/index.html (it will be updated after each run)


