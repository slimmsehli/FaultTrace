"""
llm_client.py
─────────────
Multi-provider LLM abstraction for the RTL Debug Agent.

ARCHITECTURE
────────────
                         ┌─────────────────────┐
                         │    BaseLLMClient     │  ← loop.py only sees this
                         │  chat(messages,tools)│
                         └──────────┬──────────┘
               ┌───────────┬────────┴────────┬──────────────┐
               ▼           ▼                 ▼              ▼
        OpenAIClient  AnthropicClient  GeminiClient   OllamaClient
                                                       vLLMClient
                                                    (OpenAI-compatible)

TOOL CALL FORMAT DIFFERENCES
────────────────────────────
  OpenAI / Ollama / vLLM  →  OpenAI function-calling schema (loop native)
  Anthropic                →  converted to/from Anthropic tool_use blocks
  Gemini                   →  converted to/from Gemini function_declarations

All conversions are fully hidden inside each client.  The agent loop,
history, and tool_executor see ONLY LLMResponse and ToolCallRequest.

PROVIDER SELECTION
──────────────────
Use LLMClientFactory.create(cfg) — it reads cfg.llm.provider and returns
the right concrete client.  Nothing else in the codebase needs to change
when you add a new provider.

ENVIRONMENT VARIABLES
─────────────────────
  OPENAI_API_KEY        — OpenAI
  ANTHROPIC_API_KEY     — Anthropic / Claude
  GOOGLE_API_KEY        — Google Gemini
  OLLAMA_BASE_URL       — Ollama server  (default: http://localhost:11434)
  VLLM_BASE_URL         — vLLM server    (default: http://localhost:8000)
  VLLM_API_KEY          — vLLM API key   (optional, default: "token-abc123")
"""

from __future__ import annotations

import asyncio
import json
from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import Any

from config import LLMConfig
from logger import get_logger

log = get_logger(__name__)


# ══════════════════════════════════════════════════════════════════════════════
# Shared response types  (loop.py / tool_executor.py import these)
# ══════════════════════════════════════════════════════════════════════════════

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
    raw SDK objects from any provider.
    """
    text:        str                    # assistant text (may be empty)
    tool_calls:  list[ToolCallRequest]  # empty list when the model is done
    raw_message: Any                    # provider-specific; kept for history

    @property
    def has_tool_calls(self) -> bool:
        return len(self.tool_calls) > 0

    @property
    def is_final(self) -> bool:
        """True when the model produced text but no tool calls."""
        return not self.has_tool_calls


# ══════════════════════════════════════════════════════════════════════════════
# Abstract base
# ══════════════════════════════════════════════════════════════════════════════

class BaseLLMClient(ABC):
    """
    Abstract base for all provider clients.

    Subclasses must implement:
      chat(messages, tools) -> LLMResponse
      format_history_message(raw_message) -> dict   (for history.append_assistant)
    """

    @abstractmethod
    async def chat(
        self,
        messages: list[dict],
        tools: list[dict],
    ) -> LLMResponse:
        """Call the model and return a normalised LLMResponse."""
        ...

    @abstractmethod
    def format_history_message(self, raw_message: Any) -> dict:
        """
        Convert the provider-specific raw_message stored in LLMResponse
        into the dict format that MessageHistory._raw expects.

        For OpenAI-compatible providers this is just model_dump().
        For Anthropic/Gemini it translates to an OpenAI-style dict so the
        history stays in one canonical format throughout.
        """
        ...


# ══════════════════════════════════════════════════════════════════════════════
# OpenAI  (and OpenAI-compatible: vLLM, LM Studio, etc.)
# ══════════════════════════════════════════════════════════════════════════════

class OpenAIClient(BaseLLMClient):
    """
    OpenAI chat completions.
    Also used as the base for vLLM (which is OpenAI API-compatible).
    """

    def __init__(self, cfg: LLMConfig, *, base_url: str | None = None, api_key: str | None = None) -> None:
        import os
        from openai import AsyncOpenAI

        self._cfg = cfg
        key = api_key or os.getenv("OPENAI_API_KEY")
        self._client = AsyncOpenAI(api_key=key, base_url=base_url)
        log.info(
            "OpenAI client ready (model=%s, base_url=%s).",
            cfg.model, base_url or "default",
        )

    async def chat(self, messages: list[dict], tools: list[dict]) -> LLMResponse:
        cfg = self._cfg
        token_kwargs: dict = {"max_completion_tokens": cfg.max_tokens}
        last_exc: Exception | None = None

        for attempt in range(1, cfg.max_retries + 1):
            try:
                log.debug("OpenAI call attempt %d/%d (model=%s).", attempt, cfg.max_retries, cfg.model)

                raw = await self._client.chat.completions.create(
                    model=cfg.model,
                    temperature=cfg.temperature,
                    messages=messages,
                    tools=tools or None,
                    tool_choice="auto" if tools else None,
                    **token_kwargs,
                )
                return self._normalise(raw)

            except Exception as exc:
                from openai import BadRequestError, RateLimitError, APIConnectionError

                if isinstance(exc, BadRequestError):
                    err = str(exc)
                    if "max_completion_tokens" in err and "max_tokens" not in token_kwargs:
                        log.warning("Switching to max_tokens for this model.")
                        token_kwargs = {"max_tokens": cfg.max_tokens}
                        continue
                    if "max_tokens" in err and "max_completion_tokens" not in token_kwargs:
                        token_kwargs = {"max_completion_tokens": cfg.max_tokens}
                        continue
                    raise

                if isinstance(exc, (RateLimitError, APIConnectionError)):
                    last_exc = exc
                    delay = cfg.retry_base_delay * (2 ** (attempt - 1))
                    log.warning(
                        "Transient error (attempt %d/%d), waiting %.0fs: %s",
                        attempt, cfg.max_retries, delay, exc,
                    )
                    await asyncio.sleep(delay)
                    continue

                raise   # auth failures, bad requests — not retryable

        raise RuntimeError(
            f"LLM call failed after {cfg.max_retries} attempts. Last: {last_exc}"
        )

    def format_history_message(self, raw_message: Any) -> dict:
        return raw_message.model_dump(exclude_unset=True)

    @staticmethod
    def _normalise(raw: Any) -> LLMResponse:
        msg = raw.choices[0].message
        tool_calls = []
        if msg.tool_calls:
            for tc in msg.tool_calls:
                tool_calls.append(ToolCallRequest(
                    id=tc.id,
                    name=tc.function.name,
                    arguments=tc.function.arguments,
                ))
        return LLMResponse(text=msg.content or "", tool_calls=tool_calls, raw_message=msg)


# ══════════════════════════════════════════════════════════════════════════════
# vLLM  (OpenAI-compatible endpoint, different defaults)
# ══════════════════════════════════════════════════════════════════════════════

class VLLMClient(OpenAIClient):
    """
    vLLM server running locally or on-prem.

    vLLM exposes an OpenAI-compatible API, so we reuse OpenAIClient
    with a custom base_url and api_key.

    Config:
      llm.provider   = "vllm"
      llm.model      = "mistralai/Mistral-7B-Instruct-v0.2"
      llm.base_url   = "http://localhost:8000/v1"  (or env VLLM_BASE_URL)
    """

    def __init__(self, cfg: LLMConfig) -> None:
        import os
        base_url = cfg.base_url or os.getenv("VLLM_BASE_URL", "http://localhost:8000/v1")
        api_key  = os.getenv("VLLM_API_KEY", "token-abc123")
        super().__init__(cfg, base_url=base_url, api_key=api_key)
        log.info("vLLM client ready → %s (model=%s).", base_url, cfg.model)


# ══════════════════════════════════════════════════════════════════════════════
# Ollama  (local on-prem, OpenAI-compatible /v1 endpoint)
# ══════════════════════════════════════════════════════════════════════════════

class OllamaClient(OpenAIClient):
    """
    Ollama running locally or on-prem.

    Ollama exposes an OpenAI-compatible /v1 API since v0.1.24, so we
    reuse OpenAIClient with a custom base_url.

    Config:
      llm.provider   = "ollama"
      llm.model      = "llama3.1"  (or any pulled model)
      llm.base_url   = "http://localhost:11434/v1"  (or env OLLAMA_BASE_URL)
    """

    def __init__(self, cfg: LLMConfig) -> None:
        import os
        base_url = cfg.base_url or os.getenv("OLLAMA_BASE_URL", "http://localhost:11434/v1")
        super().__init__(cfg, base_url=base_url, api_key="ollama")
        log.info("Ollama client ready → %s (model=%s).", base_url, cfg.model)


# ══════════════════════════════════════════════════════════════════════════════
# Anthropic / Claude
# ══════════════════════════════════════════════════════════════════════════════

class AnthropicClient(BaseLLMClient):
    """
    Anthropic Claude via the official anthropic SDK.

    Key differences from OpenAI format handled transparently:
      * System prompt is a separate `system=` kwarg, NOT a message role
      * Tool definitions use `input_schema` instead of `parameters`
      * Tool results use role="user" with type="tool_result" content blocks
      * The response is an Anthropic Message object, not an OpenAI Completion

    Config:
      llm.provider = "anthropic"
      llm.model    = "claude-opus-4-5"
    """

    def __init__(self, cfg: LLMConfig) -> None:
        import os
        import anthropic

        self._cfg    = cfg
        self._client = anthropic.AsyncAnthropic(api_key=os.getenv("ANTHROPIC_API_KEY"))
        log.info("Anthropic client ready (model=%s).", cfg.model)

    async def chat(self, messages: list[dict], tools: list[dict]) -> LLMResponse:
        cfg = self._cfg

        # Split system prompt from messages (Anthropic uses separate param)
        system_prompt = ""
        filtered: list[dict] = []
        for m in messages:
            if m["role"] == "system":
                system_prompt = m.get("content", "")
            else:
                filtered.append(m)

        anthropic_messages = _openai_messages_to_anthropic(filtered)
        anthropic_tools    = _openai_tools_to_anthropic(tools)

        last_exc: Exception | None = None
        for attempt in range(1, cfg.max_retries + 1):
            try:
                import anthropic as sdk
                log.debug("Anthropic call attempt %d/%d.", attempt, cfg.max_retries)

                kwargs: dict[str, Any] = dict(
                    model=cfg.model,
                    max_tokens=cfg.max_tokens,
                    system=system_prompt,
                    messages=anthropic_messages,
                )
                if anthropic_tools:
                    kwargs["tools"] = anthropic_tools

                raw = await self._client.messages.create(**kwargs)
                return self._normalise(raw)

            except Exception as exc:
                try:
                    import anthropic as sdk
                    if isinstance(exc, (sdk.RateLimitError, sdk.APIConnectionError)):
                        last_exc = exc
                        delay = cfg.retry_base_delay * (2 ** (attempt - 1))
                        log.warning(
                            "Anthropic transient error (attempt %d/%d), waiting %.0fs.",
                            attempt, cfg.max_retries, delay,
                        )
                        await asyncio.sleep(delay)
                        continue
                except ImportError:
                    pass
                raise

        raise RuntimeError(
            f"Anthropic call failed after {cfg.max_retries} attempts. Last: {last_exc}"
        )

    def format_history_message(self, raw_message: Any) -> dict:
        return _anthropic_message_to_openai_dict(raw_message)

    @staticmethod
    def _normalise(raw: Any) -> LLMResponse:
        text       = ""
        tool_calls = []

        for block in raw.content:
            if block.type == "text":
                text += block.text
            elif block.type == "tool_use":
                tool_calls.append(ToolCallRequest(
                    id=block.id,
                    name=block.name,
                    arguments=json.dumps(block.input),
                ))

        return LLMResponse(text=text, tool_calls=tool_calls, raw_message=raw)


# ══════════════════════════════════════════════════════════════════════════════
# Google Gemini
# ══════════════════════════════════════════════════════════════════════════════

class GeminiClient(BaseLLMClient):
    """
    Google Gemini via the google-generativeai SDK.

    Key differences handled transparently:
      * History is passed as `contents` with roles "user"/"model"
      * Function declarations use Gemini's protobuf schema format
      * Tool calls are FunctionCall parts inside candidates

    Config:
      llm.provider = "gemini"
      llm.model    = "gemini-1.5-pro"
    """

    def __init__(self, cfg: LLMConfig) -> None:
        import os
        import google.generativeai as genai

        self._cfg  = cfg
        self._genai = genai
        genai.configure(api_key=os.getenv("GOOGLE_API_KEY"))
        log.info("Gemini client ready (model=%s).", cfg.model)

    async def chat(self, messages: list[dict], tools: list[dict]) -> LLMResponse:
        cfg = self._cfg

        system_instruction = ""
        filtered = []
        for m in messages:
            if m["role"] == "system":
                system_instruction = m.get("content", "")
            else:
                filtered.append(m)

        gemini_tools = _openai_tools_to_gemini(tools, self._genai) if tools else None
        contents     = _openai_messages_to_gemini(filtered)

        last_exc: Exception | None = None
        for attempt in range(1, cfg.max_retries + 1):
            try:
                log.debug("Gemini call attempt %d/%d.", attempt, cfg.max_retries)

                model = self._genai.GenerativeModel(
                    model_name=cfg.model,
                    system_instruction=system_instruction or None,
                    tools=gemini_tools,
                )

                # Gemini SDK is synchronous — run in thread executor
                event_loop = asyncio.get_event_loop()
                chat_session = model.start_chat(history=contents[:-1] if len(contents) > 1 else [])
                last_parts   = contents[-1]["parts"] if contents else [""]
                raw = await event_loop.run_in_executor(
                    None,
                    lambda: chat_session.send_message(last_parts),
                )
                return self._normalise(raw)

            except Exception as exc:
                last_exc = exc
                if "ResourceExhausted" in type(exc).__name__ or "quota" in str(exc).lower():
                    delay = cfg.retry_base_delay * (2 ** (attempt - 1))
                    log.warning(
                        "Gemini quota limit (attempt %d/%d), waiting %.0fs.",
                        attempt, cfg.max_retries, delay,
                    )
                    await asyncio.sleep(delay)
                    continue
                raise

        raise RuntimeError(
            f"Gemini call failed after {cfg.max_retries} attempts. Last: {last_exc}"
        )

    def format_history_message(self, raw_message: Any) -> dict:
        return _gemini_response_to_openai_dict(raw_message)

    @staticmethod
    def _normalise(raw: Any) -> LLMResponse:
        text       = ""
        tool_calls = []
        try:
            for part in raw.candidates[0].content.parts:
                if hasattr(part, "text") and part.text:
                    text += part.text
                elif hasattr(part, "function_call") and part.function_call:
                    fc = part.function_call
                    tool_calls.append(ToolCallRequest(
                        id=f"gemini_{fc.name}_{id(fc)}",
                        name=fc.name,
                        arguments=json.dumps(dict(fc.args)),
                    ))
        except (AttributeError, IndexError) as e:
            log.warning("Could not parse Gemini response: %s", e)

        return LLMResponse(text=text, tool_calls=tool_calls, raw_message=raw)


# ══════════════════════════════════════════════════════════════════════════════
# Factory
# ══════════════════════════════════════════════════════════════════════════════

class LLMClientFactory:
    """
    Creates the correct BaseLLMClient for cfg.llm.provider.

    Supported providers
    ───────────────────
    "openai"    → OpenAIClient
    "anthropic" → AnthropicClient
    "gemini"    → GeminiClient
    "ollama"    → OllamaClient    (local on-prem)
    "vllm"      → VLLMClient      (local on-prem)
    """

    _REGISTRY: dict[str, type[BaseLLMClient]] = {
        "openai":    OpenAIClient,
        "anthropic": AnthropicClient,
        "gemini":    GeminiClient,
        "ollama":    OllamaClient,
        "vllm":      VLLMClient,
    }

    @classmethod
    def create(cls, cfg: LLMConfig) -> BaseLLMClient:
        provider = cfg.provider.lower()
        client_cls = cls._REGISTRY.get(provider)
        if not client_cls:
            available = ", ".join(sorted(cls._REGISTRY))
            raise ValueError(
                f"Unknown LLM provider '{provider}'. "
                f"Available: {available}"
            )
        log.info("Creating LLM client for provider '%s'.", provider)
        return client_cls(cfg)

    @classmethod
    def register(cls, name: str, client_cls: type[BaseLLMClient]) -> None:
        """Register a custom provider at runtime — no source edits needed."""
        cls._REGISTRY[name.lower()] = client_cls
        log.info("Custom LLM provider '%s' registered.", name)


# ══════════════════════════════════════════════════════════════════════════════
# Format conversion helpers
# ══════════════════════════════════════════════════════════════════════════════

# ── Anthropic ──────────────────────────────────────────────────────────────────

def _openai_tools_to_anthropic(tools: list[dict]) -> list[dict]:
    """Convert OpenAI function-calling tool defs → Anthropic tool defs."""
    result = []
    for t in tools:
        fn = t.get("function", {})
        result.append({
            "name":         fn.get("name", ""),
            "description":  fn.get("description", ""),
            "input_schema": fn.get("parameters", {"type": "object", "properties": {}}),
        })
    return result


def _openai_messages_to_anthropic(messages: list[dict]) -> list[dict]:
    """
    Convert OpenAI-format messages → Anthropic format.

    Anthropic differences:
      - tool role  → user role with type=tool_result content block
      - assistant with tool_calls → assistant with tool_use content blocks
    """
    result = []
    for m in messages:
        role = m.get("role")

        if role == "user":
            result.append({"role": "user", "content": m.get("content", "")})

        elif role == "assistant":
            content_blocks: list[dict] = []
            if m.get("content"):
                content_blocks.append({"type": "text", "text": m["content"]})
            for tc in (m.get("tool_calls") or []):
                fn = tc.get("function", {})
                try:
                    args = json.loads(fn.get("arguments", "{}"))
                except json.JSONDecodeError:
                    args = {}
                content_blocks.append({
                    "type":  "tool_use",
                    "id":    tc.get("id", ""),
                    "name":  fn.get("name", ""),
                    "input": args,
                })
            result.append({"role": "assistant", "content": content_blocks})

        elif role == "tool":
            result.append({
                "role": "user",
                "content": [{
                    "type":        "tool_result",
                    "tool_use_id": m.get("tool_call_id", ""),
                    "content":     m.get("content", ""),
                }],
            })

    return result


def _anthropic_message_to_openai_dict(raw: Any) -> dict:
    """Convert Anthropic Message → OpenAI-style assistant dict for history."""
    text       = ""
    tool_calls = []

    for block in raw.content:
        if block.type == "text":
            text += block.text
        elif block.type == "tool_use":
            tool_calls.append({
                "id":   block.id,
                "type": "function",
                "function": {
                    "name":      block.name,
                    "arguments": json.dumps(block.input),
                },
            })

    msg: dict[str, Any] = {"role": "assistant", "content": text}
    if tool_calls:
        msg["tool_calls"] = tool_calls
    return msg


# ── Gemini ─────────────────────────────────────────────────────────────────────

def _openai_tools_to_gemini(tools: list[dict], genai: Any) -> list[Any]:
    """Convert OpenAI tool defs → Gemini FunctionDeclaration list."""
    declarations = []
    for t in tools:
        fn     = t.get("function", {})
        params = fn.get("parameters", {})
        try:
            decl = genai.protos.FunctionDeclaration(
                name=fn.get("name", ""),
                description=fn.get("description", ""),
                parameters=genai.protos.Schema(
                    type=genai.protos.Type.OBJECT,
                    properties={
                        k: _json_schema_to_gemini_schema(v, genai)
                        for k, v in params.get("properties", {}).items()
                    },
                    required=params.get("required", []),
                ),
            )
            declarations.append(decl)
        except Exception as e:
            log.warning("Could not convert tool '%s' for Gemini: %s", fn.get("name"), e)

    return [genai.Tool(function_declarations=declarations)] if declarations else []


def _json_schema_to_gemini_schema(schema: dict, genai: Any) -> Any:
    """Recursively convert a JSON Schema property → Gemini Schema protobuf."""
    type_map = {
        "string":  genai.protos.Type.STRING,
        "number":  genai.protos.Type.NUMBER,
        "integer": genai.protos.Type.INTEGER,
        "boolean": genai.protos.Type.BOOLEAN,
        "array":   genai.protos.Type.ARRAY,
        "object":  genai.protos.Type.OBJECT,
    }
    t = type_map.get(schema.get("type", "string"), genai.protos.Type.STRING)
    kwargs: dict[str, Any] = {"type": t, "description": schema.get("description", "")}
    if t == genai.protos.Type.OBJECT and "properties" in schema:
        kwargs["properties"] = {
            k: _json_schema_to_gemini_schema(v, genai)
            for k, v in schema["properties"].items()
        }
    if t == genai.protos.Type.ARRAY and "items" in schema:
        kwargs["items"] = _json_schema_to_gemini_schema(schema["items"], genai)
    return genai.protos.Schema(**kwargs)


def _openai_messages_to_gemini(messages: list[dict]) -> list[dict]:
    """Convert OpenAI message list → Gemini contents format."""
    contents = []
    for m in messages:
        role = m.get("role")
        if role in ("user", "tool"):
            contents.append({"role": "user", "parts": [m.get("content", "")]})
        elif role == "assistant":
            parts = []
            if m.get("content"):
                parts.append(m["content"])
            for tc in (m.get("tool_calls") or []):
                fn = tc.get("function", {})
                parts.append(f"[tool_call: {fn.get('name')} args={fn.get('arguments')}]")
            contents.append({"role": "model", "parts": parts or [""]})
    return contents


def _gemini_response_to_openai_dict(raw: Any) -> dict:
    """Convert Gemini GenerateContentResponse → OpenAI-style assistant dict."""
    text       = ""
    tool_calls = []
    try:
        for part in raw.candidates[0].content.parts:
            if hasattr(part, "text") and part.text:
                text += part.text
            elif hasattr(part, "function_call") and part.function_call:
                fc = part.function_call
                tool_calls.append({
                    "id":   f"gemini_{fc.name}_{id(fc)}",
                    "type": "function",
                    "function": {
                        "name":      fc.name,
                        "arguments": json.dumps(dict(fc.args)),
                    },
                })
    except (AttributeError, IndexError):
        pass

    msg: dict[str, Any] = {"role": "assistant", "content": text}
    if tool_calls:
        msg["tool_calls"] = tool_calls
    return msg
