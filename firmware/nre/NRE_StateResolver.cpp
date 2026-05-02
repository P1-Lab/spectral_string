#include "NRE_StateResolver.h"
#include "../physics/PhiGovernor.h"
#include "../physics/GravityModel.h"

PhiGovernor phi;
GravityModel gravity;

void NRE_StateResolver::initialize() {}

SpectralState NRE_StateResolver::resolve(const SystemState& state) {
    SpectralState s;

    float energy = state.get().energy;

    s.frequency = phi.mapToSpectralField(energy * 440.0f);
    s.amplitude = gravity.apply(energy, state.get().tension);
    s.harmonicDensity = energy * 1.5f;

    return s;
}
