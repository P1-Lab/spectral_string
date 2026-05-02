/*
    VoiceStateMatrix.cpp
    Spectral String / NRE Core Voice System

    PURPOSE:
    Converts abstract "voice families" into deterministic physical state vectors.

    This is the point where:
        ORCHESTRAL CORE
        DARK MASS
        WOOD RESONANT
        SPLIT TRANSIENT
        METAL HYBRID
        DRY STUDY INSTRUMENT
        ROOM-COUPLED

    become actual parameterized physics configurations.
*/

#include "VoiceStateMatrix.h"

namespace SS {

// -----------------------------
// VOICE STATE DEFINITIONS
// -----------------------------

struct VoiceState
{
    float damping;
    float massBias;
    float coupling;
    float spectralTilt;
    float resonanceQ;
};

// -----------------------------
// MATRIX RESOLUTION
// -----------------------------

static VoiceState resolveVoice(VoiceType v)
{
    switch (v)
    {
        case VoiceType::ORCHESTRAL_CORE:
            return {0.50f, 1.00f, 0.55f, 0.00f, 0.70f};

        case VoiceType::DARK_MASS:
            return {0.30f, 2.10f, 0.80f, -0.35f, 0.95f};

        case VoiceType::WOOD_RESONANT:
            return {0.55f, 1.20f, 0.75f, +0.15f, 0.85f};

        case VoiceType::SPLIT_TRANSIENT:
            return {0.85f, 0.85f, 0.25f, +0.25f, 0.40f};

        case VoiceType::METAL_HYBRID:
            return {0.40f, 1.60f, 0.95f, +0.45f, 1.10f};

        case VoiceType::DRY_STUDY:
            return {0.95f, 1.00f, 0.10f, 0.00f, 0.20f};

        case VoiceType::ROOM_COUPLED:
            return {0.25f, 1.30f, 1.20f, -0.10f, 1.40f};
    }

    return {0.5f, 1.0f, 0.5f, 0.0f, 0.7f};
}

// -----------------------------
// PUBLIC API
// -----------------------------

VoiceState VoiceStateMatrix::getState(VoiceType v)
{
    return resolveVoice(v);
}

float VoiceStateMatrix::applyDamping(VoiceType v, float signal)
{
    return signal * resolveVoice(v).damping;
}

float VoiceStateMatrix::applyCoupling(VoiceType v, float signal)
{
    return signal * resolveVoice(v).coupling;
}

} // namespace SS
