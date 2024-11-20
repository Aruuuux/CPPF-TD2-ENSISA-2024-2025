#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>

class TimeSeriesDataset {
    private:
        bool znormalize;
        bool isTrain;
        std::vector<std::vector<double>> data;
        std::vector<int> labels;
        int maxLength;
        int numberOfSamples;

        void zNormalizeData(std::vector<double>& sample);

    public:
        TimeSeriesDataset(bool znormalize, bool isTrain, int maxLength, int numberOfSamples);
        void addSample(const std::vector<double>& sample, int label);
        std::vector<std::vector<double>> getData() const;
        std::vector<int> getLabels() const;
        int getMaxLength() const;
        int getNumberOfSamples() const;
};

#endif