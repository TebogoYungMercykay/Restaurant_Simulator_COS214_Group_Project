#include "WackNuggetsBuilder.h"

WackNuggetsBuilder::WackNuggetsBuilder() {
    this->order = new Order();
    this->order->setMeal("WackNuggets");
}

WackNuggetsBuilder::~WackNuggetsBuilder() {
    if (this->order != nullptr) {
        delete this->order;
        this->order = nullptr;
    }
}

void WackNuggetsBuilder::addToGrill() {
    this->order->addItem("Nuggets", 2.50);
}

void WackNuggetsBuilder::addToFry() {
    this->order->addItem("Fries", 20.00);
}

void WackNuggetsBuilder::addToSide() {
    this->order->addItem("Pickle Juice", 22.50);
}

void WackNuggetsBuilder::addSpecialSause() {
    this->order->addItem("Marinate", 3.50);
}

Order* WackNuggetsBuilder::getOrder() {
    return this->order;
}

void WackNuggetsBuilder::reset() {
    if (this->order != nullptr) {
        delete this->order;
        this->order = nullptr;
    }
    this->order = new Order;
}
