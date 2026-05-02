#include "SystemState.h"
#include "StateKernel.h"
#include "input/StringScanner.h"
#include "nre/NRE_StateResolver.h"
#include "io/AudioOutput.h"

SystemState systemState;

StringScanner scanner;
NRE_StateResolver resolver;
AudioOutput audio;

void setup() {
    systemState.initialize();
    scanner.initialize();
    resolver.initialize();
    audio.initialize();
}

void loop() {
    // 1. Scan physical string excitation
    StringEvent event = scanner.sample();

    // 2. Update deterministic system state
    systemState.update(event);

    // 3. Resolve spectral state (NRE core)
    SpectralState spectral = resolver.resolve(systemState);

    // 4. Output audio stream
    audio.render(spectral);
}
