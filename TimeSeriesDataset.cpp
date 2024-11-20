#include "headers/TimeSeriesDataset.h"
#include <algorithm>
#include <numeric>
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain, int maxLength, int numberOfSamples)
    : znormalize(znormalize), isTrain(isTrain), maxLength(maxLength), numberOfSamples(numberOfSamples) {}

void TimeSeriesDataset::addSample(const std::vector<double>& sample, int label) {
    std::vector<double> normalizedSample = sample;
    if (znormalize) {
        zNormalizeData(normalizedSample);
    }
    data.push_back(normalizedSample);
    labels.push_back(label);
}

std::vector<std::vector<double>> TimeSeriesDataset::getData() const {
    return data;
}

std::vector<int> TimeSeriesDataset::getLabels() const {
    return labels;
}

int TimeSeriesDataset::getMaxLength() const {
    return maxLength;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

void TimeSeriesDataset::zNormalizeData(std::vector<double>& sample) {
    double mean = std::accumulate(sample.begin(), sample.end(), 0.0) / sample.size();
    double sq_sum = std::inner_product(sample.begin(), sample.end(), sample.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / sample.size() - mean * mean);

    for (auto& value : sample) {
        value = (value - mean) / stdev;
    }
}