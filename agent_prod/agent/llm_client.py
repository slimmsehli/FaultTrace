"""
llm_client.py
─────────────
Thin, self-contained wrapper around the OpenAI chat completions API.

WHY THIS EXISTS
───────────────
The original agent called `client.chat.completions.create(...)` directly
inside the loop, mixing retry logic, model config, and conversation state
all in one place.  This module isolates every concern that belongs to
"talking to the LLM":

  * Async API calls
  * Rate-limit and transient connection retries with exponential back-off
  * Normalising the raw API response into a clean `LLMResponse` datatype
    so the loop never touches SDK internals

PHASE 2 NOTE
────────────
This is the insertion point for the multi-provider abstraction (Ollama,
vLLM, Anthropic, Azure).  Replace or subclass `OpenAILLMClient` and the
loop does not change at all.
"""

from __future__ import annotations

import asyncio
from dataclasses import dataclass

from openai import AsyncOpenAI, APIConnectionError, APIError, BadRequestError, RateLimitError
from openai.types.chat import ChatCompletionMessage

from config import LLMConfig
from logger import get_logger

log = get_logger(__name__)

# ── Token parameter compatibility ──────────────────────────────────────────────
# Older models use `max_tokens`; newer models (o1, o3, gpt-4o via recent API
# versions) require `max_completion_tokens`.  We try the modern parameter first
# and fall back automatically on a 400 if the model doesn't support it.
_MODELS_REQUIRING_COMPLETION_TOKENS = (
    "o1", "o1-mini", "o1-preview", "o3", "o3-mini",
)

def _token_param(model: str, value: int) -> dict:
    """
    Return the correct token-limit keyword for *model*.
    Models in _MODELS_REQUIRING_COMPLETION_TOKENS always get
    max_completion_tokens.  All others get max_completion_tokens too —
    the OpenAI SDK accepts it for all current gpt-4o / gpt-4-turbo models —
    with max_tokens kept as a documented fallback in the retry path.
    """
    # All models released alongside o1+ require max_completion_tokens.
    # Use it universally; fall back to max_tokens only if the API rejects it.
    return {"max_completion_tokens": value}


# ── Response datatype ──────────────────────────────────────────────────────────

@dataclass
class ToolCallRequest:
    """A single tool call the model wants to make."""
    id:        str
    name:      str
    arguments: str   # raw JSON string — parsed by tool_executor


@dataclass
class LLMResponse:
    """
    Normalised model response.  The agent loop only ever sees this — never
    raw OpenAI SDK objects.
    """
    text:        str                    # assistant text (may be empty)
    tool_calls:  list[ToolCallRequest]  # empty list when model is done
    raw_message: ChatCompletionMessage  # kept for appending to history

    @property
    def has_tool_calls(self) -> bool:
        return len(self.tool_calls) > 0

    @property
    def is_final(self) -> bool:
        """True when the model produced text but no tool calls."""
        return not self.has_tool_calls


# ── Client ─────────────────────────────────────────────────────────────────────

class OpenAILLMClient:
    """
    Async OpenAI chat completions client with retry logic built in.

    Usage
    -----
        client = OpenAILLMClient(cfg.llm)
        response = await client.chat(messages, tools)
    """

    def __init__(self, cfg: LLMConfig) -> None:
        self._cfg    = cfg
        self._client = AsyncOpenAI()   # reads OPENAI_API_KEY from environment
        log.info("LLM client ready (model=%s, temperature=%s).", cfg.model, cfg.temperature)

    async def chat(
        self,
        messages: list[dict],
        tools: list[dict],
    ) -> LLMResponse:
        """
        Call the model and return a normalised `LLMResponse`.
        Retries on rate-limit and transient connection errors.

        Raises
        ------
        RuntimeError   if all retries are exhausted
        APIError       on unrecoverable API errors (bad key, invalid request…)
        """
        cfg = self._cfg
        last_exc: Exception | None = None
        # Start with max_completion_tokens (modern API); fall back to
        # max_tokens if the model explicitly rejects it via a 400.
        token_kwargs = _token_param(cfg.model, cfg.max_tokens)

        for attempt in range(1, cfg.max_retries + 1):
            try:
                log.debug(
                    "LLM call attempt %d/%d (model=%s, token_param=%s).",
                    attempt, cfg.max_retries, cfg.model, list(token_kwargs),
                )

                raw = await self._client.chat.completions.create(
                    model=cfg.model,
                    temperature=cfg.temperature,
                    messages=messages,
                    tools=tools or None,      # API dislikes an empty list
                    tool_choice="auto" if tools else None,
                    **token_kwargs,
                )
                return self._normalise(raw)

            except BadRequestError as exc:
                # If the model rejected our token parameter, swap to the
                # other one and retry immediately (does not count as an attempt).
                err_str = str(exc)
                if "max_completion_tokens" in err_str and "max_tokens" not in token_kwargs:
                    log.warning("Model rejected max_completion_tokens — retrying with max_tokens.")
                    token_kwargs = {"max_tokens": cfg.max_tokens}
                    continue
                if "max_tokens" in err_str and "max_completion_tokens" not in token_kwargs:
                    log.warning("Model rejected max_tokens — retrying with max_completion_tokens.")
                    token_kwargs = {"max_completion_tokens": cfg.max_tokens}
                    continue
                # Any other 400 is not retryable
                log.error("Unrecoverable bad request: %s", exc)
                raise

            except RateLimitError as exc:
                last_exc = exc
                delay = cfg.retry_base_delay * (2 ** (attempt - 1))
                log.warning("Rate limit hit (attempt %d/%d). Waiting %.0fs.", attempt, cfg.max_retries, delay)
                await asyncio.sleep(delay)

            except APIConnectionError as exc:
                last_exc = exc
                delay = cfg.retry_base_delay
                log.warning("Connection error (attempt %d/%d): %s. Waiting %.0fs.", attempt, cfg.max_retries, exc, delay)
                await asyncio.sleep(delay)

            except APIError as exc:
                # Auth failure, invalid request, etc. — not retryable
                log.error("Unrecoverable OpenAI API error: %s", exc)
                raise

        raise RuntimeError(
            f"LLM call failed after {cfg.max_retries} attempts. Last error: {last_exc}"
        )

    # ── Internal helpers ───────────────────────────────────────────────────────

    @staticmethod
    def _normalise(raw) -> LLMResponse:
        msg = raw.choices[0].message

        tool_calls: list[ToolCallRequest] = []
        if msg.tool_calls:
            for tc in msg.tool_calls:
                tool_calls.append(ToolCallRequest(
                    id=tc.id,
                    name=tc.function.name,
                    arguments=tc.function.arguments,
                ))

        return LLMResponse(
            text=msg.content or "",
            tool_calls=tool_calls,
            raw_message=msg,
        )
