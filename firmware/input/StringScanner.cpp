#include "StringScanner.h"

void StringScanner::initialize() {
    // hardware init placeholder
}

StringEvent StringScanner::sample() {
    StringEvent e;

    // Placeholder deterministic input model
    e.amplitude = 0.5f;
    e.position = 0.3f;
    e.velocity = 0.8f;

    return e;
}
