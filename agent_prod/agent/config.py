"""
config.py
─────────
All configuration for the RTL Debug Agent.

PROVIDER SELECTION
──────────────────
Set llm.provider to one of:
  "openai"    — OpenAI API (GPT-4o, GPT-5, etc.)
  "anthropic" — Anthropic Claude (claude-opus-4-5, etc.)
  "gemini"    — Google Gemini (gemini-1.5-pro, etc.)
  "ollama"    — Local Ollama server (llama3.1, qwen2.5, etc.)
  "vllm"      — Local vLLM server (any HuggingFace model)

ENVIRONMENT VARIABLE OVERRIDES (Kubernetes / Docker)
─────────────────────────────────────────────────────
Every config field can be overridden via environment variables.
This means you never need to rebuild the image to change providers or models.

  LLM
  ───
  FAULTTRACE_PROVIDER          openai | anthropic | gemini | ollama | vllm
  FAULTTRACE_MODEL             model name (e.g. gpt-4o, claude-opus-4-5)
  FAULTTRACE_TEMPERATURE       float  (default 1.0)
  FAULTTRACE_MAX_TOKENS        int    (default 4096)
  FAULTTRACE_MAX_RETRIES       int    (default 3)
  FAULTTRACE_RETRY_BASE_DELAY  float  (default 5.0)
  FAULTTRACE_BASE_URL          custom base URL (Ollama / vLLM / Azure)

  LOOP
  ────
  FAULTTRACE_MAX_ITERATIONS    int    (default 50)
  FAULTTRACE_MAX_IDLE_TURNS    int    (default 10)
  FAULTTRACE_CONTEXT_BUDGET    int    (default 500000 tokens)

  PATHS
  ─────
  TOPDIR                       workspace root (default: ".")
  FAULTTRACE_OUTPUT_DIR        output directory
  FAULTTRACE_LOG_DIR           log directory
  FAULTTRACE_SESSIONS_DIR      sessions directory
  FAULTTRACE_PROMPTS_DIR       prompts directory

  API KEYS  (injected from K8s Secrets)
  ──────────────────────────────────────
  OPENAI_API_KEY
  ANTHROPIC_API_KEY
  GOOGLE_API_KEY
  VLLM_API_KEY                 (optional, default: token-abc123)
  OLLAMA_BASE_URL              (default: http://localhost:11434/v1)
  VLLM_BASE_URL                (default: http://localhost:8000/v1)
"""

from __future__ import annotations

import os
from dataclasses import dataclass, field
from pathlib import Path


# ── Helpers ────────────────────────────────────────────────────────────────────

def _env_str(key: str, default: str) -> str:
    return os.getenv(key, default)

def _env_int(key: str, default: int) -> int:
    val = os.getenv(key)
    return int(val) if val is not None else default

def _env_float(key: str, default: float) -> float:
    val = os.getenv(key)
    return float(val) if val is not None else default

def _env_path(key: str, default: str) -> Path:
    return Path(os.getenv(key, default))


TOPDIR = os.getenv("TOPDIR", ".")


# ══════════════════════════════════════════════════════════════════════════════
# MCP Server
# ══════════════════════════════════════════════════════════════════════════════

@dataclass(frozen=True)
class MCPServerConfig:
    """One MCP server process the agent can talk to."""
    label:   str        # human-readable name used in logs
    command: str        # executable (e.g. "python")
    args:    list[str]  # argv (e.g. ["server/mcp_server_terminal.py"])


# ══════════════════════════════════════════════════════════════════════════════
# LLM Provider
# ══════════════════════════════════════════════════════════════════════════════

@dataclass
class LLMConfig:
    """
    Which model and provider to use.

    The `provider` field selects the concrete client class in llm_client.py.
    The `base_url` field is used by Ollama and vLLM to point at the local server.
    All fields have environment variable overrides for K8s / Docker deployments.
    """
    provider:          str   = field(default_factory=lambda: _env_str("FAULTTRACE_PROVIDER", "openai"))
    model:             str   = field(default_factory=lambda: _env_str("FAULTTRACE_MODEL", "gpt-4o"))
    temperature:       float = field(default_factory=lambda: _env_float("FAULTTRACE_TEMPERATURE", 1.0))
    max_tokens:        int   = field(default_factory=lambda: _env_int("FAULTTRACE_MAX_TOKENS", 4096))
    max_retries:       int   = field(default_factory=lambda: _env_int("FAULTTRACE_MAX_RETRIES", 3))
    retry_base_delay:  float = field(default_factory=lambda: _env_float("FAULTTRACE_RETRY_BASE_DELAY", 5.0))

    # Optional custom endpoint — used by Ollama, vLLM, Azure OpenAI, etc.
    # Falls back to OLLAMA_BASE_URL / VLLM_BASE_URL inside the client itself.
    base_url:          str | None = field(
        default_factory=lambda: os.getenv("FAULTTRACE_BASE_URL") or None
    )

    # ── Convenience model presets per provider ─────────────────────────────────
    # These are the recommended default models. Override via env or CLI.
    PROVIDER_DEFAULT_MODELS: dict[str, str] = field(default_factory=lambda: {
        "openai":    "gpt-4o",
        "anthropic": "claude-opus-4-5",
        "gemini":    "gemini-1.5-pro",
        "ollama":    "llama3.1",
        "vllm":      "mistralai/Mistral-7B-Instruct-v0.2",
    }, repr=False, compare=False)

    def __post_init__(self) -> None:
        # If model is still the generic default but a provider-specific default
        # exists and no explicit FAULTTRACE_MODEL was set, apply the preset.
        if (
            os.getenv("FAULTTRACE_MODEL") is None
            and self.model == "gpt-4o"
            and self.provider != "openai"
        ):
            preset = self.PROVIDER_DEFAULT_MODELS.get(self.provider)
            if preset:
                self.model = preset


# ══════════════════════════════════════════════════════════════════════════════
# Loop
# ══════════════════════════════════════════════════════════════════════════════

@dataclass
class LoopConfig:
    """Controls how the agent loop runs and when it stops."""
    max_iterations:       int = field(default_factory=lambda: _env_int("FAULTTRACE_MAX_ITERATIONS", 50))
    max_idle_turns:       int = field(default_factory=lambda: _env_int("FAULTTRACE_MAX_IDLE_TURNS", 3))
    context_token_budget: int = field(default_factory=lambda: _env_int("FAULTTRACE_CONTEXT_BUDGET", 500_000))
    min_recent_pairs:     int = 8


# ══════════════════════════════════════════════════════════════════════════════
# Tools
# ══════════════════════════════════════════════════════════════════════════════

@dataclass
class ToolConfig:
    """Retry behaviour for individual MCP tool calls."""
    max_retries:  int   = 5
    retry_delay:  float = 1.5


# ══════════════════════════════════════════════════════════════════════════════
# Paths
# ══════════════════════════════════════════════════════════════════════════════

@dataclass
class PathConfig:
    prompts_dir:  Path = field(default_factory=lambda: _env_path("FAULTTRACE_PROMPTS_DIR", f"{TOPDIR}/prompts"))
    output_dir:   Path = field(default_factory=lambda: _env_path("FAULTTRACE_OUTPUT_DIR",  f"{TOPDIR}/output"))
    log_dir:      Path = field(default_factory=lambda: _env_path("FAULTTRACE_LOG_DIR",     f"{TOPDIR}/logs"))
    sessions_dir: Path = field(default_factory=lambda: _env_path("FAULTTRACE_SESSIONS_DIR",f"{TOPDIR}/sessions"))

    def ensure_dirs(self) -> None:
        for p in (self.output_dir, self.log_dir, self.sessions_dir):
            p.mkdir(parents=True, exist_ok=True)


# ══════════════════════════════════════════════════════════════════════════════
# Root config
# ══════════════════════════════════════════════════════════════════════════════

@dataclass
class AgentConfig:
    """
    Root configuration object.  Instantiate once in agent.py and pass around.
    All sub-configs read from environment variables automatically — no code
    changes needed when deploying to different environments.
    """
    llm:   LLMConfig  = field(default_factory=LLMConfig)
    loop:  LoopConfig = field(default_factory=LoopConfig)
    tools: ToolConfig = field(default_factory=ToolConfig)
    paths: PathConfig = field(default_factory=PathConfig)

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

    def summary(self) -> str:
        """Return a human-readable config summary for logging."""
        return (
            f"provider={self.llm.provider}  model={self.llm.model}  "
            f"base_url={self.llm.base_url or 'default'}  "
            f"max_iter={self.loop.max_iterations}  "
            f"context_budget={self.loop.context_token_budget:,}"
        )
