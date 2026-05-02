# Voice Calibration Model

Each Voice is defined as a target function over three domains:

## 1. Time domain response
- transient onset shape
- decay envelope
- sustain stability

## 2. Frequency domain response
- harmonic distribution
- spectral centroid drift
- overtone suppression/enhancement

## 3. Coupling domain
- inter-string interaction (if applicable)
- body resonance injection
- damping nonlinearity

---

## Calibration Objective

Minimize:

    ΔV = |Measured Voice Response - Reference Voice Curve|

Subject to physical constraints of:

- material stiffness
- string tension bounds
- enclosure resonance modes
