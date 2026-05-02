/*
    VoiceCalibrationEngine.cpp
    Spectral String / Factory Truth Layer

    PURPOSE:
    Executes full voice-state validation by comparing:

        - expected VoiceStateMatrix behavior
        - measured physical response curves
        - cross-scale normalization consistency

    This is the final pass/fail gate for instrument legitimacy.
*/

#include "VoiceCalibrationEngine.h"
#include "VoiceStateMatrix.h"

namespace SS {

// -----------------------------
// MEASURED DATA STRUCTURE
// -----------------------------

struct MeasurementSet
{
    float frequencyResponse[8];
    float decayCurve;
    float harmonicStability;
    float crossNodePhase;
};

// -----------------------------
// INTERNAL COMPARISON UTILITIES
// -----------------------------

static float absDiff(float a, float b)
{
    return (a > b) ? (a - b) : (b - a);
}

static float computeCurveDeviation(const float* measured, const float* reference, int size)
{
    float error = 0.0f;

    for (int i = 0; i < size; i++)
        error += absDiff(measured[i], reference[i]);

    return error / (float)size;
}

// -----------------------------
// REFERENCE MODEL GENERATOR
// -----------------------------

static void generateReferenceCurve(VoiceType v, float* outCurve)
{
    VoiceState s = VoiceStateMatrix::getState(v);

    /*
        Simplified spectral projection model:
        damping + coupling + spectral tilt define curve envelope
    */

    for (int i = 0; i < 8; i++)
    {
        float base = 1.0f - (i * 0.1f);

        outCurve[i] =
            base *
            (1.0f - s.damping) *
            (1.0f + s.spectralTilt);
    }
}

// -----------------------------
// VALIDATION CORE
// -----------------------------

CalibrationResult VoiceCalibrationEngine::validate(
    VoiceType voice,
    const MeasurementSet& m)
{
    float referenceCurve[8];
    generateReferenceCurve(voice, referenceCurve);

    float curveError =
        computeCurveDeviation(m.frequencyResponse, referenceCurve, 8);

    VoiceState expected = VoiceStateMatrix::getState(voice);

    // -----------------------------
    // ERROR METRICS
    // -----------------------------

    float decayError =
        absDiff(m.decayCurve, expected.resonanceQ);

    float harmonicError =
        absDiff(m.harmonicStability, expected.coupling);

    float phaseError =
        absDiff(m.crossNodePhase, expected.massBias);

    // -----------------------------
    // COMPOSITE SCORE
    // -----------------------------

    float totalError =
        curveError * 0.45f +
        decayError * 0.25f +
        harmonicError * 0.20f +
        phaseError * 0.10f;

    CalibrationResult result;

    result.voice = voice;
    result.errorScore = totalError;

    // -----------------------------
    // PASS / FAIL LOGIC
    // -----------------------------

    result.passed = (totalError < 0.12f);

    if (!result.passed)
    {
        result.failureMode =
            (curveError > 0.2f)   ? FailureMode::SPECTRAL_MISMATCH :
            (decayError > 0.2f)   ? FailureMode::DECAY_DRIFT :
            (harmonicError > 0.2f)? FailureMode::COUPLING_ERROR :
                                    FailureMode::PHASE_INSTABILITY;
    }

    return result;
}

// -----------------------------
// FACTORY GATE ENTRY POINT
// -----------------------------

bool VoiceCalibrationEngine::factoryApproval(
    VoiceType voice,
    const MeasurementSet& m)
{
    CalibrationResult r = validate(voice, m);

    return r.passed;
}

} // namespace SS
