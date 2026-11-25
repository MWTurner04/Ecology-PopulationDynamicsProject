
#include <iostream>
#include "Species.h"
#include "SpeciesStore.h"

int main() {

    // Creates the store for our species
    SpeciesStore store;

    // Creates five species for testing
    Species robin1(101, "Erithacus rubecula", "Robin",
                   "Aves", "LC", 2024, "Small garden bird",
                   150, 2019, 0.10, 750);

    Species robin2(102, "Turdus migratorius", "Robin",
                   "Aves", "EN", 2024, "Another type of Robin",
                   200, 2020, 0.10, 800);

    Species panda(103, "Ailuropoda melanoleuca", "Giant Panda",
                  "Mammalia", "VU", 2024, "Large mammal",
                  100, 2020, 0.10, 500);

    Species fox(105, "Vulpes vulpes", "Red Fox",
                "Mammalia", "NT", 2024, "Woodland animal",
                100, 2020, 0.10, 1000);

    Species turtle(110, "Chelonia mydas", "Green Turtle",
                   "Reptilia", "CR", 2024, "Marine turtle",
                   100, 2020, 0.10, 500);

    // T01 - Adds species to the linked list
    std::cout << "\nT01 - Adding Species" << std::endl;

    store.addSpecies(robin1);
    store.addSpecies(robin2);
    store.addSpecies(panda);
    store.addSpecies(fox);
    store.addSpecies(turtle);

    if (store.findById(103) != nullptr) {
        std::cout << "PASS - Panda added successfully" << std::endl;
    }

    // Checks that the same ID cannot be added twice
    if (store.addSpecies(robin1) == false) {
        std::cout << "PASS - Duplicate ID rejected" << std::endl;
    }

    // T02 - Updates an existing species
    std::cout << "\nT02 - Updating Species" << std::endl;

    Species updatedRobin(101, "Erithacus rubecula", "Robin",
                         "Aves", "EN", 2024, "Small garden bird",
                         150, 2019, 0.20, 750);

    store.updateSpecies(updatedRobin);

    if (store.findById(101) != nullptr &&
        store.findById(101)->getConservationStatus() == "EN" &&
        store.findById(101)->getGrowthRate() == 0.20) {
        std::cout << "PASS - Robin updated successfully" << std::endl;
    }

    // T04 - Finds two species with the same common name
    std::cout << "\nT04 - Searching Common Name: Robin" << std::endl;
    store.searchByCommonName("Robin");

    // T05 - Searches using the scientific name
    std::cout << "\nT05 - Searching Scientific Name" << std::endl;
    store.searchBySciName("Ailuropoda melanoleuca");

    // T06 - Sorts species by conservation risk
    std::cout << "\nT06 - Sorting by Risk" << std::endl;

    store.sortByRisk();
    store.displayAll();

    // Checks that CR appears first
    Species* firstSpecies = store.getSpeciesPosition(0);

    if (firstSpecies != nullptr &&
        firstSpecies->getConservationStatus() == "CR") {
        std::cout << "PASS - Highest risk appears first" << std::endl;
    }

    // T03 - Deletes a species using its ID
    std::cout << "\nT03 - Deleting Species" << std::endl;

    if (store.deleteSpecies(110) == true &&
        store.findById(110) == nullptr) {
        std::cout << "PASS - Green Turtle deleted" << std::endl;
    }

    // Checks that deleting a missing ID fails
    if (store.deleteSpecies(999) == false) {
        std::cout << "PASS - Missing ID rejected" << std::endl;
    }

    // Tests swapping two stores
    std::cout << "\nTesting swapWith()" << std::endl;

    SpeciesStore otherStore;
    otherStore.addSpecies(turtle);

    store.swapWith(otherStore);

    if (store.findById(110) != nullptr &&
        store.findById(101) == nullptr) {
        std::cout << "PASS - Stores swapped successfully" << std::endl;
    }

    // Tests removing all species
    std::cout << "\nTesting clear()" << std::endl;

    store.clear();

    if (store.getSpeciesPosition(0) == nullptr) {
        std::cout << "PASS - Store cleared successfully" << std::endl;
    }

    return 0;
}
