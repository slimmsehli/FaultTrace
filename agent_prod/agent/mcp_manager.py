"""
mcp_manager.py
──────────────
MCP server lifecycle management and tool registry.

THE PROBLEM WITH THE ORIGINAL
──────────────────────────────
The original code nested `async with stdio_client(...) as ..., stdio_client(...) as ...`
directly in the main function.  That approach:

  * Hard-codes the number of servers (you can't loop over them)
  * Makes the nesting exponentially deeper as you add servers
  * Mixes server startup with business logic
  * Has no duplicate-tool detection

THIS SOLUTION
─────────────
`MCPSessionPool` manages N servers by entering each context manager
programmatically via `contextlib.AsyncExitStack`.  The stack guarantees
all servers are shut down cleanly on exit regardless of exceptions.

RESPONSIBILITIES
────────────────
1. Start all configured MCP server processes
2. Initialise each ClientSession and collect its tools
3. Build a unified tool registry with duplicate detection
4. Provide `session_for(tool_name)` routing to the agent loop
5. Convert MCP tool schemas → OpenAI function-calling format
6. Dump a full tool catalogue to disk for auditability
"""

from __future__ import annotations

import json
from contextlib import asynccontextmanager, AsyncExitStack
from pathlib import Path
from typing import AsyncIterator

from mcp import ClientSession, StdioServerParameters
from mcp.client.stdio import stdio_client

from config import AgentConfig, MCPServerConfig
from logger import get_logger

log = get_logger(__name__)


# ── Session pool ───────────────────────────────────────────────────────────────

class MCPSessionPool:
    """
    A live pool of MCP sessions with a unified tool registry.

    Do not instantiate directly — use the `open_mcp_pool` context manager
    which handles startup and teardown.
    """

    def __init__(self) -> None:
        self._tool_to_session: dict[str, ClientSession] = {}
        self._openai_tools: list[dict] = []

    # ── Public API ─────────────────────────────────────────────────────────────

    @property
    def openai_tools(self) -> list[dict]:
        """All registered tools in OpenAI function-calling schema format."""
        return self._openai_tools

    @property
    def tool_count(self) -> int:
        return len(self._openai_tools)

    def session_for(self, tool_name: str) -> ClientSession:
        """
        Return the MCP session that owns *tool_name*.

        Raises
        ------
        KeyError   if the tool was never registered (bad model hallucination)
        """
        try:
            return self._tool_to_session[tool_name]
        except KeyError:
            available = sorted(self._tool_to_session.keys())
            raise KeyError(
                f"Tool '{tool_name}' not found in registry. "
                f"Available tools: {available}"
            )

    # ── Internal registration ──────────────────────────────────────────────────

    async def _register(self, label: str, session: ClientSession) -> None:
        """Initialise *session* and register all its tools."""
        await session.initialize()
        result  = await session.list_tools()
        added   = 0
        skipped = 0

        for tool in result.tools:
            if tool.name in self._tool_to_session:
                log.warning(
                    "Tool '%s' from server '%s' already registered — skipping duplicate.",
                    tool.name, label,
                )
                skipped += 1
                continue

            self._tool_to_session[tool.name] = session
            self._openai_tools.append({
                "type": "function",
                "function": {
                    "name":        tool.name,
                    "description": tool.description,
                    "parameters":  tool.inputSchema,
                },
            })
            added += 1

        log.info(
            "MCP server '%s' → %d tool(s) registered, %d duplicate(s) skipped.",
            label, added, skipped,
        )


# ── Context manager ────────────────────────────────────────────────────────────

@asynccontextmanager
async def open_mcp_pool(
    cfg: AgentConfig,
    tool_catalogue_path: Path | None = None,
) -> AsyncIterator[MCPSessionPool]:
    """
    Async context manager that starts all MCP servers, builds the session
    pool, and shuts everything down cleanly on exit.

    Uses `AsyncExitStack` so the number of servers is fully dynamic —
    no more fixed nesting depth.

    Usage
    -----
        async with open_mcp_pool(cfg, tool_catalogue_path) as pool:
            tools = pool.openai_tools
            session = pool.session_for("read_log")
    """
    pool = MCPSessionPool()

    async with AsyncExitStack() as stack:
        for srv_cfg in cfg.mcp_servers:
            log.info("Starting MCP server '%s' (%s %s)…", srv_cfg.label, srv_cfg.command, srv_cfg.args)

            params = StdioServerParameters(command=srv_cfg.command, args=srv_cfg.args)

            # Enter the stdio transport context
            read, write = await stack.enter_async_context(stdio_client(params))

            # Enter the session context
            session: ClientSession = await stack.enter_async_context(ClientSession(read, write))

            # Register all tools from this server
            await pool._register(srv_cfg.label, session)

        log.info("MCP pool ready — %d tool(s) total across %d server(s).",
                 pool.tool_count, len(cfg.mcp_servers))

        if tool_catalogue_path:
            _write_tool_catalogue(pool, tool_catalogue_path)

        yield pool
        # AsyncExitStack tears down all sessions and transports here


# ── Tool catalogue dump ────────────────────────────────────────────────────────

def _write_tool_catalogue(pool: MCPSessionPool, path: Path) -> None:
    """Write a human-readable tool inventory to *path* for audit/debug."""
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", encoding="utf-8") as fh:
        fh.write(f"Total tools: {pool.tool_count}\n")
        fh.write("=" * 60 + "\n")
        for entry in pool.openai_tools:
            fn = entry["function"]
            fh.write(f"\n[{fn['name']}]\n")
            fh.write(f"Description : {fn['description']}\n")
            fh.write(f"Parameters  :\n{json.dumps(fn['parameters'], indent=2)}\n")
            fh.write("-" * 60 + "\n")
    log.info("Tool catalogue written → %s", path)
