#include "KotaPounderBuilder.h"

KotaPounderBuilder::KotaPounderBuilder() {
    this->order = new Order();
    this->order->setMeal("Quater Pounder");
}

KotaPounderBuilder::~KotaPounderBuilder() {
    if (this->order != nullptr) {
        delete this->order;
        this->order = nullptr;
    }
}

void KotaPounderBuilder::addToGrill() {
    this->order->addItem("Beef", 45.67);
}

void KotaPounderBuilder::addToFry() {
    this->order->addItem("Bacon", 23.50);
}

void KotaPounderBuilder::addToSide() {
    this->order->addItem("Cheese", 5.50);
    this->order->addItem("Tangy Pickles", 19.50);
    this->order->addItem("Silver Onions", 9.50);
    this->order->addItem("Seed Bun", 11.00);
}

void KotaPounderBuilder::addSpecialSause() {
    this->order->addItem("Salt and Pepper", 2.50);
}

Order* KotaPounderBuilder::getOrder() {
    return this->order;
}

void KotaPounderBuilder::reset() {
    if (this->order != nullptr) {
        delete this->order;
        this->order = nullptr;
    }
    this->order = new Order;
}
