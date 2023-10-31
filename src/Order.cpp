#include "Order.h"

Order::Order() {
    this->table = 0;
    this->waiter = 0;
    this->orderItems = std::vector<std::string>();
    this->grilled = false;
    this->fried = false;
    this->cost = 0;
}

Order::~Order() {}

Order::Order(int table, int waiter, std::vector<std::string> orderItems, bool grilled, bool fried, int cost) {
    this->table = table;
    this->waiter = waiter;
    this->orderItems = orderItems;
    this->grilled = grilled;
    this->fried = fried;
    this->cost = cost;
}

bool Order::contains(std::string item) {
    for (int i = 0; i < orderItems.size(); i++) {
        if (orderItems[i] == item) {
            return true;
        }
    }
    return false;
}

void Order::addItem(std::string item) {
    if (!this->contains(item)) {
        this->orderItems.push_back(item);
    }
}

void Order::addItemCost(int costItem) {
    this->cost += costItem;
}

void Order::setTable(int table) {
    this->table = table;
}

void Order::setWaiter(int waiter) {
    this->waiter = waiter;
}

void Order::setOrderItems(std::vector<std::string> otherItems) {
    if (!this->orderItems.empty()) {
        for (int i = 0; i < otherItems.size(); i++) {
            this->orderItems.push_back(otherItems[i]);
        }
    } else {
        this->orderItems = otherItems;
    }
}

void Order::setGrilled(bool grilled) {
    this->grilled = grilled;
}

void Order::setFried(bool fried) {
    this->fried = fried;
}

void Order::setCost(int cost) {
    if (this->cost == 0) {
        this->cost = cost;
    } else {
        this->cost += cost;
    }
}

int Order::getTable() {
    return this->table;
}

int Order::getWaiter() {
    return this->waiter;
}

std::vector<std::string> Order::getOrderItems() {
    return this->orderItems;
}

bool Order::getGrilled() {
    return this->grilled;
}

bool Order::getFried() {
    return this->fried;
}

int Order::getCost() {
    return this->cost;
}
