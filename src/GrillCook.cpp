#include "GrillCook.h"

GrillCook::GrillCook() {
    this->setName("Grill Cook");
}

void GrillCook::prepareDish(Order* dish) {
    if (dish != nullptr) {
        if (dish->contains("steak")) {
            std::cout << "\tSteak Is Getting Grilled by Grill Cook." << std::endl;
            dish->setGrilled(true);
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