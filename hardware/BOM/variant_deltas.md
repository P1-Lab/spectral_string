# Variant Delta Specification — Scale Transformation Rules

## Purpose
Defines ONLY the differences between Mini / Standard / Stage systems.

No base definitions are repeated here.

---

## 1. Physical Scale Adjustments

| Parameter | Mini | Standard | Stage |
|----------|------|----------|-------|
| Length | ↓ reduced | reference | ↑ expanded |
| Mass | ↓ reduced | reference | ↑ increased |
| Enclosure rigidity | medium | high | maximum |

---

## 2. Electrical Scaling Rules

- Mini: reduced power envelope, same impedance rules
- Standard: full nominal system
- Stage: increased current capacity, reinforced thermal margins

---

## 3. Acoustic Behavior Scaling

- Mini: faster transient response, reduced sustain
- Standard: balanced response curve
- Stage: extended sustain, increased spatial interaction

---

## 4. Forbidden Divergences

The following are NOT allowed across variants:

- changing input impedance baseline (< 10 MΩ violation)
- altering core NRE coupling model
- introducing DSP-dependent compensation
- breaking mechanical rigidity assumptions

---

END DELTA SPEC
