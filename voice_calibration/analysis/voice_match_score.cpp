#include "SpectralField.h"

struct VoiceScore {
    float score;
    bool pass;
};

VoiceScore evaluateVoice(
    float spectralError,
    float transientError,
    float couplingError
) {
    VoiceScore v;

    float weighted =
        spectralError * 0.45f +
        transientError * 0.35f +
        couplingError * 0.20f;

    v.score = 1.0f - weighted;

    // Hard acceptance threshold (manufacturing gate)
    v.pass = (v.score >= 0.85f);

    return v;
}
