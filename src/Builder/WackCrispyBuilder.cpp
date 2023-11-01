#include "WackCrispyBuilder.h"

WackCrispyBuilder::WackCrispyBuilder() {
    this->order = new Order();
    this->order->setMeal("WackCrispy");
}

WackCrispyBuilder::~WackCrispyBuilder() {
    if (this->order != nullptr) {
        delete this->order;
        this->order = nullptr;
    }
}

void WackCrispyBuilder::addToGrill() {
    this->order->addItem("Chicken Breast", 55.50);
}

void WackCrispyBuilder::addToFry() {
    this->order->addItem("Fries", 20.00);
}

void WackCrispyBuilder::addToSide() {
    this->order->addItem("Crinkle-Cut Pickles", 9.50);
    this->order->addItem("Toasted Potato Roll", 15.00);
}

void WackCrispyBuilder::addSpecialSause() {
    this->order->addItem("Spicy Pepper Sauce", 2.50);
}

Order* WackCrispyBuilder::getOrder() {
    return this->order;
}

void WackCrispyBuilder::reset() {
    if (this->order != nullptr) {
        delete this->order;
        this->order = nullptr;
    }
    this->order = new Order;
}
