# Sensor Layout

## 1. Design Principle

Sensors do not define behavior.

They observe **physical state without interfering with it**.

---

## 2. Allowed Sensor Zones

### A. String Path (Primary)
- capacitive linear strip
- measures displacement envelope
- must not affect stiffness

---

### B. Bridge Region (Secondary)
- pressure sensing
- detects energy transfer into structure
- used for transient classification

---

### C. Body Frame (Global)
- accelerometer (optional)
- captures macro vibration field
- used for stability estimation only

---

## 3. Placement Constraints

- no sensor may touch string directly in a damping-capable way
- no adhesive mass that alters resonance profile
- all sensing layers must be mechanically neutral

---

## 4. Sampling Philosophy

Sensor data is NOT event data.

It is:

- continuous field sampling
- not note triggering
- not velocity encoding

---

## 5. Invalid Architectures

- fret-based switches
- segmented position encoding
- discrete “button-like” sensing zones

The system must remain spatially continuous.
