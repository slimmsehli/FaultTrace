"""
logger.py
─────────
Logging infrastructure for the RTL Debug Agent.

Call `setup_logging(log_dir, run_id)` exactly once at process startup.
Every other module then just does:

    from logger import get_logger
    log = get_logger(__name__)
"""

from __future__ import annotations

import logging
import sys
from pathlib import Path


_LOG_FMT = "%(asctime)s | %(levelname)-8s | %(name)-30s | %(message)s"
_DATE_FMT = "%Y-%m-%dT%H:%M:%S"

# Libraries that spam at DEBUG/INFO level
_QUIET_LOGGERS = ("httpx", "httpcore", "openai", "asyncio")


def setup_logging(log_dir: Path, run_id: str, console_level: int = logging.INFO) -> None:
    """
    Configure the root logger.  Must be called once before any log messages.

    Outputs
    -------
    * Per-run file  →  <log_dir>/run_<run_id>.log  (DEBUG and above)
    * stderr stream →  INFO and above (or whatever console_level is set to)
    """
    log_dir.mkdir(parents=True, exist_ok=True)
    log_file = log_dir / f"run_{run_id}.log"

    fmt = logging.Formatter(fmt=_LOG_FMT, datefmt=_DATE_FMT)

    root = logging.getLogger()
    root.setLevel(logging.DEBUG)

    # File handler — full detail, one file per run
    fh = logging.FileHandler(log_file, encoding="utf-8")
    fh.setLevel(logging.DEBUG)
    fh.setFormatter(fmt)
    root.addHandler(fh)

    # Stream handler — clean INFO output to stderr
    sh = logging.StreamHandler(sys.stderr)
    sh.setLevel(console_level)
    sh.setFormatter(fmt)
    root.addHandler(sh)

    # Silence noisy third-party libraries
    for name in _QUIET_LOGGERS:
        logging.getLogger(name).setLevel(logging.WARNING)

    logging.getLogger(__name__).info("Logging initialised → %s", log_file)


def get_logger(name: str) -> logging.Logger:
    """Return a named logger.  Use `__name__` as the convention."""
    return logging.getLogger(name)
