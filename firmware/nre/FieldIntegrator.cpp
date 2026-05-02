#include "SpectralField.h"

float integrateField(const SpectralState& s) {
    return s.frequency * s.amplitude * s.harmonicDensity;
}
