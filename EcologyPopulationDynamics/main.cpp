
#include <iostream>
#include "Species.h"

int main() {

    // Create a Robin using our test data
    Species robin(101, "Erithacus rubecula", "Robin",
                  "Aves", "LC", 2024,
                  "Small bird found in gardens and woodland.",
                  150, 2019, 0.10, 750);

    // Display all the information
    robin.display();

    // Test retrieving information
    std::cout << "\nGroup: " << robin.getGroup() << std::endl;

    // Create new information to test updating
    Species updatedRobin(999, "Erithacus rubecula", "Robin",
                         "Aves", "EN", 2024,
                         "Small bird found in gardens and woodland.",
                         150, 2019, 0.20, 750);

    // Update the original Robin
    robin.updateInfo(updatedRobin);

    // Check the updated information
    std::cout << "\nAfter updating:" << std::endl;
    std::cout << "ID: " << robin.getId() << std::endl;
    std::cout << "Status: " << robin.getConservationStatus() << std::endl;
    std::cout << "Growth Rate: " << robin.getGrowthRate() << std::endl;

    return 0;
}
