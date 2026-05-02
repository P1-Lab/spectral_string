#include <cmath>
#include "SpectralField.h"

struct DeviationResult {
    float frequencyError;
    float amplitudeError;
    float harmonicError;
};

DeviationResult computeSpectralDeviation(
    SpectralState measured,
    SpectralState reference
) {
    DeviationResult d;

    d.frequencyError = fabs(measured.frequency - reference.frequency)
                       / reference.frequency;

    d.amplitudeError = fabs(measured.amplitude - reference.amplitude)
                       / reference.amplitude;

    d.harmonicError = fabs(measured.harmonicDensity - reference.harmonicDensity)
                      / reference.harmonicDensity;

    return d;
}
