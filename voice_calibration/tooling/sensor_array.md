# Sensor Array Specification

## Purpose

The sensor array captures multi-domain physical response of the instrument during excitation.

It forms the measurement backbone of Voice calibration.

---

## 1. Primary Sensor Node

### Piezo Reference Node
- 35–38 mm brass-backed piezo capsule
- mechanically rigid coupling
- high-impedance buffered output (>10 MΩ system requirement)

Role:
- primary vibration-to-electrical transduction point

---

## 2. Structural Vibration Sensors

### Accelerometer Array
- tri-axis MEMS accelerometers
- mounted on enclosure body
- rigid coupling to wood structure

Role:
- measure enclosure resonance modes
- capture coupling transfer behavior

---

## 3. Optional Optical Measurement

### Laser Displacement (LDV class)
- non-contact surface velocity measurement
- used for validation sampling only

Role:
- ground truth displacement reference
- cross-validation of piezo response

---

## 4. Synchronization Requirements

- all sensors time-aligned to shared clock reference
- sampling drift < 1 ms across channels
- deterministic capture window per excitation event

---

## Summary

The sensor array defines the *physical truth reconstruction layer* of the instrument system.
