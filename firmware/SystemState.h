#pragma once

#include "physics/Constants.h"

struct StringEvent {
    float amplitude;
    float position;
    float velocity;
};

struct SystemStateData {
    float tension;
    float energy;
    float phase;
};

class SystemState {
public:
    void initialize();
    void update(const StringEvent& event);
    const SystemStateData& get() const;

private:
    SystemStateData state;
};
