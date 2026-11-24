//
// Created by Max Turner on 24/11/2026.
//

#ifndef ECOLOGYPOPULATIONDYNAMICS_SPECIES_H
#define ECOLOGYPOPULATIONDYNAMICS_SPECIES_H


#include <string>

//allows us to store text.


class Species {
    //Collecting the Species information as shown in Table 3 and 4 of Section 2.2
private:
    int id;
    std::string sciName;
    std::string commonName;
    std::string group;
    std::string conservationStatus;
    int assessedYear;
    std::string description;

    //Need to store values for Population Predictions
    int initialPopulation;
    int recordedYear;
    double growthRate;
    int carryingCapacity;

public:
    //Creating Species using information provided to us.
    Species (int newId,
        std::string newSciName,
        std::string newCommonName,
        std::string newGroup,
        std::string newConservationStatus,
        int newAssessedYear,
        std::string newDescription,
        int newInitialPopulation,
        int newRecordedYear,
        double newGrowthRate,
        int newCarryingCapacity);

    //Returning the stored information.
    int getId();
    std::string getSciName();
    std::string getCommonName();
    std::string getGroup();
    std::string getConservationStatus();
    int getAssessedYear();
    std::string getDescription();


    //Returning the stored population information.
    int getInitialPopulation();
    int getRecordedYear();
    double getGrowthRate();
    int getCarryingCapacity();

    //Updates a species without changing the ID.
    void updateInfo(Species newDetails);

    //Display all the information about the species.
    void display();

};


#endif //ECOLOGYPOPULATIONDYNAMICS_SPECIES_H
