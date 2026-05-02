# Voice Calibration System
## Factory Truth Layer — Spectral String

This directory defines the physical validation system for voice-state consistency across all instrument builds.

It is the final authority layer between:
- hardware fabrication
- firmware behavior
- measured acoustic output

---

## Core Principle

A voice is not valid unless it matches its measured physical response curve.

All instruments must converge on identical transfer behavior per voice state.

---

## Directory Contents

- measurement_protocol.md
- voice_reference_curves.md
- calibration_rig_spec.md
- acceptance_thresholds.md
- factory_test_suite.md

---

## Validation Philosophy

Calibration is not tuning.

It is **forcing physical reality to match the VoiceStateMatrix model.**

If it does not match:
→ the instrument is out of spec
