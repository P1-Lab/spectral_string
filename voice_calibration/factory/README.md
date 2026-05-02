# FACTORY_LAYER // REV_2026.01 // TRUTH_STATE

---

## 01_PURPOSE

This defines the manufacturing truth-state.

It is the physical reference layer that all systems must conform to.

If a unit fails these tolerances, it is not a valid instrument instance.

---

## 02_PHYSICAL_DEFINITION

| Parameter      | Value (Imperial Primary) | Metric Equivalent |
|----------------|--------------------------|------------------|
| TOTAL_LENGTH   | 24.4 in                  | 620 mm           |
| STRING_SPAN    | 21.3 in (bridge to nut) | 540 mm           |
| BODY_WIDTH     | 3.35 in                  | 85 mm            |
| BODY_DEPTH     | 1.10 in                  | 28 mm            |
| TUNING SYSTEM  | φ-based lever mechanism  | —                |

---

## 03_ELECTRONICS_CAVITY (CRITICAL)

### Location
- Underside rear section of instrument body

### Dimensions (Machined Pocket)

| Parameter | Value |
|----------|------|
| Length   | 5.51 in |
| Width    | 2.17 in |
| Depth    | 0.71 in |

### Mechanical Constraints

- PCB must be mechanically constrained on all four edges
- Maximum standoff height: 0.14 in
- No floating or suspended PCB mounting allowed
- All components must clear cavity ceiling by ≥ 0.24 in

---

## 04_CALIBRATION_PHILOSOPHY

> Calibration is not tuning.  
> It is the enforcement of identical mechanical-to-spectral transfer behavior across all builds.

---

## SYSTEM_IDENTITY_RULE

EXCITATION + DECAY + HARMONIC FIELD = IDENTICAL INSTANCE

---

## END OF FILE
ARCHITECTURE_OF_NECESSITY_PROTOCOL
