# Measurement Pipeline

## Stage 1 — Excitation

Mechanical actuator applies controlled impulse:

- pluck force
- strike velocity
- sustained excitation sweep

---

## Stage 2 — Capture

Sensors record:

- string displacement
- body vibration (accelerometer array)
- piezo transduction output
- optional air microphone reference

---

## Stage 3 — Spectral Extraction

Convert raw signal into:

- FFT spectrum
- envelope curve
- decay function
- coupling response matrix

---

## Stage 4 — Voice Matching

Compare against reference curve:

- spectral deviation (Δf)
- transient deviation (Δt)
- coupling deviation (Δc)

Output:

    Voice Match Score (0–1.0)
