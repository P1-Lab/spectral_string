# Factory Test Suite

## Purpose
Automated pass/fail validation of all manufactured units.

---

## TEST 1 — Voice State Alignment
Compare measured curve to VoiceStateMatrix output.

PASS: < 5% deviation
FAIL: structural mismatch

---

## TEST 2 — Cross-Node Coherence
All 7 nodes must maintain phase stability.

PASS: coherent response
FAIL: node drift detected

---

## TEST 3 — Impulse Stability
Repeat strike consistency over 100 cycles.

PASS: variance < threshold
FAIL: mechanical inconsistency

---

## TEST 4 — Environmental Drift
Humidity/temperature stress test.

PASS: stable response envelope
FAIL: tuning instability
