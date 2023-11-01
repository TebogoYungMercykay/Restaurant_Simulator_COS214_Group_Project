#include "FryCook.h"

FryCook::FryCook() {
    this->setName("Fry Cook");
}

void FryCook::prepareDish(Order* dish) {
    if (dish != nullptr) {
        if (dish->contains("nuggets")) {
            std::cout << "\tFry Cook making Fries and Nuggets." << std::endl;
            dish->setFried(true);
        } else if (dish->contains("chicken fillet")) {
            std::cout << "\tFry Cook making Fries and a Chicken Fillet." << std::endl;
            dish->setFried(true);
        }
        if (this->nextStation != nullptr) {
            this->nextStation->prepareDish(dish);
        } else {
            std::cout << "\tOrder Completed, Passed to Waiter." << std::endl;
        }
    } else {
        std::cout << "\t" << this->getName() << " Can't Handle Request." << std::endl;
    }
}