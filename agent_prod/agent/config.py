
### this config file is for loading the necessary configuration for the agent 
# including the mcp servers , th emodel swap and the paths 
# LLMconfig : will update the model 
# Loop config : will update the agent main loop config
# PathConfig : will change the paths for logs, prompts and other files related to agent


from __future__ import annotations

import os
from dataclasses import dataclass, field
from pathlib import Path

TOPDIR = os.getenv("TOPDIR", ".")


################################ MCP server definition

@dataclass(frozen=True)
class MCPServerConfig:
    """One MCP server process the agent can talk to."""
    label:   str        # human-readable name used in logs
    command: str        # executable (e.g. "python")
    args:    list[str]  # argv (e.g. ["../server/mcp_server_terminal.py"])



################################ LLM provider definition

@dataclass
class LLMConfig:
    """
    Which model to use and how to call it.
    The provider field is reserved for the LLM-wrapper layer (Phase 2).
    """
    model:              str   = "gpt-5-mini" #"gpt-5" #"gpt-4o-mini"
    temperature:        float = 1.0           # deterministic for debugging @NOTE : gpt5 only accept temperature 1 not 0
    max_tokens:         int   = 4096
    # Retries on rate-limit / transient connection errors
    max_retries:        int   = 3
    retry_base_delay:   float = 5.0           # seconds; doubles each attempt


################################ main agent loop configurations and setup

@dataclass
class LoopConfig:
    """Controls how the agent loop runs and when it stops."""
    max_iterations:         int   = 50
    # Stop when the model produces this many consecutive text-only turns
    max_idle_turns:         int   = 10
    # Context window budget in estimated tokens (~4 chars = 1 token)
    context_token_budget:   int   = 500_000
    # Always keep at least this many recent message pairs even when trimming
    min_recent_pairs:       int   = 8

################################ tool configuration for the reran in case of failure 

@dataclass
class ToolConfig:
    """Retry behaviour for individual MCP tool calls."""
    max_retries:    int   = 5
    retry_delay:    float = 1.5   # seconds; multiplied by attempt number

################################ file system for paths, logs files and prompt inputs 

@dataclass
class PathConfig:
    prompts_dir:  Path = Path(f"{TOPDIR}/prompts")
    output_dir:   Path = Path(f"{TOPDIR}/output")
    log_dir:      Path = Path(f"{TOPDIR}/logs")
    sessions_dir: Path = Path(f"{TOPDIR}/sessions")  # reserved for session persistence (Phase 2)

    def ensure_dirs(self) -> None:
        for p in (self.output_dir, self.log_dir, self.sessions_dir):
            p.mkdir(parents=True, exist_ok=True)


################################ Top level config of the agent 

@dataclass
class AgentConfig:
    """
    Root configuration object.  Instantiate once in main() and pass around.
    All sub-configs have sensible defaults — only override what you need.
    """
    llm:   LLMConfig  = field(default_factory=LLMConfig)
    loop:  LoopConfig = field(default_factory=LoopConfig)
    tools: ToolConfig = field(default_factory=ToolConfig)
    paths: PathConfig = field(default_factory=PathConfig)
    
    # to add new mcp server it it needs to be added here 
    mcp_servers: list[MCPServerConfig] = field(default_factory=lambda: [
        MCPServerConfig(
            label="rtl-file-parser",
            command="python",
            args=[f"{TOPDIR}/server/mcp_server_str_wrapper.py"],
        ),
        MCPServerConfig(
            label="linux-terminal",
            command="python",
            args=[f"{TOPDIR}/server/mcp_server_terminal.py"],
        ),
    ])

    def __post_init__(self) -> None:
        self.paths.ensure_dirs()


