#include "FryCook.h"

FryCook::FryCook() {
    this->setName("Fry Cook");
}

void FryCook::prepareDish(Order* dish) {
    if (dish != nullptr) {
        std::cout << "\tFry Cook making Fries" << std::endl;
        if (dish->getFirstItem() != "beef" && dish->getFirstItem() != "beef patty") {
            std::string first = dish->getFirstItem();
            first[0] = std::toupper(first[0]);
            std::cout << " and " << first << std::endl;
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