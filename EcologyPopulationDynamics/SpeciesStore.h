//
// Created by Max Turner on 25/11/2026.
//

#ifndef ECOLOGYPOPULATIONDYNAMICS_SPECIESSTORE_H
#define ECOLOGYPOPULATIONDYNAMICS_SPECIESSTORE_H

#include "Species.h"
#include <string>

//To store and manage multiple species using a linked list.
class SpeciesStore {
private:

    //Holds one species, then points to the next one.
    struct SpeciesItem {
        Species species;
        SpeciesItem* next;

        SpeciesItem(Species newSpecies)
            : species(newSpecies), next(nullptr) {}
    };

    //Start at the beginning of the list.
    SpeciesItem* head;

    //Sets up to give each conservation status a risk level
    int riskLevel(std::string status);

public:
    SpeciesStore();
    ~SpeciesStore();

    //Adds, Updates, delete species.
    bool addSpecies(Species newSpecies);
    bool updateSpecies(Species newDetails);
    bool deleteSpecies(int id);

    //Using ID to find species.
    Species* findById(int id);

    //Allows for searching by name.
    void searchBySciName(std::string name);
    void searchByCommonName(std::string name);

    //Displays all on list and sorts them by risk level.
    void displayAll();
    void sortByRisk();

    //Removing all the stored Species.
    void clear();

    //Replaces the stored list with another compatable list.
    void swapWith(SpeciesStore &other);


    //Gets species from a position in the list.
    Species* getSpeciesPosition(int position);
};


#endif //ECOLOGYPOPULATIONDYNAMICS_SPECIESSTORE_H

/*
 * Manages multiple species using a linked list.
 *
 * Each item stores one species then points to the next.
 *
 * The class allows us to update, delete, search, sort, display.
 *
 * Manages the memory to store an item.
 */