//
// Created by Max Turner on 24/11/2026.
//

/*
 *This file contains the code for the Species Class.
 *
 *The purpose of this code is to store information about,
 *individual species.
 *
 *First, it takes the information provided for a new species,
 *stores it within the variables we declared in the .h file.
 *
 *The "get" functions allow other parts of the program ,
 *to retrieve the information we have sorted.
 *
 *The updateInfo function allows us to replace the info,
 *without changing the unique ID.
 *
 *Then we display using the display function,
 *outputting all the info for the users to see.
 *
 *The class ONLY handles the information for one species,
 *other classes will manage handling multiple,
 *they will also check the info and calculate predictions.
 *
 */

#include "Species.h"
#include <iostream>

//Create a species and stores the information provided.
Species::Species(int newId,
    std::string newSciName,
    std::string newCommonName,
    std::string newGroup,
    std::string newConservationStatus,
    int newAssessedYear,
    std::string newDescription,
    int newInitialPopulation,
    int newRecordedYear,
    double newGrowthRate,
    int newCarryingCapacity)
//Setting the new information into the Species Variables.
: id(newId),
sciName(newSciName),
commonName(newCommonName),
group(newGroup),
conservationStatus(newConservationStatus),
assessedYear(newAssessedYear),
description(newDescription),
initialPopulation(newInitialPopulation),
recordedYear(newRecordedYear),
growthRate(newGrowthRate),
carryingCapacity(newCarryingCapacity) {

}

//Returning the new stored species information
int Species::getId() {
    return id;
}

std::string Species::getSciName() {
    return sciName;
}

std::string Species::getCommonName() {
    return commonName;
}

std::string Species::getGroup() {
    return group;
}

std::string Species::getConservationStatus() {
    return conservationStatus;
}

int Species::getAssessedYear() {
    return assessedYear;
}

std::string Species::getDescription() {
    return description;
}

//Returns the stored population information.
int Species::getInitialPopulation() {
    return initialPopulation;
}

int Species::getRecordedYear() {
    return recordedYear;
}

double Species::getGrowthRate() {
    return growthRate;
}

int Species::getCarryingCapacity() {
    return carryingCapacity;
}

//Updates the species information without changing the unique ID.
void Species::updateInfo(Species newDetails) {
    sciName = newDetails.sciName;
    commonName = newDetails.commonName;
    group = newDetails.group;
    conservationStatus = newDetails.conservationStatus;
    assessedYear = newDetails.assessedYear;
    description = newDetails.description;
    initialPopulation = newDetails.initialPopulation;
    recordedYear = newDetails.recordedYear;
    growthRate = newDetails.growthRate;
    carryingCapacity = newDetails.carryingCapacity;
}

//Displaying the information about stored Species to the user.
void Species::display() {
    std::cout << "\nSpecies ID: " << id << std::endl;
    std::cout << "\nScientific Name: " << sciName << std::endl;
    std::cout << "\nCommon Name: " << commonName << std::endl;
    std::cout << "\nGroup: " << group << std::endl;
    std::cout << "\nConservation Status: " << conservationStatus << std::endl;
    std::cout << "\nYear Assessed: " << assessedYear << std::endl;
    std::cout << "\nDescription: " << description << std::endl;
    std::cout << "\nInitial Population: " << initialPopulation << std::endl;
    std::cout << "\nYear Recorded: " << recordedYear << std::endl;
    std::cout << "\nGrowth Rate: " << growthRate << std::endl;
    std::cout << "\nCarrying Capacity: " << carryingCapacity<< std::endl;
}
