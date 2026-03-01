"""
runner.py
─────────
AgentRunner — owns the full lifecycle of one RTL debug run.

WHY THIS EXISTS
───────────────
In the previous version, agent.py was doing two jobs at once:
  1. Being the CLI entry point  (parse args, set up logging, sys.exit)
  2. Being the run orchestrator (load prompts, wire modules, call loop)

Mixing these makes the agent untestable and impossible to call
programmatically — you cannot import a script that calls sys.exit().

This module contains AgentRunner, which owns job #2 entirely.
agent.py is now a pure 30-line entry point that only does job #1.

AgentRunner can be:
  * Called from the CLI via agent.py       (today)
  * Called from a FastAPI endpoint         (Phase 2 — REST API)
  * Called from a CI/CD trigger script     (Phase 2 — nightly regression)
  * Instantiated in a test                 (always)
  * Called with await runner.run()         (same call regardless of caller)

PUBLIC INTERFACE
────────────────
    runner = AgentRunner(cfg, run_id="my_run")
    result = await runner.run()
    # result.status, result.final_output, result.metrics all available
"""

from __future__ import annotations

import sys
from pathlib import Path

from config import AgentConfig
from history import MessageHistory
from llm_client import LLMClientFactory
from logger import get_logger
from loop import run_loop, LoopResult, LoopStatus
from mcp_manager import open_mcp_pool
from reporter import save_report, log_run_summary
from session_manager import SessionManager

log = get_logger(__name__)


class AgentRunner:
    """
    Owns one complete RTL debug agent run.

    Responsibilities
    ────────────────
    * Load prompts from disk
    * Start MCP server pool
    * Instantiate LLM client and message history
    * Drive the agent loop
    * Save report and summary
    * Return a structured LoopResult to the caller

    Does NOT
    ────────
    * Parse CLI arguments          → agent.py
    * Set up logging               → agent.py  (must be done before instantiation)
    * Call sys.exit()              → agent.py
    * Contain any retry logic      → llm_client.py / tool_executor.py
    * Contain any loop logic       → loop.py
    * Know about message formats   → history.py / tool_executor.py

    Parameters
    ──────────
    cfg:        Full AgentConfig (with any CLI overrides already applied).
    run_id:     Unique identifier for this run, used in filenames.
    """

    def __init__(self, cfg: AgentConfig, run_id: str) -> None:
        self.cfg    = cfg
        self.run_id = run_id

    # ── Public entry point ─────────────────────────────────────────────────────

    async def run(self) -> LoopResult:
        """
        Execute the full agent run end-to-end.

        Returns
        ───────
        LoopResult containing:
          .status         — CONCLUDED | MAX_ITER | ERROR
          .final_output   — the agent's final text/HTML
          .metrics        — iterations, tool calls, elapsed time
          .error          — populated only if status == ERROR

        Never raises — exceptions are caught, logged, and returned
        as a LoopResult with status=ERROR so callers always get a result.
        """
        log.info("AgentRunner.run() starting (run_id=%s, model=%s)", self.run_id, self.cfg.llm.model)

        # ── Step 1: load prompts ───────────────────────────────────────────────
        try:
            system_prompt, user_prompt = self._load_prompts()
        except SystemExit:
            raise   # let agent.py handle the exit cleanly
        except Exception as exc:
            log.error("Failed to load prompts: %s", exc)
            return self._error_result(str(exc))

        # ── Step 2: open MCP pool, build clients, run loop ────────────────────
        tool_catalogue_path = self.cfg.paths.log_dir / f"tools_{self.run_id}.log"
        history: MessageHistory | None = None   # keep reference for session save

        try:
            async with open_mcp_pool(self.cfg, tool_catalogue_path=tool_catalogue_path) as pool:

                llm = LLMClientFactory.create(self.cfg.llm)

                history = MessageHistory(
                    system_prompt=system_prompt,
                    user_prompt=user_prompt,
                    token_budget=self.cfg.loop.context_token_budget,
                    min_pairs=self.cfg.loop.min_recent_pairs,
                    llm_client=llm,   # enables provider-aware message formatting
                )

                result = await run_loop(
                    history=history,
                    llm=llm,
                    pool=pool,
                    loop_cfg=self.cfg.loop,
                    tool_cfg=self.cfg.tools,
                )

        except Exception as exc:
            log.exception("Unhandled exception during agent run.")
            return self._error_result(str(exc))

        # ── Step 3: log summary and save report ───────────────────────────────
        log_run_summary(result, run_id=self.run_id)

        report_path = None
        if result.final_output:
            report_path, summary_path = save_report(
                result=result,
                output_dir=self.cfg.paths.output_dir,
                run_id=self.run_id,
                model=self.cfg.llm.model,
            )
            log.info("Report  → %s", report_path)
            log.info("Summary → %s", summary_path)
        else:
            log.warning("Agent produced no final output — no report saved.")

        # ── Step 4: persist session (history + summary + report + index) ───────
        if history is not None:
            try:
                session_dir = SessionManager(self.cfg).save_session(
                    run_id=self.run_id,
                    result=result,
                    history=history,
                    report_path=report_path,
                    model=self.cfg.llm.model,
                )
                log.info("Session → %s", session_dir)
            except Exception as exc:
                # Session save failure must never abort the run
                log.warning("Session save failed (non-fatal): %s", exc)

        return result

    # ── Private helpers ────────────────────────────────────────────────────────

    def _load_prompts(self) -> tuple[str, str]:
        """
        Load system_prompt and user_prompt from the configured prompts directory.
        Prints clear errors and calls sys.exit(1) if either file is missing —
        this is a hard precondition failure, not a runtime error.
        """
        prompts_dir = self.cfg.paths.prompts_dir
        system_path = prompts_dir / "system_prompt"
        user_path   = prompts_dir / "user_prompt"

        missing = [p for p in (system_path, user_path) if not p.exists()]
        if missing:
            for p in missing:
                log.error("Prompt file not found: %s", p)
                print(f"[ERROR] Prompt file not found: {p}", file=sys.stderr)
            sys.exit(1)

        system = system_path.read_text(encoding="utf-8")
        user   = user_path.read_text(encoding="utf-8")

        log.info("Prompts loaded from '%s' (system: %d chars, user: %d chars).",
                 prompts_dir, len(system), len(user))
        return system, user

    @staticmethod
    def _error_result(error_msg: str) -> LoopResult:
        """Construct a LoopResult representing a hard failure before the loop ran."""
        from loop import LoopMetrics
        return LoopResult(
            status=LoopStatus.ERROR,
            final_output="",
            metrics=LoopMetrics(),
            error=error_msg,
        )
