#include "PhiGovernor.h"
#include "../physics/Constants.h"

float PhiGovernor::mapToSpectralField(float input) {
    return input * PHI;
}
