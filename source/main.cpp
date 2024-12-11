#include "../headers/GaussianGenerator.h"
#include "../headers/SinWaveGenerator.h"
#include "../headers/StepGenerator.h"
#include "../headers/TimeSeriesDataset.h"
#include "../headers/Knn.h"
#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

int main() {
    std::cout << "==== Time Series Classification Program ====\n\n";

    // Création des générateurs
    std::cout << "Generating training and testing datasets...\n";
    GaussianGenerator gsg(0.0, 1.0);
    SinWaveGenerator swg(1.0, 0.1, 0.0);
    StepGenerator stg;

    TimeSeriesDataset trainData(false, true, 11, 6);
    TimeSeriesDataset testData(false, false, 11, 3);

    // Ajout des échantillons au jeu d'entraînement
    trainData.addSample(gsg.generateTimeSeries(11), 0);
    trainData.addSample(gsg.generateTimeSeries(11), 0);
    trainData.addSample(swg.generateTimeSeries(11), 1);
    trainData.addSample(swg.generateTimeSeries(11), 1);
    trainData.addSample(stg.generateTimeSeries(11), 2);
    trainData.addSample(stg.generateTimeSeries(11), 2);

    // Ajout des échantillons au jeu de test
    std::vector<int> groundTruth = {0, 1, 2};
    testData.addSample(gsg.generateTimeSeries(11), groundTruth[0]);
    testData.addSample(swg.generateTimeSeries(11), groundTruth[1]);
    testData.addSample(stg.generateTimeSeries(11), groundTruth[2]);

    std::cout << "Datasets successfully created.\n\n";

    // Exécution des classifications avec KNN
    std::cout << "Running KNN classification with DTW...\n";
    KNN knn_1(1, "dtw");
    double accuracy_dtw = knn_1.evaluate(trainData.getData(), trainData.getLabels(), testData.getData(), groundTruth);
    std::cout << "Accuracy with DTW: " << accuracy_dtw * 100 << "%\n";

    std::cout << "Running KNN classification with Euclidean Distance...\n";
    KNN knn_2(1, "euclidean_distance");
    double accuracy_euclidean = knn_2.evaluate(trainData.getData(), trainData.getLabels(), testData.getData(), groundTruth);
    std::cout << "Accuracy with Euclidean Distance: " << accuracy_euclidean * 100 << "%\n";

    std::cout << "\n==== Classification Completed Successfully ====\n";

    return 0;
}
