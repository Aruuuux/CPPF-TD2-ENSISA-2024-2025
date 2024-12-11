# Time Series Classification Project

## Description
Ce projet implémente un système de classification des séries temporelles en C++ en utilisant :
- **K-Nearest Neighbors (KNN)** comme classifieur.
- Deux mesures de similarité :
  - **Dynamic Time Warping (DTW)**
  - **Euclidean Distance**

## Fonctionnalités
1. Génération de séries temporelles à partir de trois générateurs :
   - **GaussianGenerator** : Génère des séries avec une distribution gaussienne.
   - **SinWaveGenerator** : Génère des séries basées sur une fonction sinusoïdale.
   - **StepGenerator** : Génère des séries avec des valeurs en escalier.
2. Création d'un jeu de données d'entraînement et de test.
3. Classification des séries temporelles en utilisant le KNN avec deux mesures de similarité.
4. Calcul de la précision pour chaque méthode.

## Prérequis
- **C++11** ou version ultérieure.
- Un compilateur compatible (GCC, Clang, etc.).

## Compilation
Pour compiler le projet, exécutez la commande suivante dans le terminal :
```bash
g++ -std=c++11 main.cpp GaussianGenerator.cpp SinWaveGenerator.cpp StepGenerator.cpp TimeSeriesDataset.cpp Knn.cpp Dtw.cpp TimesSeriesGenerator.cpp -o main
