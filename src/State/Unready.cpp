#include "Unready.h"
#include <cstdlib>
#include <ctime>

void Unready::setTableComponent(TableComponent* table) {
    this->table = table;
}

void Unready::serve() {
    if (this->table != nullptr) {
        std::string response = "";
        std::cout << "Are you ready to place an order? (yes/no): ";
        while(std::cin >> response && (response != "yes" && response != "no")) {
            std::cout << "Invalid input. Please respond with 'yes' or 'no'.\n";
            std::cout << "Are you ready to place an order? (yes/no): ";
        }
        if (response == "yes") {
            this->table->changeState(new Ready());
        } else if (response == "no") {
            srand(time(0));
            int random_time = rand() % 10 + 1;
            std::cout << "No problem. Take your time and let us know when you're ready.\n";
            std::cout << "The waiter will Check In on you in " << random_time << " Minutes.\n";
        }
    } else {
        std::cout << "Error: No Table Assigned Yet.\n";
    }
}