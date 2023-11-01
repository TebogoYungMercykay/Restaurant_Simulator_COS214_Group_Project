// OrderDirector.cpp
#include "OrderDirector.h"

void OrderDirector::setOrderBuilder(OrderBuilder* newOrderBuilder) {
    this->builder = newOrderBuilder;
}

Order* OrderDirector::getOrder() {
    return this->builder->getOrder();
}

void OrderDirector::constructOrder() {
    this->builder->addToGrill();
    this->builder->addToFry();
    this->builder->addToSide();
    this->builder->addSpecialSause();
}

void OrderDirector::addExtras(std::string drinkType, vector<std::string> removeItems) {
    if (drinkType != "") {
        this->builder->getOrder()->addDrink(drinkType);
    }

    // Removing specified items from the order
    for (std::string item : removeItems) {
        this->builder->getOrder()->removeItem(item);
    }
}

void OrderDirector::reset() {
    this->builder->reset();
}