/*
    ScaleFieldAdapter.cpp
    Spectral String / NRE Integration Layer

    PURPOSE:
    Translates scale-normalized physical behavior into the
    Non-Random Excitation (NRE) spectral field system.

    This is the final bridge:
        Physics → Gesture → Scale → Spectral Field
*/

#include "ScaleFieldAdapter.h"
#include "../physics/ScaleResolver.h"
#include "../physics/InstrumentMassModel.h"

namespace SS {

// -----------------------------
// FIELD STATE
// -----------------------------

struct FieldState
{
    float density;
    float coherence;
    float dispersion;
};

// -----------------------------
// INTERNAL FIELD COMPUTATION
// -----------------------------

static FieldState computeField()
{
    MassState mass = InstrumentMassModel::compute();

    FieldState f;

    // density increases with system mass
    f.density = mass.bodyMass * 0.75f;

    // coherence decreases with excessive inertia
    f.coherence = 1.0f / (1.0f + mass.inertiaCoefficient);

    // dispersion increases with scale mismatch
    f.dispersion =
        (ScaleResolver::getLengthScale() -
         ScaleResolver::getTensionScale()) * 0.5f;

    return f;
}

// -----------------------------
// PUBLIC NRE INTERFACE
// -----------------------------

float ScaleFieldAdapter::getSpectralDensity()
{
    return computeField().density;
}

float ScaleFieldAdapter::getCoherence()
{
    return computeField().coherence;
}

float ScaleFieldAdapter::getDispersion()
{
    return computeField().dispersion;
}

// -----------------------------
// FIELD NORMALIZATION OUTPUT
// -----------------------------

SpectralField ScaleFieldAdapter::resolve(const GestureVector& g)
{
    FieldState f = computeField();

    SpectralField out;

    out.energy = g.energy * f.density;
    out.stability = g.sustainWeight * f.coherence;
    out.chaos = g.attackSharpness * f.dispersion;

    return out;
}

} // namespace SS
