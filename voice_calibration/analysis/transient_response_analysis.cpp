#include <cmath>

struct TransientProfile {
    float attackTime;
    float decaySlope;
    float sustainStability;
};

struct TransientDeviation {
    float attackError;
    float decayError;
    float sustainError;
};

TransientDeviation analyzeTransient(
    TransientProfile measured,
    TransientProfile reference
) {
    TransientDeviation d;

    d.attackError = fabs(measured.attackTime - reference.attackTime)
                    / reference.attackTime;

    d.decayError = fabs(measured.decaySlope - reference.decaySlope)
                   / fabs(reference.decaySlope);

    d.sustainError = fabs(measured.sustainStability - reference.sustainStability)
                     / reference.sustainStability;

    return d;
}
