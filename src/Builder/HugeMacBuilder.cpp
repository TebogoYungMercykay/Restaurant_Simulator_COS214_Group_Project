#include "HugeMacBuilder.h"

HugeMacBuilder::HugeMacBuilder() {
    this->order = new Order();
    this->order->setMeal("BiggerMac");
}

HugeMacBuilder::~HugeMacBuilder() {
    if (this->order != nullptr) {
        delete this->order;
        this->order = nullptr;
    }
}

void HugeMacBuilder::addToGrill() {
    this->order->addItem("Beef Patty", 27.50);
}

void HugeMacBuilder::addToFry() {
    this->order->addItem("Fries", 20.00);
}

void HugeMacBuilder::addToSide() {
    this->order->addItem("Cheese", 5.50);
    this->order->addItem("Pickle", 15.50);
    this->order->addItem("Lettuce", 4.50);
    this->order->addItem("Tomato", 2.50);
    this->order->addItem("Onions", 3.50);
    this->order->addItem("Seed Bun", 11.00);
}

void HugeMacBuilder::addSpecialSause() {
    this->order->addItem("Special Sauce", 2.50);
}

Order* HugeMacBuilder::getOrder() {
    return this->order;
}

void HugeMacBuilder::reset() {
    if (this->order != nullptr) {
        delete this->order;
        this->order = nullptr;
    }
    this->order = new Order;
}
