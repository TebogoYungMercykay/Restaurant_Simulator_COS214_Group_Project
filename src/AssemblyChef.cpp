#include "AssemblyChef.h"

AssemblyChef::AssemblyChef() {
    this->setName("Assembly Chef");
}

void AssemblyChef::prepareDish(Order* dish) {
    if (dish != nullptr) {
        if (dish->contains("takeaway")) {
            std::cout << "\tAssembling and packaging " << (
                dish->contains("beef patty") ? " the HugeMac" : dish->contains("nuggets")
                ? " the Chicken WackNuggets" : dish->contains("beef") ? " the Kota Pounder" : " the Spicy WackCrispy"
            ) << " Accurately and Efficiently." << std::endl;
        } else if (dish->contains("dine-in")) {
            std::cout << "\tAssembly Chef Plating " << (
                dish->contains("beef patty") ? " the HugeMac" : dish->contains("nuggets")
                ? " the Chicken WackNuggets" : dish->contains("beef") ? " the Kota Pounder" : " the Spicy WackCrispy"
            ) << " Accurately and Efficiently." << std::endl;
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