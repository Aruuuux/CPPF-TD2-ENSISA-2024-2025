#include "headers/StepGenerator.h"
#include <random>

StepGenerator::StepGenerator() {}

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);
    std::uniform_real_distribution<> prob(0.0, 1.0);

    series[0] = 0; // Première valeur est 0

    for (int i = 1; i < size; ++i) {
        if (prob(gen) < 0.5) {
            series[i] = series[i - 1];
        } else {
            series[i] = dis(gen);
        }
    }

    return series;
}