#include "../headers/Knn.h"
#include "../headers/Dtw.h"
#include <cmath>
#include <algorithm>
#include <numeric>

KNN::KNN(int k, const std::string& similarityMeasure) : k(k), similarityMeasure(similarityMeasure) {}

double KNN::euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2) const {
    double sum = 0.0;
    for (size_t i = 0; i < series1.size(); ++i) {
        sum += std::pow(series1[i] - series2[i], 2);
    }
    return std::sqrt(sum);
}

int KNN::predict(const std::vector<std::vector<double>>& trainData, const std::vector<int>& trainLabels, const std::vector<double>& testSeries) const {
    std::vector<std::pair<double, int>> distances;

    for (size_t i = 0; i < trainData.size(); ++i) {
        double distance = 0.0;
        if (similarityMeasure == "euclidean_distance") {
            distance = euclideanDistance(trainData[i], testSeries);
        } else if (similarityMeasure == "dtw") {
            distance = Dtw::calculate(trainData[i], testSeries);
        }
        distances.emplace_back(distance, trainLabels[i]);
    }

    std::sort(distances.begin(), distances.end());

    std::vector<int> kNearestLabels(k);
    for (int i = 0; i < k; ++i) {
        kNearestLabels[i] = distances[i].second;
    }

    int predictedLabel = std::accumulate(kNearestLabels.begin(), kNearestLabels.end(), 0) / k;
    return predictedLabel;
}

double KNN::evaluate(const std::vector<std::vector<double>>& trainData, const std::vector<int>& trainLabels, const std::vector<std::vector<double>>& testData, const std::vector<int>& groundTruth) const {
    int correctPredictions = 0;
    for (size_t i = 0; i < testData.size(); ++i) {
        int predictedLabel = predict(trainData, trainLabels, testData[i]);
        if (predictedLabel == groundTruth[i]) {
            ++correctPredictions;
        }
    }
    return static_cast<double>(correctPredictions) / groundTruth.size();
}