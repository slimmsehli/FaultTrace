"""
reporter.py
───────────
Saves the agent's final output and writes a structured run summary.

OUTPUTS
───────
* <output_dir>/report_<run_id>.html  or  .txt   — the agent's final analysis
* <output_dir>/summary_<run_id>.json            — machine-readable run metadata

The summary JSON is the hook for Phase 2 session persistence and the
CI/CD integration layer — a regression pipeline can parse it to know
whether the debug run succeeded and where the report lives.
"""

from __future__ import annotations

import json
from datetime import datetime, timezone
from pathlib import Path

from loop import LoopResult, LoopStatus
from logger import get_logger

log = get_logger(__name__)


def save_report(
    result:     LoopResult,
    output_dir: Path,
    run_id:     str,
    model:      str,
) -> tuple[Path, Path]:
    """
    Persist the agent's output to disk.

    Returns
    -------
    (report_path, summary_path)   — both absolute Paths.
    """
    output_dir.mkdir(parents=True, exist_ok=True)

    report_path  = _write_report(result.final_output, output_dir, run_id)
    summary_path = _write_summary(result, output_dir, run_id, model, report_path)

    return report_path, summary_path


# ── Report ─────────────────────────────────────────────────────────────────────

def _write_report(content: str, output_dir: Path, run_id: str) -> Path:
    """Auto-detect HTML vs plain text and write with the right extension."""
    is_html = content.strip().lower().startswith("<!doctype") or "<html" in content[:300].lower()
    ext     = ".html" if is_html else ".txt"
    path    = output_dir / f"report_{run_id}{ext}"

    path.write_text(content, encoding="utf-8")
    log.info("Report saved → %s", path)
    return path


# ── Summary ────────────────────────────────────────────────────────────────────

def _write_summary(
    result:      LoopResult,
    output_dir:  Path,
    run_id:      str,
    model:       str,
    report_path: Path,
) -> Path:
    """Write a machine-readable JSON summary of the run."""
    m = result.metrics
    summary = {
        "run_id":           run_id,
        "timestamp_utc":    datetime.now(timezone.utc).isoformat(),
        "model":            model,
        "status":           result.status.name,
        "iterations":       m.iterations,
        "total_tool_calls": m.total_tool_calls,
        "failed_tool_calls":m.failed_tool_calls,
        "elapsed_seconds":  round(m.elapsed_seconds, 2),
        "report_path":      str(report_path.resolve()),
        "error":            result.error or None,
    }

    path = output_dir / f"summary_{run_id}.json"
    path.write_text(json.dumps(summary, indent=2), encoding="utf-8")
    log.info("Run summary → %s", path)
    return path


def log_run_summary(result: LoopResult, run_id: str) -> None:
    """Print a clean human-readable summary to the log."""
    m = result.metrics
    status_icon = {"CONCLUDED": "✓", "MAX_ITER": "⚠", "ERROR": "✗"}.get(result.status.name, "?")
    log.info(
        "══════════════════════════════════════════════\n"
        "  Run ID  : %s\n"
        "  Status  : %s %s\n"
        "  Iters   : %d\n"
        "  Tools   : %d called, %d failed\n"
        "  Elapsed : %.1fs\n"
        "══════════════════════════════════════════════",
        run_id,
        status_icon, result.status.name,
        m.iterations,
        m.total_tool_calls, m.failed_tool_calls,
        m.elapsed_seconds,
    )
