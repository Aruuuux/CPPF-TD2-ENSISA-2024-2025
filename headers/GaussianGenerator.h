#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "TimeSeriesGenerator.h"
#include <vector>

class GaussianGenerator : public TimeSeriesGenerator {
    private:
        double mean;
        double stddev;

    public:
        GaussianGenerator(double mean, double stddev);
        std::vector<double> generateTimeSeries(int size) override;
};

#endif