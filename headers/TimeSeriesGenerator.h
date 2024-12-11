#ifndef TIMESSERIESGENERATOR_H
#define TIMESSERIESGENERATOR_H

#include <vector>
#include <iostream>

class TimeSeriesGenerator {
    private:
        int seed; // Variable pour stocker la graine

    public:
        // Constructeur par défaut initialisant la graine à 0
        TimeSeriesGenerator();

        // Constructeur paramétré initialisant la graine avec une valeur donnée
        TimeSeriesGenerator(int seed);

        // Fonction virtuelle pure pour générer une série temporelle
        // Prend en paramètre la taille de la série et retourne un vecteur de doubles
        virtual std::vector<double> generateTimeSeries(int size) = 0;

        // Fonction statique pour imprimer une série temporelle
        // Prend en paramètre un vecteur de doubles et imprime chaque élément
        static void printTimeSeries(const std::vector<double>& series);
        };


#endif