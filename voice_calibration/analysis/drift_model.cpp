struct DriftState {
    float cumulativeSpectralDrift;
    float mechanicalWearIndex;
    float couplingRelaxation;
};

DriftState updateDrift(
    DriftState previous,
    float newSpectralError,
    float usageTime
) {
    DriftState d;

    d.cumulativeSpectralDrift =
        previous.cumulativeSpectralDrift * 0.9f + newSpectralError * 0.1f;

    d.mechanicalWearIndex =
        previous.mechanicalWearIndex + usageTime * 0.001f;

    d.couplingRelaxation =
        previous.couplingRelaxation + newSpectralError * 0.05f;

    return d;
}
