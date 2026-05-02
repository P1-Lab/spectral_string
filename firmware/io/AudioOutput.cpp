#include "AudioOutput.h"

void AudioOutput::initialize() {
    // DAC / audio subsystem init placeholder
}

void AudioOutput::render(const SpectralState& state) {
    // deterministic output mapping (placeholder)
    float signal = state.frequency * state.amplitude;

    (void)signal; // replace with DAC output in hardware build
}
