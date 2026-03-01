# ══════════════════════════════════════════════════════════════════════════════
# FaultTrace RTL Debug Agent — Dockerfile
# ══════════════════════════════════════════════════════════════════════════════
#
# Multi-stage build:
#   Stage 1 (builder) — installs all Python dependencies into a venv
#   Stage 2 (runtime) — copies only the venv + source, no build tools
#
# This keeps the final image lean (~200MB vs ~800MB with build tools).
#
# BUILD
# ─────
#   docker build -t faulttrace:latest .
#
# RUN (local, with OpenAI)
# ────────────────────────
#   docker run --rm \
#     -e OPENAI_API_KEY=sk-... \
#     -v $(pwd)/prompts:/app/prompts:ro \
#     -v $(pwd)/output:/app/output \
#     faulttrace:latest
#
# RUN (local, with Ollama on host)
# ─────────────────────────────────
#   docker run --rm \
#     -e FAULTTRACE_PROVIDER=ollama \
#     -e FAULTTRACE_MODEL=llama3.1 \
#     -e OLLAMA_BASE_URL=http://host.docker.internal:11434/v1 \
#     -v $(pwd)/prompts:/app/prompts:ro \
#     -v $(pwd)/output:/app/output \
#     faulttrace:latest
# ══════════════════════════════════════════════════════════════════════════════

# ── Stage 1: dependency builder ───────────────────────────────────────────────
FROM python:3.11-slim AS builder

WORKDIR /build

# Install build dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    gcc \
    && rm -rf /var/lib/apt/lists/*

# Copy requirements first (layer cache — only re-runs if requirements change)
COPY requirements.txt .

# Create venv and install all deps
RUN python -m venv /opt/venv && \
    /opt/venv/bin/pip install --upgrade pip && \
    /opt/venv/bin/pip install --no-cache-dir -r requirements.txt


# ── Stage 2: runtime image ────────────────────────────────────────────────────
FROM python:3.11-slim AS runtime

# Non-root user for security
RUN groupadd -r faulttrace && useradd -r -g faulttrace -d /app faulttrace

WORKDIR /app

# Runtime OS deps (git for potential RTL repo access, less for log viewing)
RUN apt-get update && apt-get install -y --no-install-recommends \
    git \
    && rm -rf /var/lib/apt/lists/*

# Copy venv from builder
COPY --from=builder /opt/venv /opt/venv
ENV PATH="/opt/venv/bin:$PATH"

# Copy agent source
COPY --chown=faulttrace:faulttrace agent.py \
     config.py \
     history.py \
     llm_client.py \
     logger.py \
     loop.py \
     mcp_manager.py \
     reporter.py \
     runner.py \
     session_manager.py \
     tool_executor.py \
     ./

# Copy MCP servers into server/ subdirectory
COPY --chown=faulttrace:faulttrace server/ ./server/

# Writable runtime directories
# Prompts are mounted read-only from outside; output/logs/sessions are writable
RUN mkdir -p /app/output /app/logs /app/sessions /app/prompts && \
    chown -R faulttrace:faulttrace /app/output /app/logs /app/sessions /app/prompts

# Environment defaults (all overridable at runtime)
ENV TOPDIR=/app \
    FAULTTRACE_PROVIDER=openai \
    FAULTTRACE_MODEL=gpt-4o \
    FAULTTRACE_MAX_ITERATIONS=50 \
    FAULTTRACE_MAX_IDLE_TURNS=3 \
    FAULTTRACE_OUTPUT_DIR=/app/output \
    FAULTTRACE_LOG_DIR=/app/logs \
    FAULTTRACE_SESSIONS_DIR=/app/sessions \
    FAULTTRACE_PROMPTS_DIR=/app/prompts \
    PYTHONUNBUFFERED=1 \
    PYTHONDONTWRITEBYTECODE=1

USER faulttrace

# Volumes for persistent data
VOLUME ["/app/output", "/app/logs", "/app/sessions", "/app/prompts"]

ENTRYPOINT ["python", "agent.py"]
CMD []
