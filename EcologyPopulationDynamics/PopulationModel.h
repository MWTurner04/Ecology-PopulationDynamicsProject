//
// Created by Max Turner on 25/11/2026.
//

#ifndef ECOLOGYPOPULATIONDYNAMICS_POPULATIONMODEL_H
#define ECOLOGYPOPULATIONDYNAMICS_POPULATIONMODEL_H

#include "Species.h"

//Calculates population predictions for a species.
class PopulationModel {
public:
    //Calculate the predicted population,
    //after a number of years
    double predictPopulation(Species &species, int years);

};
/*
 *Returns a double
 *uses the Species class
 *& uses an existing object
 *species is a placeholder name
 *years in a int input.
 */

#endif //ECOLOGYPOPULATIONDYNAMICS_POPULATIONMODEL_H
