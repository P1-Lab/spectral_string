/*
    NRE_StringAdapter.cpp
    Spectral String Project
    Mechanical–Spectral Transduction Layer

    This module defines the bridge between:
    - physical string excitation (piezo / magnetic / contact mic)
    - deterministic spectral engine (NRE: Non-Random Excitation core)

    It does NOT perform synthesis.
    It normalizes physical input into stable spectral state vectors.
*/

#include "NRE_StringAdapter.h"
#include <cmath>
#include <vector>

// -----------------------------
// Internal Constants
// -----------------------------
static constexpr float SAMPLE_RATE = 48000.0f;
static constexpr float ENERGY_DECAY = 0.985f;
static constexpr float NOISE_FLOOR = 0.0003f;

// -----------------------------
// State Structure
// -----------------------------
struct StringState {
    float fundamental = 0.0f;
    float harmonic_profile[8] = {0};
    float transient_energy = 0.0f;
    float bow_pressure_est = 0.0f;
    float excitation_stability = 0.0f;
};

// -----------------------------
// Utility: simple spectral centroid
// -----------------------------
static float spectralCentroid(const std::vector<float>& fftMag) {
    float weightedSum = 0.0f;
    float magSum = 0.0f;

    for (size_t i = 0; i < fftMag.size(); ++i) {
        weightedSum += i * fftMag[i];
        magSum += fftMag[i];
    }

    return (magSum > 0.0f) ? (weightedSum / magSum) : 0.0f;
}

// -----------------------------
// Core Adapter Class
// -----------------------------
class NRE_StringAdapter {
public:
    NRE_StringAdapter() {
        state = StringState();
    }

    void processFrame(const std::vector<float>& inputSignal,
                      std::vector<float>& spectralOut) {

        // 1. Estimate raw energy
        float energy = computeEnergy(inputSignal);
        state.transient_energy = smooth(state.transient_energy, energy);

        // 2. Extract pseudo spectral representation
        std::vector<float> fftMag = pseudoFFT(inputSignal);

        // 3. Determine fundamental behavior
        state.fundamental = estimateFundamental(fftMag);

        // 4. Harmonic shaping (deterministic mapping)
        for (int i = 0; i < 8; i++) {
            state.harmonic_profile[i] = fftMag[i] * harmonicWeight(i);
        }

        // 5. Stability metric (string coherence model)
        state.excitation_stability =
            1.0f - fabs(fftMag[1] - fftMag[2]) * 0.5f;

        // 6. Output spectral field
        spectralOut.resize(fftMag.size());
        for (size_t i = 0; i < fftMag.size(); i++) {
            spectralOut[i] =
                fftMag[i] *
                ENERGY_DECAY +
                state.excitation_stability * 0.1f;
        }
    }

    float getFundamental() const {
        return state.fundamental;
    }

    float getStability() const {
        return state.excitation_stability;
    }

private:
    StringState state;

    float computeEnergy(const std::vector<float>& x) {
        float e = 0.0f;
        for (float v : x) e += v * v;
        return e / x.size();
    }

    float smooth(float prev, float curr) {
        return prev * 0.8f + curr * 0.2f;
    }

    std::vector<float> pseudoFFT(const std::vector<float>& x) {
        // Placeholder deterministic transform
        std::vector<float> out(64, 0.0f);

        for (size_t i = 0; i < x.size() && i < 64; i++) {
            out[i % 64] += fabs(x[i]);
        }
        return out;
    }

    float estimateFundamental(const std::vector<float>& mag) {
        float maxVal = 0.0f;
        int idx = 0;

        for (int i = 0; i < (int)mag.size(); i++) {
            if (mag[i] > maxVal) {
                maxVal = mag[i];
                idx = i;
            }
        }
        return 440.0f * pow(2.0f, (idx - 32) / 12.0f);
    }

    float harmonicWeight(int i) {
        return 1.0f / (1.0f + i);
    }
};
