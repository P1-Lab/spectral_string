/*
    InstrumentMassModel.cpp
    Spectral String / Physical Inertia Model

    PURPOSE:
    Converts physical instrument scale into dynamic response inertia.

    This determines:
    - attack latency behavior
    - decay stability
    - string response inertia under excitation
*/

#include "InstrumentMassModel.h"
#include "ScaleResolver.h"

namespace SS {

// -----------------------------
// BASE MASS CONSTANTS
// -----------------------------

static constexpr float BASE_STRING_MASS   = 0.012f;
static constexpr float BASE_BODY_MASS     = 1.000f;
static constexpr float BASE_BRIDGE_MASS   = 0.085f;

// -----------------------------
// MASS MODEL COMPUTATION
// -----------------------------

MassState InstrumentMassModel::compute()
{
    float scaleM = ScaleResolver::getMassScale();

    MassState state;

    state.stringMass = BASE_STRING_MASS * (0.8f + scaleM);
    state.bodyMass   = BASE_BODY_MASS   * scaleM;
    state.bridgeMass = BASE_BRIDGE_MASS * (0.5f + scaleM);

    // derived inertia coupling coefficient
    state.inertiaCoefficient =
        (state.bodyMass * 0.6f) +
        (state.bridgeMass * 0.3f);

    return state;
}

// -----------------------------
// RESPONSE TIMING MODEL
// -----------------------------

float InstrumentMassModel::attackLag()
{
    MassState m = compute();

    return 1.0f / (1.0f + m.inertiaCoefficient);
}

float InstrumentMassModel::decayStability()
{
    MassState m = compute();

    return (m.bodyMass / (1.0f + m.stringMass));
}

} // namespace SS
