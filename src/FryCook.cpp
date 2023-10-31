#include "FryCook.h"

FryCook::FryCook() {
    this->setName("Fry Cook");
}

void FryCook::prepareDish(Order* dish) {
    if (dish != nullptr) {
        if (dish->contains("fries")) {
            std::cout << "\tFry Cook Making Fries." << std::endl;
            dish->setFried(true);
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