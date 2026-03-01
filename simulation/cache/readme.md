# MESI Cache Coherence — Design & Verification Guide

## Files

| File | Description |
|---|---|
| `mesi_cache.v` | Per-core cache with full MESI state machine |
| `mesi_system.v` | Contains: `bus_arbiter`, `main_memory`, `mesi_system` top-level |
| `tb_mesi_system.v` | Self-checking testbench covering all MESI transitions |

---

## Architecture Diagram

```
   Core 0                              Core 1
     │  cpu_req/ack/addr/data            │  cpu_req/ack/addr/data
     ▼                                   ▼
┌──────────────┐                  ┌──────────────┐
│  mesi_cache  │                  │  mesi_cache  │
│   (ID=0)     │                  │   (ID=1)     │
│              │                  │              │
│  tag[]       │                  │  tag[]       │
│  mesi[]      │                  │  mesi[]      │
│  data[]      │                  │  data[]      │
└──────┬───────┘                  └──────┬───────┘
       │ bus_req/grant                   │ bus_req/grant
       │ bus_drive/addr/cmd/data         │ bus_drive/addr/cmd/data
       │ snoop: shared/dirty/rdata       │ snoop: shared/dirty/rdata
       │                                 │
       └──────────────┬──────────────────┘
                      │
           ┌──────────▼──────────┐
           │    Shared Bus       │◄── bus_valid / bus_addr
           │  (wire OR / mux)    │    bus_cmd / bus_data
           └──────────┬──────────┘
              ┌───────┴────────┐
              │                │
    ┌─────────▼──────┐  ┌──────▼──────────┐
    │  bus_arbiter   │  │  main_memory    │
    │ (round-robin)  │  │  (word[n]=n)    │
    └────────────────┘  └─────────────────┘
```

---

## MESI Protocol Explained

Each cache line carries a 2-bit state tag:

```
State        Meaning                               Can write?  Bus action on write
──────────── ───────────────────────────────────── ──────────  ───────────────────
M Modified   Only copy; dirty (differs from mem)  Yes         None (already owner)
E Exclusive  Only copy; clean                     Yes         None (silent E→M)
S Shared     Multiple caches hold clean copies    No          BusInv → others go I
I Invalid    Not present / stale                  No          BusRd first
```

### State Transition Diagram

```
                  ┌─────────────────────────────────────────────────────┐
                  │                  (another cache BusRd)               │
                  │           M ─────────────────────────────────► S    │
                  │           │                                    ▲     │
                  │   write   │                          BusRd,    │     │
                  │  (silent) │                         no other   │     │
                  │           ▼                         sharers    │     │
         write    │     ┌──── M                                    │     │
     (after BusInv│     │     ▲                              ┌─────┘     │
      for S→M)   │     │     │ write                        │           │
                  │     │     │ (after BusInv               │           │
                  │     │     │  for S→M)                   │           │
     I ─────── BusRd──► E ───┘           BusRd,        S ──┘           │
                        │                other          │               │
                        │                sharers        │   BusInv      │
                        └───────────────────────────────┘   (snoop) ───► I
```

### Bus Transaction Types

| Transaction | Who drives it | Who reacts |
|---|---|---|
| `BusRd` | Cache with a miss | Other caches: if M, supply data + go S; if E, go S; memory: if no dirty, supply |
| `BusInv` | Cache upgrading S→M | All other caches: invalidate (go I) |
| `BusWB` | Cache evicting dirty line | Memory: absorb the dirty data |

---

## How the Testbench Verifies Coherence

Each test follows the pattern:

1. **Issue transactions** via `cpu_read` / `cpu_write` tasks
2. **Wait for ack** (tasks poll the `cpu_ack` signal with a timeout watchdog)
3. **Inspect internal state** directly via hierarchical references:
   - `dut.u_cache0.mesi[index]` — MESI state bits
   - `dut.u_cache0.data[index]` — cached data
4. **Count bus transactions** using the always block bus monitor
5. **Print PASS/FAIL** for each assertion

### Tests and Coverage

```
Test 1: Cold miss         I → E              BusRd expected
Test 2: Read hit          E stays E          No bus activity
Test 3: Shared read       E → S (both)       BusRd, bus_shared asserted
Test 4: Write to shared   S → M + BusInv     BusInv, other cache S→I
Test 5: Read dirty line   fetch from M cache M→S, requester→S
Test 6: Exclusive write   E → M (silent)     No BusInv!
Test 7: Dirty eviction    M → BusWB → I      BusWB to memory
Test 8: False sharing     M ping-pong        Repeated BusInv
```

---

## How to Simulate

### Using Icarus Verilog (free)

```bash
# Compile
iverilog -o mesi_sim \
    mesi_cache.v mesi_system.v tb_mesi_system.v

# Run
vvp mesi_sim

# View waveforms
gtkwave mesi_sim.vcd
```

### Using ModelSim / Questa

```tcl
vlog mesi_cache.v mesi_system.v tb_mesi_system.v
vsim tb_mesi_system
run -all
```

### Expected Output (condensed)

```
============================================================
 TEST 1: Cold miss (Core 0, addr=0x10)
============================================================
  [BUS] BusRd   addr=0x10
  [PASS] Core0 rdata (word 4) = 0x00000004
  [PASS] Cache0 index4 state = E(Exclusive)

============================================================
 TEST 2: Read hit (Core 0, addr=0x10 again)
============================================================
  [PASS] Core0 rdata (hit) = 0x00000004
  [PASS] Cache0 index4 state = E(Exclusive)
  Bus BusRd count since test: 0 (expected 0 - served from cache)

... (all 8 tests) ...

============================================================
 SIMULATION COMPLETE — Transaction Summary
============================================================
  Total BusRd         : 7
  Total BusInvalidate : 5
  Total BusWriteback  : 1
```

---

## Key Design Decisions

**Direct-mapped cache** — one line per index, no way sets or LRU. Simple to explain but leads to more conflict misses (visible in Test 7 and Test 8).

**Snooping bus** — every cache observes every transaction simultaneously. Scales to ~4-8 cores. Beyond that, directory-based coherence is used instead (a separate protocol).

**Write-invalidate** (vs write-update) — on a write, other copies are invalidated rather than updated. More bus traffic for read-after-write but fewer unnecessary updates. This is what x86 (MESI) and ARM (MOESI) use.

**1-cycle memory** — in reality DRAM takes 100-200 cycles. The concepts are identical; only the wait states change.
