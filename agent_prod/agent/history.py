"""
history.py
──────────
Message history management for the RTL Debug Agent.

RESPONSIBILITIES
────────────────
1. BUILD     — construct the initial message list from system + user prompts
2. APPEND    — add assistant turns and tool results in the correct format
3. TRIM      — sliding-window context management so we never overflow the LLM
4. SERIALISE — convert history to/from JSON for persistence (Phase 2)

WHY A DEDICATED MODULE
───────────────────────
In the original code, message list manipulation was scattered across the
loop body: appending raw SDK objects, manually constructing tool dicts,
and never trimming.  Putting all history operations here means:

  * The loop just calls `history.append_*(...)` — no format knowledge needed
  * Trimming happens automatically on every read via `history.messages`
  * The format of "tool" and "assistant" messages is defined in exactly one place
  * Persistence (Phase 2) is a clean add-on with no loop changes

TOKEN ESTIMATION
────────────────
We use a character-based heuristic (~4 chars ≈ 1 token) rather than
importing tiktoken.  This avoids a hard dependency and is accurate enough
for budget management — we're protecting against 10× overruns, not
optimising for 1% accuracy.
"""

from __future__ import annotations

import json
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

from openai.types.chat import ChatCompletionMessage

from tool_executor import ToolResult, result_to_message
from logger import get_logger

log = get_logger(__name__)


# ── Token estimation ───────────────────────────────────────────────────────────

def _estimate_tokens(obj: Any) -> int:
    """Rough token count for any serialisable object (~4 chars = 1 token)."""
    if isinstance(obj, str):
        return max(1, len(obj) // 4)
    if isinstance(obj, (dict, list)):
        return _estimate_tokens(json.dumps(obj))
    return 1


def _message_tokens(msg: dict) -> int:
    content     = msg.get("content") or ""
    tool_calls  = msg.get("tool_calls") or []
    return _estimate_tokens(content) + _estimate_tokens(tool_calls) + 8  # role overhead


# ── History ────────────────────────────────────────────────────────────────────

class MessageHistory:
    """
    Manages the conversation history for one agent run.

    The `messages` property always returns a trimmed snapshot — the loop
    never has to think about context length.
    """

    def __init__(
        self,
        system_prompt: str,
        user_prompt:   str,
        token_budget:  int = 100_000,
        min_pairs:     int = 6,
    ) -> None:
        self._token_budget = token_budget
        self._min_pairs    = min_pairs
        self._raw: list[dict] = [
            {"role": "system", "content": system_prompt},
            {"role": "user",   "content": user_prompt},
        ]
        log.debug(
            "MessageHistory initialised (budget=%d tokens, min_pairs=%d).",
            token_budget, min_pairs,
        )

    # ── Append operations ──────────────────────────────────────────────────────

    def append_assistant(self, raw_message: ChatCompletionMessage) -> None:
        """
        Append the assistant's raw response message.
        We call `.model_dump()` to convert the SDK object to a plain dict.
        `exclude_unset=True` strips None fields the API dislikes on echo.
        """
        self._raw.append(raw_message.model_dump(exclude_unset=True))

    def append_tool_result(self, result: ToolResult) -> None:
        """Append one tool result in the format OpenAI expects."""
        self._raw.append(result_to_message(result))

    # ── Read with automatic trimming ───────────────────────────────────────────

    @property
    def messages(self) -> list[dict]:
        """
        Return the current history, trimmed to fit within the token budget.
        The system prompt is always kept.  Oldest tool-exchange pairs are
        dropped first.
        """
        return self._trim(self._raw)

    @property
    def raw_messages(self) -> list[dict]:
        """Full un-trimmed history (for persistence/debugging)."""
        return list(self._raw)

    @property
    def depth(self) -> int:
        return len(self._raw)

    # ── Trimming logic ─────────────────────────────────────────────────────────

    def _trim(self, messages: list[dict]) -> list[dict]:
        """
        Return a trimmed copy of *messages*.

        Strategy
        ────────
        1. Always keep messages[0] (system prompt).
        2. Group the rest into logical "exchange groups":
             - An assistant message with tool_calls + all its tool responses = one group
             - Any other message = its own group
        3. Drop the oldest groups until we fit within the token budget,
           but always keep at least `_min_pairs` groups.
        """
        if not messages:
            return messages

        total_tokens = sum(_message_tokens(m) for m in messages)
        if total_tokens <= self._token_budget:
            return messages

        system  = messages[:1]
        rest    = messages[1:]
        groups  = _group_messages(rest)

        dropped_count  = 0
        dropped_tokens = 0

        while len(groups) > self._min_pairs and total_tokens > self._token_budget:
            oldest        = groups.pop(0)
            group_tokens  = sum(_message_tokens(m) for m in oldest)
            total_tokens -= group_tokens
            dropped_tokens += group_tokens
            dropped_count  += 1

        if dropped_count:
            log.warning(
                "Context trim: dropped %d group(s) (~%d tokens). "
                "Remaining groups: %d. Estimated total: %d tokens.",
                dropped_count, dropped_tokens, len(groups), total_tokens,
            )

        return system + [msg for group in groups for msg in group]

    # ── Persistence (Phase 2 hook) ─────────────────────────────────────────────

    def to_json(self) -> str:
        """Serialise full history to JSON string."""
        return json.dumps(self._raw, ensure_ascii=False, indent=2)

    def save(self, path: Path) -> None:
        """Write full history to *path* as JSON."""
        path.write_text(self.to_json(), encoding="utf-8")
        log.debug("History saved → %s (%d messages).", path, len(self._raw))

    @classmethod
    def load(cls, path: Path, token_budget: int, min_pairs: int) -> "MessageHistory":
        """Restore a history from a previously saved JSON file."""
        raw = json.loads(path.read_text(encoding="utf-8"))
        instance = cls.__new__(cls)
        instance._token_budget = token_budget
        instance._min_pairs    = min_pairs
        instance._raw          = raw
        log.info("History loaded ← %s (%d messages).", path, len(raw))
        return instance


# ── Helpers ────────────────────────────────────────────────────────────────────

def _group_messages(messages: list[dict]) -> list[list[dict]]:
    """
    Group a flat message list into logical exchange groups.

    An "assistant with tool calls" message and all its subsequent "tool"
    role responses form one group.  Everything else is a group of one.
    """
    groups: list[list[dict]] = []
    i = 0
    while i < len(messages):
        msg = messages[i]
        if msg.get("role") == "assistant" and msg.get("tool_calls"):
            # Collect the assistant message + all following tool results
            group = [msg]
            i += 1
            while i < len(messages) and messages[i].get("role") == "tool":
                group.append(messages[i])
                i += 1
            groups.append(group)
        else:
            groups.append([msg])
            i += 1
    return groups
