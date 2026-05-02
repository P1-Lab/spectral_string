#pragma once

#include "../SystemState.h"
#include "SpectralField.h"

class NRE_StateResolver {
public:
    void initialize();
    SpectralState resolve(const SystemState& state);
};
