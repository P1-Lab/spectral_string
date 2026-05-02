# Material Substrate Model  
## Spectral String — Physical Excitation Layer Classification

This document defines how physical materials function as **signal substrates** within the Spectral String system.

Materials are not treated as passive components.  
They are treated as **state-generating physical systems** that define how excitation enters the Nodal Response Engine (NRE).

---

# 1. Core Principle

All sound begins as:

> mechanical energy interacting with a tensioned substrate under constraint

The substrate determines:

- entropy of excitation input  
- stability of harmonic formation  
- transient behavior characteristics  
- drift over time (if any)  
- resolution limits of sensing interpretation  

The substrate is therefore not “material choice” but:

> a configuration of physical behavior under excitation

---

# 2. Substrate Classes

## A. Low-Entropy Substrates (Steel-Class Systems)

### Examples
- stainless steel strings
- phosphor bronze strings (stabilized alloys)

### Physical Characteristics
- near-linear elastic response
- high tension stability
- predictable harmonic structure
- minimal environmental drift

### Spectral Behavior
- clean harmonic convergence
- fast transient stabilization
- low internal noise floor

### NRE Interpretation
- high determinism input
- stable mapping to spectral field
- minimal correction required

### Design Role in Spectral String
Default baseline substrate for:
- Monos systems
- ensemble modes
- precision articulation modes

---

## B. Controlled-Instability Substrates (Hybrid Gut-Class Systems)

### Examples
- Pirastro Passione-type composite gut/metal systems
- synthetic-core hybrid strings

### Physical Characteristics
- nonlinear elasticity under load
- moderate environmental sensitivity
- controlled viscoelastic drift
- rich transient deformation

### Spectral Behavior
- organic envelope shaping
- slight pitch centroid movement under excitation
- increased harmonic density variance

### NRE Interpretation
- medium entropy input stream
- requires adaptive stabilization mapping
- enhances spectral richness without loss of coherence

### Design Role in Spectral String
Used for:
- expressive solo performance layers
- bowed or friction-based excitation
- systems requiring controlled instability as musical material

---

## C. High-Entropy Substrates (Pure Gut-Class Systems)

### Examples
- traditional gut strings (untreated or lightly wound)

### Physical Characteristics
- strong humidity and temperature sensitivity
- nonlinear tension response
- slow-state drift behavior
- viscoelastic memory effects

### Spectral Behavior
- broad harmonic diffusion
- slower transient settling
- strong subharmonic presence
- temporal instability in pitch centering

### NRE Interpretation
- high entropy excitation source
- requires time-aware spectral tracking
- treated as dynamic system rather than fixed reference

### Design Role in Spectral String
Used for:
- experimental modes
- thermodynamic or “living field” interpretations
- expressive instability as primary feature

---

## D. Excitation Transfer Substrates (Bow System Class)

### Examples
- carbon fiber bows (e.g., CodaBow Diamond GX class)
- pernambuco bows (traditional analog systems)

### Physical Characteristics
- friction-controlled energy transfer
- variable pressure-response curves
- directional excitation vector shaping

### Spectral Behavior
- continuous energy injection
- controllable attack shaping
- fine-grained articulation control

### NRE Interpretation
- does NOT define spectral mapping
- defines excitation profile into substrate
- acts as input modulation layer

### Design Role in Spectral String
Used for:
- bowed modes
- continuous excitation regimes
- vertical or planar friction-based performance

---

# 3. Substrate Interaction Rules

## 3.1 Substrates are not interchangeable without system awareness

Changing substrate class changes:

- NRE stabilization requirements
- sensor interpretation scaling
- transient response models

---

## 3.2 Hybrid systems are valid but must be declared

Mixing substrates is allowed only when explicitly designed:

Example:
- steel core + gut winding → controlled instability system
- hybrid bow + steel string → precision excitation system

---

## 4. Environmental Coupling

Substrates respond differently to:

- humidity
- temperature
- mechanical fatigue
- excitation frequency density

Only Low-Entropy Substrates assume environmental invariance.

All others include environmental coupling as part of their behavior model.

---

## 5. System-Level Constraint

Spectral String does not normalize material behavior.

Instead:

> the NRE system must adapt to substrate physics, not override it

This preserves the instrument’s status as a physical system rather than a simulated one.

---

## 6. Architectural Implication

The full system pipeline is therefore:
