#include "headers/SinWaveGenerator.h"
#include <cmath>

SinWaveGenerator::SinWaveGenerator(double amplitude, double frequency, double phase)
    : amplitude(amplitude), frequency(frequency), phase(phase) {}

std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);

    for (int i = 0; i < size; ++i) {
        series[i] = amplitude * std::sin(frequency * i + phase);
    }

    return series;
}