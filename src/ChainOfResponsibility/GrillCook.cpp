#include "GrillCook.h"

GrillCook::GrillCook() {
    this->setName("Grill Cook");
}

void GrillCook::prepareDish(Order* dish) {
    if (dish != nullptr) {
        std::vector<OrderItem> items = dish->getOrderItems("grill");
        if (items.size() != 0) {
            for (int k = 0; k < items.size(); k++) {
                std::cout << "\t" << (items[k]).getName() << " is getting Grilled by Grill Cook." << std::endl;
                std::cout << "\tFry Cook is making " << (items[k]).getName() << std::endl;
            }
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