#include "headers/TimeSeriesGenerator.h"

// Constructeur par défaut initialisant la graine à 0
TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

// Constructeur paramétré initialisant la graine avec une valeur donnée
TimeSeriesGenerator::TimeSeriesGenerator(int seed) : seed(seed) {}

// Fonction statique pour imprimer une série temporelle
void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& series) {
    for (int i = 0; i < series.size(); i++) {
        std::cout << series[i] << " ";
    }
    std::cout << std::endl;
}