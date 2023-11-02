#include "Order.h"
#include <algorithm>

#include "Order.h"
#include <iostream>

Order::Order() {
    this->table = 0;
    this->waiter = 0;
    this->grilled = false;
    this->fried = false;
    this->cost = 0;
}

Order::~Order() {}

Order::Order(int table, int waiter, std::vector<OrderItem> parameterOrderItems, bool grilled, bool fried, int cost) {
    this->table = table;
    this->waiter = waiter;
    this->grilled = grilled;
    this->fried = fried;
    this->cost = cost;
    for (OrderItem item : parameterOrderItems) {
        this->addItem(item.getName(), item.getPrice());
    }
}

bool Order::contains(std::string item) {
    for (OrderItem orderItem : this->orderItems) {
        if (orderItem.getName() == item) {
            return true;
        }
    }
    return false;
}

std::string Order::toStringItems() {
    std::string items = "";
    for (int i = 0; i < this->orderItems.size(); i++) {
        if (i != 0) {
            if (i == this->orderItems.size() - 1) {
                items += " and ";
            } else {
                items += ", ";
            }
        }
        items += this->orderItems[i].getName();
    }
    return items;
}

std::string Order::toStringSideItems() {
    std::string items = "";
    for (int i = 2; i < this->orderItems.size(); i++) {
        if (i != 2) {
            if (i == this->orderItems.size() - 1) {
                items += " and ";
            } else {
                items += ", ";
            }
        }
        items += this->orderItems[i].getName();
    }
    return items;
}

void Order::addItem(std::string item, double price, int quantity) {
    for (OrderItem orderItem : this->orderItems) {
        if (orderItem.getName() == item) {
            orderItem.setQuantity(orderItem.getQuantity() + quantity);
            if (orderItem.getQuantity() <= 0) {
                for (auto it = this->orderItems.begin(); it != this->orderItems.end(); ++it) {
                    if (it->getName() == item) {
                        this->orderItems.erase(it);
                        break;
                    }
                }
            }
            return;
        }
    }

    OrderItem newItem(quantity, price, item);
    this->orderItems.push_back(newItem);
}

void Order::addItemCost(int costItem) {
    this->cost += costItem;
}

void Order::removeItem(std::string item) {
    for (OrderItem orderItem : this->orderItems) {
        if (orderItem.getName() == item) {
            orderItem.setQuantity(orderItem.getQuantity() - 1);

            if (orderItem.getQuantity() <= 0) {
                for (auto it = this->orderItems.begin(); it != this->orderItems.end(); ++it) {
                    if (it->getName() == item) {
                        this->orderItems.erase(it);
                        break;
                    }
                }
            }
            return;
        }
    }
}

void Order::addDrink(std::string drink) {
    this->addItem(drink, 18.56);
}

void Order::setTable(int table) {
    this->table = table;
}

void Order::setWaiter(int waiter) {
    this->waiter = waiter;
}

void Order::setOrderItems(std::vector<OrderItem> otherItems) {
    this->orderItems = otherItems;
}

void Order::setGrilled(bool grilled) {
    this->grilled = grilled;
}

void Order::setFried(bool fried) {
    this->fried = fried;
}

void Order::setCost(int cost) {
    this->cost = cost;
}

void Order::setMeal(std::string meal) {
    this->meal = meal;
}

std::string Order::getMeal() {
    return this->meal;
}

int Order::getTable() {
    return this->table;
}

int Order::getWaiter() {
    return this->waiter;
}

std::vector<OrderItem> Order::getOrderItems() {
    return this->orderItems;
}

bool Order::getGrilled() {
    return this->grilled;
}

bool Order::getFried() {
    return this->fried;
}

double Order::getCost() {
    this->cost = 0;
    for (OrderItem orderItem : this->orderItems) {
        this->cost += orderItem.getPrice() * orderItem.getQuantity();
    }

    return this->cost;
}
