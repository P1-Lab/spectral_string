/*
    GestureNormalizationEngine.cpp
    Spectral String / Unified Instrument System

    PURPOSE:
    Converts raw physical interaction data (force, position, velocity)
    into normalized gesture vectors that remain consistent across:

        - Mini Node
        - Standard Node
        - Stage Node

    This ensures that "gesture meaning" is invariant across scale.
*/

#include "GestureNormalizationEngine.h"
#include "Constants.h"
#include "PhiGovernor.h"
#include "GravityModel.h"

namespace SS {

// -----------------------------
// INTERNAL STATE
// -----------------------------

static float scaleFactor = 1.0f;
static float inertiaBias  = 0.0f;

// -----------------------------
// SCALE REGIME LOADER
// -----------------------------

void GestureNormalizationEngine::setScaleMode(ScaleMode mode)
{
    switch (mode)
    {
        case ScaleMode::MINI:
            scaleFactor = 0.65f;
            inertiaBias = -0.25f;
            break;

        case ScaleMode::STANDARD:
            scaleFactor = 1.0f;
            inertiaBias = 0.0f;
            break;

        case ScaleMode::STAGE:
            scaleFactor = 1.75f;
            inertiaBias = +0.35f;
            break;
    }
}

// -----------------------------
// RAW INPUT STRUCTURE
// -----------------------------

GestureVector GestureNormalizationEngine::processRawInput(const RawGesture& input)
{
    /*
        Input space:
        - force (N)
        - velocity (m/s equivalent mechanical proxy)
        - position (normalized 0–1 across string span)
    */

    float forceNorm    = input.force * scaleFactor;
    float velocityNorm = input.velocity * PhiGovernor::velocityBias();
    float positionNorm = input.position;

    // Gravity model introduces “felt resistance”
    float gravityComp = GravityModel::localField(input.contactDepth);

    GestureVector out;

    out.energy = (forceNorm * velocityNorm) - gravityComp;
    out.position = positionNorm;

    // Apply scale-aware inertia shaping
    out.attackSharpness =
        (input.velocity / (1.0f + inertiaBias));

    out.sustainWeight =
        forceNorm * (1.0f + inertiaBias);

    return out;
}

// -----------------------------
// NORMALIZATION CHECKSUM
// -----------------------------

bool GestureNormalizationEngine::validate(const GestureVector& g)
{
    return (g.energy >= 0.0f && g.energy < Constants::MAX_ENERGY_FLOOR);
}

} // namespace SS
