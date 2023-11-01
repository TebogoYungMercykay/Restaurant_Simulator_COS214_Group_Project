#include "KitchenStaff.h"

KitchenStaff::KitchenStaff() {
    this->setName("Kitchen Staff");
}

void KitchenStaff::prepareDish(Order* dish) {
    if (dish != nullptr) {
        std::cout << "Order for Table " << dish->getTable() << " being handled" << std::endl;
        std::cout << "\tKitchen Staff is preparing the " << dish->toStringSideItems() << std::endl;
        if (this->nextStation != nullptr) {
            this->nextStation->prepareDish(dish);
        } else {
            std::cout << "\tOrder Completed, Passed to Waiter." << std::endl;
        }
    } else {
        std::cout << "\t" << this->getName() << " Can't Handle Request." << std::endl;
    }
}