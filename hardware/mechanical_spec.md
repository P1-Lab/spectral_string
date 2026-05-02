# Spectral String — Mechanical Specification (v1.0)

## 1. Instrument Class

Spectral String is a **continuous excitation acoustic instrument** based on tensioned string physics with embedded sensing.

It is not a controller, not a keyboard, and not a trigger surface.

The mechanical system must remain fully playable without power.

---

## 2. Structural Layout

### Core Architecture

- 1 or 2 tensioned strings (Monos / Duos)
- rigid beam body (non-resonant primary structure)
- distributed sensing along string path
- optional contact surface beneath string plane

---

## 3. String System

### Material

- stainless steel or phosphor bronze (preferred)
- optional hybrid: coated steel for reduced finger noise

### Tension Range

- Low: 40–60 N (expressive, slide-heavy mode)
- Nominal: 60–90 N (balanced performance)
- High: 90–120 N (precision / articulation mode)

### Mounting

- fixed bridge anchor (non-moving)
- floating tail anchor with micro-adjust compensation

---

## 4. Body Construction

### Materials (ranked)

1. **Maple (preferred)**
   - balanced stiffness and tactile feedback
2. Ash
   - brighter mechanical response
3. Carbon composite
   - maximum stability, minimal coloration

### Structural Rule

The body must behave as:

> a reference inertial frame, not a resonant instrument body

---

## 5. Playing Surfaces

### Permitted Interaction Zones

- string (primary excitation)
- top beam surface (secondary tactile control)
- side edge (gesture articulation)
- underside coupling surface (optional resonance coupling)

No fixed “zones” are marked physically.

Interaction is spatially continuous.

---

## 6. Sensor Integration

### Allowed Sensor Types

- linear capacitive strip (string position)
- pressure sensing (force envelope)
- optional accelerometer (global excitation tracking)

### Placement Rule

Sensors must not alter mechanical stiffness of the string path.

---

## 7. Lever System (Tuning Reference Switch)

### Function

Instant switching between global harmonic reference systems:

- A = 440 Hz (ensemble standard)
- A = 415 Hz (historical / solo tuning)

### Implementation Requirement

- must be a binary or detented mechanical switch
- must not physically retension string
- must operate at signal-processing layer

---

## 8. Orientation Modes

### Horizontal Mode
- Guqin-like interface
- compositional precision
- low inertia gestures

### Vertical Mode
- performance projection
- percussive articulation allowed
- higher energy excitation

Instrument must function identically in both orientations.

---

## 9. Design Constraint: Acoustic Integrity

The instrument must remain:

- playable with electronics OFF
- responsive without amplification
- mechanically stable under dynamic excitation

If the system requires power to “feel like an instrument,” it is invalid.

---

## 10. Mass Distribution

- central beam: high stiffness / low damping
- string anchors: high rigidity coupling
- sensor regions: neutral mass loading (no vibration sinks)

No component may introduce unintended sympathetic resonance unless explicitly designed.

---

## 11. Aesthetic Constraint (Functional, not decorative)

The instrument must visually communicate:

- tension
- structure
- precision
- physical causality

It must not resemble consumer MIDI hardware.

---

## 12. Certification Rule

A valid Spectral String build must:

- produce consistent pitch mapping across full string length
- exhibit stable transient response under repeated excitation
- maintain tuning reference shift (415/440) without mechanical drift
