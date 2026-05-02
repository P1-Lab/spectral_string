float VoiceMatchScore(SpectralState measured, SpectralState reference) {

    float spectralError = abs(measured.frequency - reference.frequency);
    float transientError = abs(measured.amplitude - reference.amplitude);
    float harmonicError  = abs(measured.harmonicDensity - reference.harmonicDensity);

    float score =
        1.0f - (spectralError * 0.4f +
                transientError * 0.3f +
                harmonicError * 0.3f);

    return clamp(score, 0.0f, 1.0f);
}
