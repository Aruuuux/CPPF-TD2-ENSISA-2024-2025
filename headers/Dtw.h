#ifndef DTW_H
#define DTW_H

#include <vector>
#include <cmath>
#include <limits>

class Dtw {
public:
    static double calculate(const std::vector<double>& series1, const std::vector<double>& series2);
};

#endif // DTW_H