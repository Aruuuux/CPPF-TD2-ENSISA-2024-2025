#include "headers/GaussianGenerator.h"
#include <cmath>
#include <random>

GaussianGenerator::GaussianGenerator(double mean, double stddev) : mean(mean), stddev(stddev) {}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> series(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < size; ++i) {
        double u1 = dis(gen);
        double u2 = dis(gen);
        double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);
        series[i] = mean + z0 * stddev;
    }

    return series;
}