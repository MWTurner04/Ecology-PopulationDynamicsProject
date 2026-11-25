//
// Created by Max Turner on 25/11/2026.
//

/*
 * This file is used to predict the future population of species.
 *
 * It gets the initial population, growth rate, carrying capacity,
 * from the Species class, along with a number of years entered.
 *
 * Checking values, making sure inputs are valid before continuing,
 * with the calculations
 *
 * If it is invalid it will return a -1
 *
 * Uses the chosen logistic growth formula to calculate
 *
 *returns the predicted population value.
 *
 */

#include "PopulationModel.h"
#include <cmath>

//Calculate the predicted population.
double PopulationModel::predictPopulation(Species &species, int years) {

    //Get the calculation values from selected species.
    int initialPopulation = species.getInitialPopulation();
    double growthRate = species.getGrowthRate();
    int carryingCapacity = species.getCarryingCapacity();

    //SAFETY CHECK: Make sure there are no invalid inputs.
    if (initialPopulation <= 0 || growthRate < 0 || carryingCapacity < initialPopulation || years < 0) {
        return -1;
    }

    //Using the logic growth formula to predict Population.
    double predictedPopulation = carryingCapacity / (1.0 + ((double)(carryingCapacity - initialPopulation) /
        initialPopulation) * std::exp(-growthRate * years));

    /*
     * This calculation uses the species initial population
     * growth rate and carrying capacity.
     * alongside the number of years entered
     * to predict its future population.
     */


    //return the Predicted Population.
    return predictedPopulation;
}
