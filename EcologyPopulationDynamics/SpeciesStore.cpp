//
// Created by Max Turner on 25/11/2026.
//

/*
 * This file stores and manages multiple species in a list.
 *
 * Each item holds one species and points down the list.
 *
 * It allows species to be added, updated, deleted and searched.
 *
 * It also displays species and sorts them by their risk.
 *
 * Creating new items, removing others from memory.
 */

#include "SpeciesStore.h"
#include <iostream>

//Start empty list.
SpeciesStore::SpeciesStore() : head(nullptr) {}

//Removes all species.
SpeciesStore::~SpeciesStore() {
    clear();
}

//Adds if ID is not already in use.
bool SpeciesStore::addSpecies(Species newSpecies) {
    if (findById(newSpecies.getId()) != nullptr) {
        return false;
    }
    SpeciesItem* newItem = new SpeciesItem(newSpecies);

    newItem->next = head;
    head = newItem;

    return true;
}

//Search using ID
Species* SpeciesStore::findById(int id) {
    SpeciesItem* current = head;

    while (current != nullptr) {
        if (current->species.getId() ==id) {
            return &current->species;
        }
        current = current->next;
    }
    return nullptr;
}

//Updates existing info
bool SpeciesStore::updateSpecies(Species newDetails) {

    Species* existingSpecies = findById(newDetails.getId());

    if (existingSpecies == nullptr) {
        return false;
    }

    existingSpecies->updateInfo(newDetails);
    return true;
}

//Deletes using ID
bool SpeciesStore::deleteSpecies(int id) {

    SpeciesItem* current = head;
    SpeciesItem* previous = nullptr;

    while (current != nullptr) {

        if (current->species.getId() == id) {

            if (previous == nullptr) {
                head = current->next;
            }
            else {
                previous->next = current->next;
            }

            delete current;
            return true;
        }

        previous = current;
        current = current->next;
    }
    return false;
}

//Search using sciName
void SpeciesStore::searchBySciName(std::string name) {
    SpeciesItem* current = head;
    bool identified = false;

    while (current != nullptr) {

        if (current->species.getSciName() == name) {
            current->species.display();
            identified = true;
        }

        current = current->next;
    }

    if (identified == false) {
        std::cout << "Species couldn't be identified." << std::endl;
    }
}

//Searches common name
void SpeciesStore::searchByCommonName(std::string name) {
    SpeciesItem* current = head;
    bool identified = false;

    while (current != nullptr) {

        if (current->species.getCommonName() == name) {
            current->species.display();
            identified = true;
        }

        current = current->next;
    }
    if (identified == false) {
        std::cout << "Species couldn't be identified." << std::endl;
    }
}

//Displays all
void SpeciesStore::displayAll() {
    SpeciesItem* current = head;

    if (current == nullptr) {
        std::cout <<"No species sored." << std::endl;
        return;
    }
    while (current != nullptr) {
        current->species.display();
        current = current->next;
    }
}

//Giving Risk status a number for storing.
int SpeciesStore::riskLevel(std::string status) {

    if (status == "CR") {
        return 5;
    }
    if (status == "EN") {
        return 4;
    }
    if (status == "VU") {
        return 3;
    }
    if (status == "NT") {
        return 2;
    }
    if (status == "LC") {
        return 1;
    }
    return 0;
}

//Sorts from highest to lowest.
void SpeciesStore::sortByRisk() {

    if (head == nullptr) {
        return;
    }
    bool changesMade = true;

    while (changesMade == true) {
        changesMade = false;
        SpeciesItem* current = head;

        while (current->next != nullptr) {
            int currentRisk = riskLevel(current->species.getConservationStatus());
            int nextRisk = riskLevel(current->next->species.getConservationStatus());

            if (currentRisk < nextRisk) {
                Species temporary = current->species;

                current->species = current->next->species;
                current->next->species = temporary;

                changesMade = true;
            }
            current = current->next;
        }
    }
}

//Removes all from memory.
void SpeciesStore::clear() {
    SpeciesItem* current = head;
    while (current != nullptr) {
        SpeciesItem* nextItem = current->next;
        delete current;
        current = nextItem;
    }

    head = nullptr;
}

//Swaps the stored records with another SpeciesStore
void SpeciesStore::swapWith(SpeciesStore &other) {
    SpeciesItem* temporary = head;
    head = other.head;
    other.head = temporary;
}

//Gets species through postion on list.
Species* SpeciesStore:: getSpeciesPosition(int position) {
    SpeciesItem* current = head;
    int number = 0;

    while (current != nullptr) {
        if (number == position) {
            return &current->species;
        }
        current = current->next;
        number++;
    }
    return nullptr;
}