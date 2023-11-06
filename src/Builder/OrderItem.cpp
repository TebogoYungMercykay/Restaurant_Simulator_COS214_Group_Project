#include "OrderItem.h"

// Parameterized constructor
OrderItem::OrderItem(int quantity, double price, string name) {
    this->quantity = quantity;
    this->price = price;
    this->name = name;
}

int OrderItem::getQuantity() {
    return quantity;
}

double OrderItem::getPrice() {
    return price;
}

string OrderItem::getName() {
    return name;
}

void OrderItem::setQuantity(int quantity) {
    this->quantity = quantity;
}

void OrderItem::setPrice(double price) {
    this->price = price;
}

void OrderItem::setName(string name) {
    this->name = name;
}
