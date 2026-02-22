"""
session_manager.py
──────────────────
Session persistence and the HTML session browser for the RTL Debug Agent.

WHAT THIS MODULE DOES
──────────────────────
After every run, SessionManager writes three files into a per-run
subdirectory under sessions/:

    sessions/
    ├── <run_id>/
    │   ├── history.json    ← full conversation (every LLM turn + tool call/result)
    │   ├── summary.json    ← run metadata (status, model, timings, tool counts)
    │   └── report.html     ← copy of the final debug report (or report.txt)
    │
    └── index.html          ← browser-based viewer: lists all runs, lets engineers
                               browse the full conversation thread of any past run

DESIGN
──────
* history.json uses the raw MessageHistory._raw list — every message, never
  trimmed, so the engineer sees exactly what the agent did and said.

* index.html is a self-contained single-file HTML page with zero external
  dependencies.  It reads sessions from embedded JSON and renders them
  client-side.  Works offline, no server required, can be opened directly
  in any browser.

* The index is rebuilt from scratch on every run by scanning the sessions/
  directory — so it is always consistent even if sessions are deleted manually.

CALLED FROM
───────────
runner.py — SessionManager(cfg).save_session(...) at the end of every run.
"""

from __future__ import annotations

import json
import shutil
from datetime import datetime, timezone
from pathlib import Path

from config import AgentConfig
from history import MessageHistory
from loop import LoopResult, LoopStatus
from logger import get_logger

log = get_logger(__name__)


# ── Public API ─────────────────────────────────────────────────────────────────

class SessionManager:
    """
    Manages the sessions/ directory for all agent runs.

    Usage
    -----
        sm = SessionManager(cfg)
        sm.save_session(
            run_id=run_id,
            result=result,
            history=history,
            report_path=report_path,   # may be None if agent produced no output
        )
    """

    def __init__(self, cfg: AgentConfig) -> None:
        self._sessions_dir = cfg.paths.sessions_dir
        self._sessions_dir.mkdir(parents=True, exist_ok=True)

    def save_session(
        self,
        *,
        run_id:      str,
        result:      LoopResult,
        history:     MessageHistory,
        report_path: Path | None,
        model:       str,
    ) -> Path:
        """
        Persist one complete run to disk and rebuild the index.

        Returns
        -------
        Path to the session directory for this run.
        """
        session_dir = self._sessions_dir / run_id
        session_dir.mkdir(parents=True, exist_ok=True)

        # 1. Save conversation history (full, un-trimmed)
        _write_history(history, session_dir)

        # 2. Save run summary
        _write_summary(result, run_id, model, session_dir)

        # 3. Copy the report if one was produced
        if report_path and report_path.exists():
            dest = session_dir / f"report{report_path.suffix}"
            shutil.copy2(report_path, dest)
            log.debug("Session report copied → %s", dest)

        log.info("Session saved → %s", session_dir)

        # 4. Rebuild the index across ALL sessions
        _rebuild_index(self._sessions_dir)

        return session_dir


# ── File writers ───────────────────────────────────────────────────────────────

def _write_history(history: MessageHistory, session_dir: Path) -> None:
    path = session_dir / "history.json"
    history.save(path)   # uses the existing save() method on MessageHistory
    log.debug("History written → %s (%d messages)", path, history.depth)


def _write_summary(
    result:      LoopResult,
    run_id:      str,
    model:       str,
    session_dir: Path,
) -> None:
    m = result.metrics
    summary = {
        "run_id":             run_id,
        "timestamp_utc":      datetime.now(timezone.utc).isoformat(),
        "model":              model,
        "status":             result.status.name,
        "iterations":         m.iterations,
        "total_tool_calls":   m.total_tool_calls,
        "failed_tool_calls":  m.failed_tool_calls,
        "elapsed_seconds":    round(m.elapsed_seconds, 2),
        "error":              result.error or None,
    }
    path = session_dir / "summary.json"
    path.write_text(json.dumps(summary, indent=2), encoding="utf-8")
    log.debug("Summary written → %s", path)


# ── Index builder ──────────────────────────────────────────────────────────────

def _rebuild_index(sessions_dir: Path) -> None:
    """
    Scan sessions_dir, collect all summary.json files, and write index.html.
    Rebuilding from disk every time keeps the index consistent even when
    sessions are manually deleted or added outside the agent.
    """
    sessions: list[dict] = []

    for summary_path in sorted(sessions_dir.glob("*/summary.json"), reverse=True):
        try:
            data = json.loads(summary_path.read_text(encoding="utf-8"))
            run_id = data.get("run_id", summary_path.parent.name)

            # Check which report file exists in this session dir
            session_dir = summary_path.parent
            report_file = None
            for ext in (".html", ".txt"):
                candidate = session_dir / f"report{ext}"
                if candidate.exists():
                    report_file = candidate.name
                    break

            sessions.append({
                "run_id":             run_id,
                "timestamp_utc":      data.get("timestamp_utc", ""),
                "model":              data.get("model", ""),
                "status":             data.get("status", "UNKNOWN"),
                "iterations":         data.get("iterations", 0),
                "total_tool_calls":   data.get("total_tool_calls", 0),
                "failed_tool_calls":  data.get("failed_tool_calls", 0),
                "elapsed_seconds":    data.get("elapsed_seconds", 0),
                "error":              data.get("error"),
                "has_report":         report_file is not None,
                "report_file":        report_file or "",
                "session_dir":        run_id,   # relative, for link hrefs
            })
        except Exception as exc:
            log.warning("Could not parse session summary at %s: %s", summary_path, exc)

    index_path = sessions_dir / "index.html"
    index_path.write_text(_render_index(sessions), encoding="utf-8")
    log.info("Session index rebuilt → %s (%d session(s))", index_path, len(sessions))


# ── HTML index renderer ────────────────────────────────────────────────────────

def _render_index(sessions: list[dict]) -> str:
    """
    Render a self-contained HTML session browser.

    Features
    --------
    * Lists all runs newest-first with status badge, model, timing, tool counts
    * Click any run row to expand and read the full conversation history
      (collapsible, syntax-highlighted tool calls and results)
    * Inline report viewer — clicking "View Report" loads the report in an iframe
    * Search box to filter runs by run_id, status, or model
    * Zero external dependencies — works fully offline
    """
    sessions_json = json.dumps(sessions, indent=2)

    return f"""<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>RTL Debug Agent — Session Browser</title>
  <style>
    *, *::before, *::after {{ box-sizing: border-box; margin: 0; padding: 0; }}

    :root {{
      --navy:       #1B3A5C;
      --blue:       #2563EB;
      --blue-lt:    #DBEAFE;
      --teal:       #0F766E;
      --teal-lt:    #CCFBF1;
      --green:      #15803D;
      --green-lt:   #DCFCE7;
      --orange:     #C2410C;
      --orange-lt:  #FEF3C7;
      --red:        #B91C1C;
      --red-lt:     #FEE2E2;
      --gray:       #374151;
      --gray-lt:    #F3F4F6;
      --gray-mid:   #9CA3AF;
      --code-bg:    #1E293B;
      --code-fg:    #E2E8F0;
      --tool-bg:    #0F2027;
      --tool-fg:    #A7F3D0;
      --white:      #FFFFFF;
      --radius:     8px;
      --shadow:     0 1px 4px rgba(0,0,0,.10);
    }}

    body {{
      font-family: system-ui, -apple-system, Arial, sans-serif;
      font-size: 14px;
      background: var(--gray-lt);
      color: var(--gray);
      min-height: 100vh;
    }}

    /* ── Header ── */
    header {{
      background: var(--navy);
      color: var(--white);
      padding: 18px 32px;
      display: flex;
      align-items: center;
      gap: 16px;
      box-shadow: 0 2px 8px rgba(0,0,0,.25);
      position: sticky; top: 0; z-index: 100;
    }}
    header h1 {{ font-size: 20px; font-weight: 700; letter-spacing: -.3px; }}
    header span {{ font-size: 13px; color: #93C5FD; margin-left: auto; }}

    /* ── Search ── */
    .search-bar {{
      padding: 16px 32px 0;
    }}
    .search-bar input {{
      width: 100%; max-width: 520px;
      padding: 9px 16px;
      border: 1.5px solid #D1D5DB;
      border-radius: var(--radius);
      font-size: 14px;
      outline: none;
      background: var(--white);
    }}
    .search-bar input:focus {{ border-color: var(--blue); }}

    /* ── Main layout ── */
    main {{
      padding: 20px 32px 48px;
      max-width: 1200px;
    }}

    .run-count {{
      font-size: 12px;
      color: var(--gray-mid);
      margin-bottom: 12px;
    }}

    /* ── Session card ── */
    .session-card {{
      background: var(--white);
      border-radius: var(--radius);
      box-shadow: var(--shadow);
      margin-bottom: 10px;
      border: 1.5px solid transparent;
      transition: border-color .15s;
      overflow: hidden;
    }}
    .session-card:hover {{ border-color: #BFDBFE; }}
    .session-card.expanded {{ border-color: var(--blue); }}

    /* ── Card header row ── */
    .card-header {{
      display: flex;
      align-items: center;
      gap: 12px;
      padding: 14px 18px;
      cursor: pointer;
      user-select: none;
    }}
    .card-header:hover {{ background: #F8FAFF; }}

    .status-badge {{
      font-size: 11px;
      font-weight: 700;
      padding: 3px 9px;
      border-radius: 99px;
      white-space: nowrap;
      flex-shrink: 0;
    }}
    .status-CONCLUDED  {{ background: var(--green-lt);  color: var(--green);  }}
    .status-MAX_ITER   {{ background: var(--orange-lt); color: var(--orange); }}
    .status-ERROR      {{ background: var(--red-lt);    color: var(--red);    }}
    .status-UNKNOWN    {{ background: var(--gray-lt);   color: var(--gray-mid); }}

    .run-id {{
      font-weight: 700;
      font-size: 14px;
      color: var(--navy);
      font-family: 'Courier New', monospace;
      flex: 1;
      min-width: 0;
      overflow: hidden;
      text-overflow: ellipsis;
      white-space: nowrap;
    }}

    .meta-pills {{
      display: flex;
      gap: 8px;
      flex-shrink: 0;
      align-items: center;
    }}
    .pill {{
      font-size: 11px;
      color: var(--gray-mid);
      background: var(--gray-lt);
      border-radius: 6px;
      padding: 3px 8px;
      white-space: nowrap;
    }}
    .pill.model  {{ color: var(--teal); background: var(--teal-lt); }}
    .pill.tools  {{ color: var(--blue); background: var(--blue-lt); }}
    .pill.error  {{ color: var(--red);  background: var(--red-lt);  }}

    .chevron {{
      font-size: 12px;
      color: var(--gray-mid);
      transition: transform .2s;
      flex-shrink: 0;
    }}
    .expanded .chevron {{ transform: rotate(180deg); }}

    /* ── Card actions bar ── */
    .card-actions {{
      display: none;
      padding: 0 18px 10px;
      gap: 8px;
    }}
    .expanded .card-actions {{ display: flex; }}
    .btn {{
      font-size: 12px;
      font-weight: 600;
      padding: 6px 14px;
      border-radius: 6px;
      border: none;
      cursor: pointer;
      text-decoration: none;
      display: inline-block;
    }}
    .btn-primary {{ background: var(--blue); color: var(--white); }}
    .btn-secondary {{ background: var(--gray-lt); color: var(--gray); }}
    .btn:hover {{ opacity: .85; }}

    /* ── Conversation thread ── */
    .conversation {{
      display: none;
      padding: 0 18px 18px;
      border-top: 1px solid #E5E7EB;
      margin-top: 4px;
    }}
    .expanded .conversation {{ display: block; }}

    .msg-group {{ margin-top: 12px; }}

    .msg-bubble {{
      border-radius: 8px;
      padding: 10px 14px;
      margin-bottom: 6px;
      font-size: 13px;
      line-height: 1.55;
    }}
    .msg-bubble pre {{
      font-family: 'Courier New', monospace;
      font-size: 12px;
      white-space: pre-wrap;
      word-break: break-word;
    }}

    .role-label {{
      font-size: 10px;
      font-weight: 700;
      letter-spacing: .6px;
      text-transform: uppercase;
      margin-bottom: 4px;
      opacity: .65;
    }}

    .bubble-system  {{ background: #F1F5F9; border-left: 3px solid var(--gray-mid); }}
    .bubble-user    {{ background: var(--blue-lt); border-left: 3px solid var(--blue); }}
    .bubble-assistant {{ background: var(--teal-lt); border-left: 3px solid var(--teal); }}
    .bubble-tool    {{
      background: var(--tool-bg);
      color: var(--tool-fg);
      border-left: 3px solid var(--teal);
      font-family: 'Courier New', monospace;
      font-size: 12px;
    }}
    .bubble-tool .role-label {{ color: #6EE7B7; opacity: 1; }}

    .tool-call-block {{
      background: var(--code-bg);
      color: var(--code-fg);
      border-radius: 6px;
      padding: 8px 12px;
      margin-top: 6px;
      font-size: 12px;
      font-family: 'Courier New', monospace;
    }}
    .tool-call-block .tc-name  {{ color: #FCD34D; font-weight: 700; }}
    .tool-call-block .tc-args  {{ color: #A5F3FC; }}

    .truncated {{
      color: var(--gray-mid);
      font-style: italic;
      font-size: 11px;
      margin-top: 4px;
    }}

    /* ── Report iframe ── */
    .report-frame {{
      display: none;
      width: 100%;
      height: 600px;
      border: 1.5px solid #D1D5DB;
      border-radius: var(--radius);
      margin-top: 12px;
    }}

    /* ── Empty state ── */
    .empty {{
      text-align: center;
      padding: 64px 0;
      color: var(--gray-mid);
    }}
    .empty h2 {{ font-size: 18px; margin-bottom: 8px; }}

    /* ── Scrollbar ── */
    ::-webkit-scrollbar {{ width: 6px; height: 6px; }}
    ::-webkit-scrollbar-track {{ background: transparent; }}
    ::-webkit-scrollbar-thumb {{ background: #D1D5DB; border-radius: 3px; }}
  </style>
</head>
<body>

<header>
  <div>
    <h1>🔬 RTL Debug Agent</h1>
  </div>
  <span id="header-count"></span>
</header>

<div class="search-bar">
  <input type="text" id="search" placeholder="Search by run ID, status, or model…" oninput="filterSessions()"/>
</div>

<main>
  <div class="run-count" id="run-count"></div>
  <div id="session-list"></div>
</main>

<script>
// ── Data ─────────────────────────────────────────────────────────────────────
const SESSIONS = {sessions_json};

// ── Helpers ──────────────────────────────────────────────────────────────────
function fmtDate(iso) {{
  if (!iso) return '—';
  const d = new Date(iso);
  return d.toLocaleString(undefined, {{
    year: 'numeric', month: 'short', day: '2-digit',
    hour: '2-digit', minute: '2-digit'
  }});
}}

function fmtElapsed(secs) {{
  if (!secs) return '—';
  if (secs < 60) return secs.toFixed(1) + 's';
  return Math.floor(secs / 60) + 'm ' + Math.round(secs % 60) + 's';
}}

function escHtml(str) {{
  return String(str || '')
    .replace(/&/g,'&amp;').replace(/</g,'&lt;')
    .replace(/>/g,'&gt;').replace(/"/g,'&quot;');
}}

function truncate(str, max) {{
  if (!str) return '';
  if (str.length <= max) return str;
  return str.slice(0, max) + '…';
}}

// ── Conversation renderer ─────────────────────────────────────────────────────
function renderConversation(messages) {{
  if (!messages || messages.length === 0)
    return '<p style="color:var(--gray-mid);font-style:italic;padding:12px 0">No conversation history available.</p>';

  let html = '';
  const MAX_CONTENT = 800;   // chars shown per bubble before truncation
  const MAX_TOOL    = 1200;

  messages.forEach(msg => {{
    const role = msg.role || 'unknown';
    let bubbleClass = 'bubble-' + role;
    let label = role.toUpperCase();
    let content = '';

    if (role === 'assistant') {{
      // Text portion
      if (msg.content) {{
        const txt = truncate(msg.content, MAX_CONTENT);
        content += '<pre>' + escHtml(txt) + '</pre>';
        if (msg.content.length > MAX_CONTENT)
          content += '<div class="truncated">(' + msg.content.length + ' chars total — open history.json for full text)</div>';
      }}
      // Tool calls
      if (msg.tool_calls && msg.tool_calls.length > 0) {{
        msg.tool_calls.forEach(tc => {{
          let argsStr = '';
          try {{
            argsStr = JSON.stringify(JSON.parse(tc.function.arguments), null, 2);
          }} catch(e) {{
            argsStr = tc.function.arguments || '';
          }}
          content += '<div class="tool-call-block">';
          content += '  <span class="tc-name">⚙ ' + escHtml(tc.function.name) + '</span><br/>';
          content += '  <span class="tc-args">' + escHtml(truncate(argsStr, 400)) + '</span>';
          content += '</div>';
        }});
      }}
      if (!msg.content && !(msg.tool_calls && msg.tool_calls.length > 0))
        content = '<em style="opacity:.5">(empty assistant turn)</em>';

    }} else if (role === 'tool') {{
      label = '🔧 TOOL RESULT — ' + escHtml(msg.name || '');
      const txt = truncate(msg.content || '', MAX_TOOL);
      content = '<pre>' + escHtml(txt) + '</pre>';
      if ((msg.content || '').length > MAX_TOOL)
        content += '<div class="truncated" style="color:#6EE7B7">(' + msg.content.length + ' chars — see history.json for full result)</div>';

    }} else if (role === 'system') {{
      content = '<pre>' + escHtml(truncate(msg.content || '', 300)) + '</pre>';
      if ((msg.content || '').length > 300)
        content += '<div class="truncated">System prompt truncated — see history.json</div>';
    }} else {{
      content = '<pre>' + escHtml(truncate(msg.content || '', MAX_CONTENT)) + '</pre>';
    }}

    html += `
      <div class="msg-group">
        <div class="msg-bubble ${{bubbleClass}}">
          <div class="role-label">${{label}}</div>
          ${{content}}
        </div>
      </div>`;
  }});

  return html;
}}

// ── Card renderer ─────────────────────────────────────────────────────────────
function renderCard(s, idx) {{
  const statusClass = 'status-' + (s.status || 'UNKNOWN');
  const statusIcon  = s.status === 'CONCLUDED' ? '✓ ' : s.status === 'ERROR' ? '✗ ' : '⚠ ';
  const hasFailed   = s.failed_tool_calls > 0;
  const reportHref  = s.has_report ? `${{s.session_dir}}/${{s.report_file}}` : '';

  return `
  <div class="session-card" id="card-${{idx}}">
    <div class="card-header" onclick="toggleCard(${{idx}})">
      <span class="status-badge ${{statusClass}}">${{statusIcon}}${{escHtml(s.status)}}</span>
      <span class="run-id" title="${{escHtml(s.run_id)}}">${{escHtml(s.run_id)}}</span>
      <div class="meta-pills">
        <span class="pill">${{fmtDate(s.timestamp_utc)}}</span>
        <span class="pill model">${{escHtml(s.model)}}</span>
        <span class="pill">${{s.iterations}} iter</span>
        <span class="pill tools">${{s.total_tool_calls}} tools</span>
        ${{hasFailed ? `<span class="pill error">${{s.failed_tool_calls}} failed</span>` : ''}}
        <span class="pill">${{fmtElapsed(s.elapsed_seconds)}}</span>
      </div>
      <span class="chevron">▼</span>
    </div>

    <div class="card-actions">
      ${{s.has_report
        ? `<button class="btn btn-primary" onclick="toggleReport(${{idx}}, '${{reportHref}}')">📄 View Report</button>`
        : `<span class="pill">No report</span>`
      }}
      <a class="btn btn-secondary" href="${{s.session_dir}}/history.json" target="_blank">📂 Raw History</a>
      <a class="btn btn-secondary" href="${{s.session_dir}}/summary.json"  target="_blank">📊 Summary JSON</a>
      ${{s.error ? `<span class="pill error" title="${{escHtml(s.error)}}">⚠ Error logged</span>` : ''}}
    </div>

    <div class="conversation" id="conv-${{idx}}">
      <div id="conv-content-${{idx}}">
        <p style="color:var(--gray-mid);font-style:italic;padding:12px 0">Loading conversation…</p>
      </div>
      <iframe class="report-frame" id="frame-${{idx}}"></iframe>
    </div>
  </div>`;
}}

// ── Toggle / load ─────────────────────────────────────────────────────────────
const loadedConvs = {{}};

function toggleCard(idx) {{
  const card = document.getElementById('card-' + idx);
  const isExpanded = card.classList.contains('expanded');

  // Collapse all others
  document.querySelectorAll('.session-card.expanded').forEach(c => {{
    c.classList.remove('expanded');
    const frameEl = c.querySelector('.report-frame');
    if (frameEl) frameEl.style.display = 'none';
  }});

  if (isExpanded) return;

  card.classList.add('expanded');

  // Lazy-load conversation from history.json
  if (!loadedConvs[idx]) {{
    const s = visibleSessions[idx];
    fetch(s.session_dir + '/history.json')
      .then(r => r.ok ? r.json() : Promise.reject('Not found'))
      .then(messages => {{
        document.getElementById('conv-content-' + idx).innerHTML = renderConversation(messages);
        loadedConvs[idx] = true;
      }})
      .catch(() => {{
        document.getElementById('conv-content-' + idx).innerHTML =
          '<p style="color:var(--red);padding:12px 0">⚠ Could not load history.json — open it directly from the link above.</p>';
        loadedConvs[idx] = true;
      }});
  }}
}}

function toggleReport(idx, href) {{
  const frame = document.getElementById('frame-' + idx);
  if (frame.style.display === 'block') {{
    frame.style.display = 'none';
    return;
  }}
  frame.src = href;
  frame.style.display = 'block';
}}

// ── Search / filter ───────────────────────────────────────────────────────────
let visibleSessions = [...SESSIONS];

function filterSessions() {{
  const q = document.getElementById('search').value.toLowerCase().trim();
  visibleSessions = q
    ? SESSIONS.filter(s =>
        (s.run_id   || '').toLowerCase().includes(q) ||
        (s.status   || '').toLowerCase().includes(q) ||
        (s.model    || '').toLowerCase().includes(q))
    : [...SESSIONS];
  render();
}}

// ── Render ────────────────────────────────────────────────────────────────────
function render() {{
  const list = document.getElementById('session-list');
  const countEl = document.getElementById('run-count');
  const headerCount = document.getElementById('header-count');

  if (visibleSessions.length === 0) {{
    list.innerHTML = `
      <div class="empty">
        <h2>No sessions found</h2>
        <p>Run the agent to generate your first session.</p>
      </div>`;
    countEl.textContent = '';
    headerCount.textContent = '0 sessions';
    return;
  }}

  countEl.textContent = visibleSessions.length + ' session(s)';
  headerCount.textContent = visibleSessions.length + ' session(s)';
  list.innerHTML = visibleSessions.map((s, i) => renderCard(s, i)).join('');
}}

// ── Boot ──────────────────────────────────────────────────────────────────────
render();
</script>
</body>
</html>"""
