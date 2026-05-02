# Impedance Fixture Specification

## Purpose

The impedance fixture enforces a controlled electrical loading environment for piezoelectric and buffer-stage calibration.

It ensures that electrical behavior remains consistent across all Voice evaluations.

---

## 1. Electrical Baseline

### Input Impedance Standard
- Minimum: 10 MΩ
- Maximum variance: ±2%

This ensures:
- stable low-frequency response
- predictable charge transfer behavior
- repeatable transient measurement

---

## 2. Load Simulation Network

The fixture must support:

- resistive loading profiles
- capacitive loading simulation
- variable impedance emulation for stress testing

---

## 3. Buffer Behavior Validation

The fixture validates:

- JFET input stability
- gate leakage behavior
- noise floor consistency

---

## 4. Signal Integrity Requirements

- noise floor below calibration threshold
- no parasitic oscillation at high gain
- stable DC offset across temperature range

---

## Summary

The impedance fixture enforces *electrical determinism* in a system defined by mechanical variability.
