/*
    GestureTranslationLayer.cpp
    Spectral String / Performance System

    PURPOSE:
    Converts calibrated physical gesture data into performance-ready
    expressive control signals.

    This is the layer where:
        physics → becomes articulation
        measurement → becomes phrasing
*/

#include "GestureTranslationLayer.h"
#include "../firmware/physics/GestureNormalizationEngine.h"
#include "../firmware/nre/VoiceStateMatrix.h"

namespace SS {

// -----------------------------
// INTERNAL EXPRESSIVE STATE
// -----------------------------

struct GestureExpression
{
    float attack;
    float sustain;
    float microVariation;
    float expressiveWeight;
};

// -----------------------------
// EXPRESSION MAPPING
// -----------------------------

static GestureExpression mapGesture(const GestureVector& g, VoiceType voice)
{
    VoiceState v = VoiceStateMatrix::getState(voice);

    GestureExpression e;

    // attack shaped by rigidity + damping behavior
    e.attack =
        g.attackSharpness *
        (1.0f - v.damping);

    // sustain shaped by coupling + mass bias
    e.sustain =
        g.sustainWeight *
        (0.5f + v.coupling);

    // micro-variation emerges from spectral instability
    e.microVariation =
        g.energy * v.spectralTilt * 0.25f;

    // expressive weight is full system interaction
    e.expressiveWeight =
        (e.attack + e.sustain) * (1.0f + v.massBias);

    return e;
}

// -----------------------------
// PUBLIC PERFORMANCE API
// -----------------------------

PerformanceSignal GestureTranslationLayer::translate(
    const GestureVector& g,
    VoiceType voice)
{
    GestureExpression e = mapGesture(g, voice);

    PerformanceSignal out;

    /*
        The output is no longer “signal strength”
        but a structured expressive vector
    */

    out.transient = e.attack;
    out.body      = e.sustain;
    out.motion    = e.microVariation;
    out.intensity = e.expressiveWeight;

    return out;
}

// -----------------------------
// ARTICULATION NORMALIZATION
// -----------------------------

float GestureTranslationLayer::normalizeAttack(float raw)
{
    return raw * 0.8f + (raw * raw * 0.2f);
}

} // namespace SS
