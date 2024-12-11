#include "../headers/Dtw.h"

double Dtw::calculate(const std::vector<double>& series1, const std::vector<double>& series2) {
    int len1 = series1.size();
    int len2 = series2.size();

    // Initialize the DTW matrix
    std::vector<std::vector<double>> dtw(len1 + 1, std::vector<double>(len2 + 1, std::numeric_limits<double>::infinity()));
    dtw[0][0] = 0;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            double cost = std::pow(series1[i - 1] - series2[j - 1], 2);
            dtw[i][j] = cost + std::min({dtw[i - 1][j], dtw[i][j - 1], dtw[i - 1][j - 1]});
        }
    }

    return std::sqrt(dtw[len1][len2]);
}