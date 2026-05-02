/*
    EnsembleCoherenceModel.cpp
    Spectral String / Multi-Instrument Performance Layer

    PURPOSE:
    Ensures multiple instruments (Mini / Standard / Stage)
    behave as a coherent musical system rather than independent units.

    This governs:
        - timing alignment
        - spectral overlap control
        - shared field stability
*/

#include "EnsembleCoherenceModel.h"
#include "../firmware/physics/ScaleResolver.h"
#include "../firmware/nre/VoiceStateMatrix.h"

namespace SS {

// -----------------------------
// ENSEMBLE STATE
// -----------------------------

struct EnsembleState
{
    float timingDrift;
    float spectralOverlap;
    float phaseLock;
};

// -----------------------------
// COHERENCE MODEL
// -----------------------------

static EnsembleState computeCoherence(VoiceType a, VoiceType b)
{
    VoiceState va = VoiceStateMatrix::getState(a);
    VoiceState vb = VoiceStateMatrix::getState(b);

    EnsembleState s;

    // timing drift emerges from mass + damping mismatch
    s.timingDrift =
        abs(va.massBias - vb.massBias) * 0.6f;

    // spectral overlap is coupling interaction
    s.spectralOverlap =
        (va.coupling + vb.coupling) * 0.5f;

    // phase lock depends on damping symmetry
    s.phaseLock =
        1.0f - abs(va.damping - vb.damping);

    return s;
}

// -----------------------------
// PUBLIC ENSEMBLE API
// -----------------------------

float EnsembleCoherenceModel::computeStability(VoiceType a, VoiceType b)
{
    EnsembleState s = computeCoherence(a, b);

    /*
        Stability collapses if:
        - timing drift too high
        - phase lock too low
    */

    float stability =
        (s.phaseLock * 0.5f) +
        (s.spectralOverlap * 0.3f) -
        (s.timingDrift * 0.2f);

    return stability;
}

// -----------------------------
// ENSEMBLE WARNING SYSTEM
// -----------------------------

bool EnsembleCoherenceModel::isStable(VoiceType a, VoiceType b)
{
    return computeStability(a, b) > 0.65f;
}

} // namespace SS
