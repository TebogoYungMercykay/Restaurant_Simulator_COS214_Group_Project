#include "FryCook.h"

FryCook::FryCook() {
    this->setName("Fry Cook");
}

void FryCook::prepareDish(Order* dish) {
    if (dish != nullptr) {
        std::vector<OrderItem> items = dish->getOrderItems("fried");
        if (items.size() != 0) {
            for (int k = 0; k < items.size(); k++) {
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