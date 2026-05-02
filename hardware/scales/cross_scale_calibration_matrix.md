# CROSS_SCALE_CALIBRATION_MATRIX.md
## Spectral String Instrument System

---

## 1. PURPOSE

This document defines how **musical gesture behavior translates across Mini, Standard, and Stage nodes**.

It does NOT define pitch mapping.

It defines:

> how physical excitation becomes comparable musical intent across scales

This is the missing layer between hardware scaling and musical consistency.

---

## 2. CORE PROBLEM

A single gesture does not produce equivalent raw output across scales.

Example:

- Mini Node → fast decay, high articulation density
- Stage Node → long decay, high spatial bloom

Yet both must represent the same **intentional action**.

---

## 3. DESIGN PRINCIPLE

We do not normalize sound.

We normalize:

> perceptual gesture identity

Meaning:

- attack remains attack
- energy contour remains consistent
- decay shape is scale-dependent but structurally equivalent

---

## 4. SCALE IDENTIFIERS

| Scale | Code |
|------|------|
| Mini | M |
| Standard | S |
| Stage | T |

---

## 5. GESTURE VECTOR MODEL

Each excitation event is represented as:

:contentReference[oaicite:0]{index=0}

Where:

- A = attack energy
- E = excitation intensity
- D = decay profile
- R = resonance activation

---

## 6. SCALE TRANSFORMATION FUNCTION

Each scale applies a transformation to the same gesture vector:

:contentReference[oaicite:1]{index=1}

Where:

- Tscale = mechanical + acoustic transfer function of instrument body

---

## 7. CROSS-SCALE NORMALIZATION RULE

To preserve musical identity:

:contentReference[oaicite:2]{index=2}

This does NOT mean identical output.

It means:

> equivalent perceived gesture structure

---

## 8. ATTACK BEHAVIOR MAPPING

| Scale | Attack Character |
|------|------------------|
| Mini | sharp, immediate, high-resolution |
| Standard | rounded, balanced, expressive |
| Stage | expanded, weighted, spatial |

---

## 9. DECAY BEHAVIOR MAPPING

Decay is not normalized directly.

Instead:

:contentReference[oaicite:3]{index=3}

Where:

- τ increases with physical scale
- Mini → shortest decay window
- Stage → longest decay field

---

## 10. RESONANCE COUPLING RULE

:contentReference[oaicite:4]{index=4}

Behavior:

- Mini → minimal environmental coupling
- Standard → balanced internal/external coupling
- Stage → strong room-field interaction

---

## 11. PLAYING CONSISTENCY RULE

A gesture performed identically across all scales must satisfy:

- same attack intent
- same energy profile shape
- same articulation class
- different acoustic manifestation

---

## 12. SCALE INTERPRETATION LAYER (FIRMWARE RELEVANCE)

Firmware must not convert audio.

It must normalize:

- gesture detection thresholds
- decay classification
- excitation classification

NOT waveform output.

---

## 13. SYSTEM CONSEQUENCE

This matrix enables:

- interchangeable performance vocabulary across instruments
- ensemble compatibility across scales
- compositional portability

---

## 14. FINAL STATEMENT

Spectral String is not a set of instruments.

It is a **single gestural language expressed through multiple physical bodies**.
