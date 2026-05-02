#pragma once
#include "../nre/SpectralField.h"

class AudioOutput {
public:
    void initialize();
    void render(const SpectralState& state);
};
