# Base BOM — Spectral String System

## Role
This defines the invariant physical and electrical architecture shared across all scale variants (Mini / Standard / Stage).

All derivatives MUST inherit this baseline without modification unless explicitly overridden in variant_deltas.md.

---

## 1. Core Electrical Architecture

- Signal Path: Analog-first buffer stage (JFET or equivalent high-impedance input)
- Input Impedance: ≥ 10 MΩ (non-negotiable system constraint)
- Output Stage: Low-noise line driver (balanced preferred where applicable)
- Grounding: Single-point star ground topology

---

## 2. Core Transduction Philosophy

- Mechanical excitation → physical string → analog transduction → spectral resolution layer (NRE)
- No digital-first sound generation permitted in baseline mode

---

## 3. Wiring Standards

- Signal wiring: shielded 20–24 AWG copper
- Power wiring: 14–18 AWG depending on scale variant
- All signal paths must be physically separated from power rails

---

## 4. Structural Materials Class

- Primary body: hardwood or engineered composite with high stiffness-to-weight ratio
- Internal cavities: CNC-defined, sealed or semi-sealed depending on variant
- No flexible chassis allowed in signal-bearing regions

---

## 5. Connector System

- Balanced audio: XLR (preferred)
- Auxiliary: TRS where required
- Power: locking DC or XT-series depending on scale

---

## 6. System Constraint Invariants

- Mechanical stability precedes signal correction
- No DSP compensation for structural instability
- All variants must preserve baseline impedance behavior

---

END BASE SYSTEM
