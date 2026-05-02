#include "StringScanner.h"
#include <algorithm>
#include <cmath>

/*
    StringScanner — Spectral String Input Spine

    Responsibilities:
    - Convert physical interaction → continuous control signals
    - Preserve transient integrity
    - Maintain deterministic output for NRE pipeline

    This is NOT MIDI extraction.
    This is physical state reconstruction.
*/

StringScanner::StringScanner() {}

void StringScanner::Init(float sample_rate)
{
    sr = sample_rate;

    for (int i = 0; i < MAX_CHANNELS; i++)
    {
        position[i] = 0.0f;
        pressure[i] = 0.0f;
        velocity[i] = 0.0f;
        last_position[i] = 0.0f;
    }
}

/*
    Update raw sensor frame
    Expected inputs:
    - normalized position (0..1 along string)
    - normalized pressure (0..1 excitation force)
*/
void StringScanner::Update(float* pos, float* press, int channels)
{
    for (int i = 0; i < channels; i++)
    {
        float p = std::clamp(pos[i], 0.0f, 1.0f);
        float f = std::clamp(press[i], 0.0f, 1.0f);

        // Velocity estimation (first-order differentiation)
        velocity[i] = (p - last_position[i]) * sr;
        last_position[i] = p;

        // Low-level smoothing (preserve transient edge)
        position[i] = position[i] * 0.85f + p * 0.15f;

        // Pressure is NOT smoothed heavily (preserve attack)
        pressure[i] = f;
    }
}

/*
    Physical interpretation layer

    Converts string state into excitation vectors for NRE
*/
void StringScanner::GetExcitation(int channel, float& out_pos, float& out_energy, float& out_velocity)
{
    channel = std::clamp(channel, 0, MAX_CHANNELS - 1);

    out_pos = position[channel];
    out_energy = pressure[channel];

    // velocity is directional excitation sharpness
    out_velocity = velocity[channel];
}

/*
    Derived excitation strength used by NRE
*/
float StringScanner::GetTransientEnergy(int channel)
{
    channel = std::clamp(channel, 0, MAX_CHANNELS - 1);

    // nonlinear emphasis on attack
    float p = pressure[channel];
    float v = std::abs(velocity[channel]);

    return (p * p) + (0.5f * v);
}
