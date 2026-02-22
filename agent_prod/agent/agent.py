"""
agent.py
────────
RTL Debug Agent — entry point. Nothing more.

This file has exactly four jobs and nothing else:
  1. Parse CLI arguments
  2. Apply overrides to config
  3. Set up logging
  4. Call AgentRunner.run() and exit with the right code

Every behaviour lives in a dedicated module:
  config.py        — all tunables
  runner.py        — full run lifecycle (load prompts → loop → save report)
  llm_client.py    — LLM API calls and retries
  mcp_manager.py   — MCP server startup and tool routing
  tool_executor.py — individual tool calls with retry
  history.py       — message history and context trimming
  loop.py          — the agent loop logic
  reporter.py      — saving reports and summaries
  logger.py        — logging setup

USAGE
─────
    python agent.py
    python agent.py --run-id nightly_042
    python agent.py --run-id ci_run_99 --model gpt-4o --max-iterations 30
    python agent.py --prompts-dir ../prompts_timing/ --run-id timing_debug
"""

from __future__ import annotations

import argparse
import asyncio
import sys
from datetime import datetime
from pathlib import Path

from dotenv import load_dotenv

# Load .env before any module reads the environment
load_dotenv()

from config import AgentConfig
from logger import setup_logging, get_logger
from loop import LoopStatus
from runner import AgentRunner


def _parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="RTL Debug Agent — LLM-powered simulation failure analysis.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    parser.add_argument(
        "--run-id",
        default=datetime.utcnow().strftime("%Y%m%d_%H%M%S"),
        metavar="ID",
        help="Unique name for this run. Used in all output and log filenames.",
    )
    parser.add_argument(
        "--model",
        default=None,
        metavar="NAME",
        help="Override LLM model from config.py (e.g. gpt-4o, gpt-4o-mini).",
    )
    parser.add_argument(
        "--max-iterations",
        type=int,
        default=None,
        metavar="N",
        help="Override loop.max_iterations from config.py.",
    )
    parser.add_argument(
        "--prompts-dir",
        type=Path,
        default=None,
        metavar="PATH",
        help="Override paths.prompts_dir from config.py.",
    )
    return parser.parse_args()


async def _run(args: argparse.Namespace) -> int:
    """Wire config, boot logging, delegate everything to AgentRunner."""

    # ── 1. Build config and apply CLI overrides ────────────────────────────────
    cfg = AgentConfig()
    if args.model:
        cfg.llm.model = args.model
    if args.max_iterations:
        cfg.loop.max_iterations = args.max_iterations
    if args.prompts_dir:
        cfg.paths.prompts_dir = args.prompts_dir

    # ── 2. Boot logging (must happen before any log.* calls) ──────────────────
    setup_logging(log_dir=cfg.paths.log_dir, run_id=args.run_id)
    log = get_logger(__name__)

    log.info("═══════════════════════════════════════════════")
    log.info("  RTL Debug Agent")
    log.info("  run_id  : %s", args.run_id)
    log.info("  model   : %s", cfg.llm.model)
    log.info("  prompts : %s", cfg.paths.prompts_dir)
    log.info("  output  : %s", cfg.paths.output_dir)
    log.info("═══════════════════════════════════════════════")

    # ── 3. Run ─────────────────────────────────────────────────────────────────
    result = await AgentRunner(cfg=cfg, run_id=args.run_id).run()

    # ── 4. Exit code ───────────────────────────────────────────────────────────
    if result.status == LoopStatus.ERROR:
        log.error("Run failed: %s", result.error)
        return 1

    if not result.final_output:
        log.warning("Run completed but agent produced no output.")
        return 2

    return 0   # CONCLUDED or MAX_ITER — report was saved by AgentRunner


if __name__ == "__main__":
    args = _parse_args()
    try:
        exit_code = asyncio.run(_run(args))
    except KeyboardInterrupt:
        print("\n[INTERRUPTED]", file=sys.stderr)
        sys.exit(0)
    sys.exit(exit_code)
