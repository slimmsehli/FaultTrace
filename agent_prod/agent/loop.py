"""
loop.py
───────
The agent loop — the brain of the RTL Debug Agent.

DESIGN PRINCIPLE
────────────────
This module knows NOTHING about:
  * How to call the LLM API            → that's llm_client.py
  * How to call MCP tools              → that's tool_executor.py
  * How to route to the right session  → that's mcp_manager.py
  * How to manage message history      → that's history.py
  * File paths, model names, retries   → that's config.py

The loop only orchestrates:
  1. Ask the LLM what to do next
  2. If it wants tools → execute them → feed results back → repeat
  3. If it's done → return the final output
  4. Keep track of metrics and know when to stop

TERMINATION LOGIC
─────────────────
The original code had a single `break` on the first no-tool-call turn,
which caused problems:
  - The model sometimes produces a short "I'll now summarise…" text turn
    before its actual final report, causing premature termination.
  - The `max_iterations` guard had no warning.

This version uses:
  * `idle_turns` counter — requires N consecutive text-only turns before
    declaring done (configurable via LoopConfig.max_idle_turns)
  * Explicit `LoopStatus` enum so callers know exactly why we stopped
  * Structured `LoopResult` with full metrics attached
"""

from __future__ import annotations

import time
from dataclasses import dataclass, field
from enum import Enum, auto

from config import LoopConfig, ToolConfig
from history import MessageHistory
from llm_client import BaseLLMClient, LLMResponse
from mcp_manager import MCPSessionPool
from tool_executor import execute_tool
from logger import get_logger

log = get_logger(__name__)


# ── Result types ───────────────────────────────────────────────────────────────

class LoopStatus(Enum):
    CONCLUDED     = auto()   # model finished cleanly
    MAX_ITER      = auto()   # hit the iteration ceiling
    ERROR         = auto()   # unrecoverable error during loop


@dataclass
class LoopMetrics:
    iterations:       int   = 0
    total_tool_calls: int   = 0
    failed_tool_calls: int  = 0
    elapsed_seconds:  float = 0.0


@dataclass
class LoopResult:
    status:       LoopStatus
    final_output: str           # last text the model produced (may be empty)
    metrics:      LoopMetrics
    error:        str = ""      # populated only when status == ERROR


# ── Agent loop ─────────────────────────────────────────────────────────────────

async def run_loop(
    *,
    history:     MessageHistory,
    llm:         BaseLLMClient,
    pool:        MCPSessionPool,
    loop_cfg:    LoopConfig,
    tool_cfg:    ToolConfig,
) -> LoopResult:
    """
    Execute the RTL debug agent loop until the model concludes,
    the iteration budget is exhausted, or an unrecoverable error occurs.

    Parameters
    ----------
    history:    Conversation history (manages its own context trimming).
    llm:        LLM client (handles API calls and retries).
    pool:       MCP session pool (handles tool routing).
    loop_cfg:   Loop control parameters (max iterations, idle turns, etc.).
    tool_cfg:   Tool execution parameters (retries, delay).

    Returns
    -------
    LoopResult with status, final text output, and run metrics.
    """
    metrics    = LoopMetrics()
    idle_turns = 0
    final_text = ""
    start_time = time.monotonic()

    log.info(
        "Agent loop starting (max_iterations=%d, max_idle_turns=%d).",
        loop_cfg.max_iterations, loop_cfg.max_idle_turns,
    )

    for iteration in range(1, loop_cfg.max_iterations + 1):
        metrics.iterations = iteration
        log.info("[iter %02d] Calling LLM (history depth: %d messages).", iteration, history.depth)

        # ── Step 1: call the LLM ───────────────────────────────────────────────
        try:
            response: LLMResponse = await llm.chat(
                messages=history.messages,   # automatically trimmed
                tools=pool.openai_tools,
            )
        except Exception as exc:
            log.exception("Unrecoverable LLM error at iteration %d.", iteration)
            metrics.elapsed_seconds = time.monotonic() - start_time
            return LoopResult(
                status=LoopStatus.ERROR,
                final_output=final_text,
                metrics=metrics,
                error=str(exc),
            )

        # ── Step 2: record the assistant turn ─────────────────────────────────
        history.append_assistant(response.raw_message)

        if response.text:
            log.info("[iter %02d] LLM: %s", iteration, _truncate(response.text, 300))

        # ── Step 3: check termination ──────────────────────────────────────────
        if response.is_final:
            final_text  = response.text
            idle_turns += 1
            log.info(
                "[iter %02d] No tool calls (idle_turns=%d/%d).",
                iteration, idle_turns, loop_cfg.max_idle_turns,
            )
            if idle_turns >= loop_cfg.max_idle_turns:
                log.info("Agent concluded cleanly after %d idle turn(s).", idle_turns)
                metrics.elapsed_seconds = time.monotonic() - start_time
                return LoopResult(
                    status=LoopStatus.CONCLUDED,
                    final_output=final_text,
                    metrics=metrics,
                )
            continue   # give the model one more turn to finish its thoughts

        # ── Step 4: reset idle counter and execute tools ───────────────────────
        idle_turns = 0

        log.info("[iter %02d] Model requested %d tool call(s).", iteration, len(response.tool_calls))

        for tool_req in response.tool_calls:
            metrics.total_tool_calls += 1

            # Route to the correct MCP session
            try:
                session = pool.session_for(tool_req.name)
            except KeyError as exc:
                # Model hallucinated a non-existent tool — feed error back
                log.warning("[iter %02d] Unknown tool requested: %s", iteration, tool_req.name)
                from tool_executor import ToolResult, result_to_message
                fake_result = ToolResult(
                    tool_call_id=tool_req.id,
                    tool_name=tool_req.name,
                    success=False,
                    content=f"[ERROR] {exc}",
                    error=str(exc),
                )
                history.append_tool_result(fake_result)
                metrics.failed_tool_calls += 1
                continue

            log.info("[iter %02d] → tool '%s' args=%s", iteration, tool_req.name, _truncate(tool_req.arguments, 200))

            # Execute with retry
            result = await execute_tool(
                session=session,
                request=tool_req,
                max_retries=tool_cfg.max_retries,
                retry_delay=tool_cfg.retry_delay,
            )

            if not result.success:
                metrics.failed_tool_calls += 1
                log.warning("[iter %02d] ✗ tool '%s' failed — error surfaced to model.", iteration, tool_req.name)
            else:
                log.debug("[iter %02d] ✓ tool '%s' OK (%d chars).", iteration, tool_req.name, len(result.content))

            # Append result to history — this is the ONLY place this happens
            history.append_tool_result(result)

    # ── Iteration budget exhausted ─────────────────────────────────────────────
    log.warning("Agent exhausted iteration budget (%d). Stopping.", loop_cfg.max_iterations)
    metrics.elapsed_seconds = time.monotonic() - start_time
    return LoopResult(
        status=LoopStatus.MAX_ITER,
        final_output=final_text,
        metrics=metrics,
    )


# ── Utilities ──────────────────────────────────────────────────────────────────

def _truncate(text: str, max_len: int) -> str:
    if len(text) <= max_len:
        return text
    return text[:max_len] + f"… [+{len(text) - max_len} chars]"
