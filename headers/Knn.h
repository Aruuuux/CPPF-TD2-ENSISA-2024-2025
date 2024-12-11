#ifndef KNN_H
#define KNN_H

#include <vector>
#include <string>

class KNN {
private:
    int k;
    std::string similarityMeasure;

    double euclideanDistance(const std::vector<double>& series1, const std::vector<double>& series2) const;

public:
    KNN(int k, const std::string& similarityMeasure);

    int predict(const std::vector<std::vector<double>>& trainData, const std::vector<int>& trainLabels, const std::vector<double>& testSeries) const;

    double evaluate(const std::vector<std::vector<double>>& trainData, const std::vector<int>& trainLabels, const std::vector<std::vector<double>>& testData, const std::vector<int>& groundTruth) const;
};

#endif // KNN_H
