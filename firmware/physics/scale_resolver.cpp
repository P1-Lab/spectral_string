/*
    ScaleResolver.cpp
    Spectral String / Unified Scale System

    PURPOSE:
    Resolves instrument-scale-dependent behavior (Mini / Standard / Stage)
    into a shared normalized physics space.

    This is the bridge between:
    - physical instrument size
    - gesture normalization engine
    - mass/inertia model
*/

#include "ScaleResolver.h"

namespace SS {

// -----------------------------
// INTERNAL SCALE STATE
// -----------------------------

static ScaleMode currentMode = ScaleMode::STANDARD;

// -----------------------------
// SCALE METRICS TABLE
// -----------------------------

struct ScaleProfile
{
    float lengthFactor;
    float massFactor;
    float tensionFactor;
};

static ScaleProfile resolveProfile(ScaleMode mode)
{
    switch (mode)
    {
        case ScaleMode::MINI:
            return {0.60f, 0.45f, 1.25f};

        case ScaleMode::STANDARD:
            return {1.00f, 1.00f, 1.00f};

        case ScaleMode::STAGE:
            return {1.85f, 2.10f, 0.85f};
    }

    return {1.0f, 1.0f, 1.0f};
}

// -----------------------------
// PUBLIC API
// -----------------------------

void ScaleResolver::setMode(ScaleMode mode)
{
    currentMode = mode;
}

ScaleMode ScaleResolver::getMode()
{
    return currentMode;
}

float ScaleResolver::getLengthScale()
{
    return resolveProfile(currentMode).lengthFactor;
}

float ScaleResolver::getMassScale()
{
    return resolveProfile(currentMode).massFactor;
}

float ScaleResolver::getTensionScale()
{
    return resolveProfile(currentMode).tensionFactor;
}

} // namespace SS
