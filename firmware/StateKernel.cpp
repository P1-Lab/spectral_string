#include "SystemState.h"

void SystemState::initialize() {
    state.tension = DEFAULT_TENSION;
    state.energy = 0.0f;
    state.phase = 0.0f;
}

void SystemState::update(const StringEvent& event) {
    state.energy = 0.98f * state.energy + event.amplitude * event.velocity;
    state.phase += event.position * state.tension;

    if (state.phase > 1.0f) {
        state.phase -= 1.0f;
    }
}

const SystemStateData& SystemState::get() const {
    return state;
}
