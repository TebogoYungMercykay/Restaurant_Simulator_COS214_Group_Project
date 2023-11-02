#include "FryCook.h"

FryCook::FryCook() {
    this->setName("Fry Cook");
}

void FryCook::prepareDish(Order* dish) {
    if (dish != nullptr) {
        if (dish->getOrderItems().size() >= 2) {
            std::cout << "\tFry Cook is making " << (dish->getOrderItems()[1]).getName() << std::endl;
            dish->setGrilled(true);
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