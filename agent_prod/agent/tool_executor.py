"""
tool_executor.py
────────────────
Resilient MCP tool execution and message formatting.

TWO RESPONSIBILITIES
────────────────────
1. EXECUTION  — call a tool on the right MCP session with retry logic.
               Never raises — errors become a ToolResult with success=False.

2. FORMATTING — convert ToolResult objects into the exact dict format
               OpenAI expects for "tool" role messages.
               This keeps message-history concerns out of the agent loop.

WHY ERRORS BECOME RESULTS
──────────────────────────
If a tool fails and we raise an exception, the agent crashes and the user
gets nothing.  Instead, we surface the error back to the model as a tool
response.  The model can then decide whether to retry, try a different
approach, or report what it knows so far.  This is the correct agentic
behaviour.
"""

from __future__ import annotations

import asyncio
import json
import traceback
from dataclasses import dataclass

from mcp import ClientSession

from llm_client import ToolCallRequest
from logger import get_logger

log = get_logger(__name__)


# ── Result datatype ────────────────────────────────────────────────────────────

@dataclass(slots=True)
class ToolResult:
    """Outcome of one MCP tool call, success or failure."""
    tool_call_id: str
    tool_name:    str
    success:      bool
    content:      str   # text to feed back to the model
    error:        str = ""


# ── Execution ──────────────────────────────────────────────────────────────────

async def execute_tool(
    *,
    session:      ClientSession,
    request:      ToolCallRequest,
    max_retries:  int   = 3,
    retry_delay:  float = 1.5,
) -> ToolResult:
    """
    Call the tool described by *request* on *session*.

    Retries on exception with linear back-off (delay × attempt number).
    Always returns a `ToolResult` — never raises.

    Parameters
    ----------
    session:      The MCP ClientSession that owns this tool.
    request:      The ToolCallRequest from the LLM response.
    max_retries:  Total attempts before giving up.
    retry_delay:  Base delay in seconds between attempts.
    """
    # Parse arguments once — a JSON error here is not retryable
    try:
        args = json.loads(request.arguments) if request.arguments else {}
    except json.JSONDecodeError as exc:
        msg = f"[ARGUMENT ERROR] Could not parse tool arguments: {exc}\nRaw: {request.arguments}"
        log.error("Tool '%s': %s", request.name, msg)
        return ToolResult(
            tool_call_id=request.id,
            tool_name=request.name,
            success=False,
            content=msg,
            error=str(exc),
        )

    last_exc: Exception | None = None

    for attempt in range(1, max_retries + 1):
        try:
            log.debug("Calling tool '%s' (attempt %d/%d) args=%s", request.name, attempt, max_retries, args)

            result = await session.call_tool(request.name, args)

            # MCP returns a list of content blocks — flatten to text
            parts = []
            for block in result.content:
                parts.append(block.text if hasattr(block, "text") else str(block))

            content = "\n".join(parts) if parts else "(tool returned empty response)"
            log.debug("Tool '%s' OK (attempt %d). Response: %d chars.", request.name, attempt, len(content))

            return ToolResult(
                tool_call_id=request.id,
                tool_name=request.name,
                success=True,
                content=content,
            )

        except Exception as exc:
            last_exc = exc
            log.warning("Tool '%s' failed on attempt %d/%d: %s", request.name, attempt, max_retries, exc)
            if attempt < max_retries:
                await asyncio.sleep(retry_delay * attempt)

    # All attempts exhausted
    error_text = (
        f"[TOOL FAILED] '{request.name}' failed after {max_retries} attempt(s).\n"
        f"Error: {last_exc}\n"
        f"Traceback:\n{traceback.format_exc()}"
    )
    log.error(error_text)

    return ToolResult(
        tool_call_id=request.id,
        tool_name=request.name,
        success=False,
        content=error_text,
        error=str(last_exc),
    )


# ── Message formatting ─────────────────────────────────────────────────────────

def result_to_message(result: ToolResult) -> dict:
    """
    Convert a ToolResult into the dict that OpenAI expects for
    the "tool" role in the message history.

    This is the only place in the codebase that knows this format.
    The agent loop calls this and appends the returned dict — nothing else.
    """
    return {
        "role":         "tool",
        "tool_call_id": result.tool_call_id,
        "name":         result.tool_name,
        "content":      result.content,
    }
