#include "GrillCook.h"

GrillCook::GrillCook() {
    this->setName("Grill Cook");
}

void GrillCook::prepareDish(Order* dish) {
    if (dish != nullptr) {
        if (dish->getOrderItems().size() >= 1) {
            std::cout << "\t" << (dish->getOrderItems()[0]).getName() << " is getting Grilled by Grill Cook." << std::endl;
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