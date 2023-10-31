#include "SousChef.h"

SousChef::SousChef() {
    this->setName("Sous Chef");
}

void SousChef::prepareDish(Order* dish) {
    if (dish != nullptr) {
        if (dish->contains("ensure")) {
            std::cout << "\tSous Chef Ensuring the Quality and Consistency of Dishes" << std::endl;
            if (this->nextStation != nullptr) {
                this->nextStation->prepareDish(dish);
            }
        } else {
            if (this->nextStation != nullptr) {
                this->nextStation->prepareDish(dish);
            } else {
                std::cout << "\tOrder Completed, Passed to Waiter." << std::endl;
            }
        }
    } else {
        std::cout << "\t" << this->getName() << " Can't Handle Request." << std::endl;
    }
}