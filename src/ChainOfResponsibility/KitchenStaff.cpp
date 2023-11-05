#include "KitchenStaff.h"

KitchenStaff::KitchenStaff() {
    this->setName("Kitchen Staff");
}

void KitchenStaff::prepareDish(Order* dish) {
    if (dish != nullptr) {
        std::cout << "Order for Table " << dish->getTable() << " being handled" << std::endl;
        std::cout << "\tKitchen Staff is preparing the ";
        std::vector<OrderItem> items = dish->getOrderItems("side");
        if (items.size() != 0) {
            for (int k = 0; k < items.size(); k++) {
                std::cout << (items[k]).getName();
            }
            std::cout << std::endl;
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