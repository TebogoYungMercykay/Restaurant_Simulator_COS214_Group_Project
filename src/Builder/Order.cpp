#include "Order.h"
#include <algorithm>
#include <iomanip>

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

Order::Order(int table, int waiter, std::vector<OrderItem> parameterOrderItems, bool grilled, bool fried, double cost) {
    this->table = table;
    this->waiter = waiter;
    this->grilled = grilled;
    this->fried = fried;
    this->cost = cost;
    for (OrderItem item : parameterOrderItems) {
        for (int k = 0; k < item.getQuantity(); k++) {
            this->addItem(item.getName(), item.getPrice());
        }
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

std::string Order::toString() {
    std::string items = "----------------- Ordered Items --------------------\n";
    for (int i = 0; i < this->orderItems.size(); i++) {
        std::cout << "\t" << std::setfill('0') << std::setw(2) << std::right << i << "." << std::setfill(' ') << std::setw(25) << std::left << this->orderItems[i].getName() << "R" << std::fixed << std::setprecision(2) << this->orderItems[i].getPrice() << "\n";
        i++;
    }
    std::cout << "---------------------------------------------------\n";
    return items;
}

void Order::addItem(std::string item, double price, int quantity) {
    for (int k = 0; k < orderItems.size(); k++) {
        if (orderItems[k].getName() == item) {
            orderItems[k].setQuantity(orderItems[k].getQuantity() + quantity);
            if (orderItems[k].getQuantity() <= 0) {
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

void Order::addItemCost(double costItem) {
    if (this->orderItems.size() != 0) {
        this->orderItems[0].setPrice(this->orderItems[0].getPrice() + costItem);
    }
}

void Order::removeItem(std::string item) {
    for (auto it = this->orderItems.begin(); it != this->orderItems.end(); ++it) {
        if (it->getName() == item) {
            it->setQuantity(it->getQuantity() - 1);

            if (it->getQuantity() <= 0) {
                this->orderItems.erase(it);
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

std::vector<OrderItem> Order::getOrderItems(std::string type) {
    if (type == "fried") {
        std::vector<OrderItem> elements = {};
        std::vector<std::string> items = { "Fries", "Bacon" };
        for (int k = 0; k < orderItems.size(); k++) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i] == orderItems[k].getName()) {
                    elements.push_back(orderItems[k]);
                }
            }
        }
        return elements;
    } else if (type == "grill") {
        std::vector<OrderItem> elements = {};
        std::vector<std::string> items = { "Beef", "Beef Patty", "Nuggets", "Chicken Breast" };
        for (int k = 0; k < orderItems.size(); k++) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i] == orderItems[k].getName()) {
                    elements.push_back(orderItems[k]);
                }
            }
        }
        return elements;
    } else if (type == "sauce") {
        std::vector<OrderItem> elements = {};
        std::vector<std::string> items = { "Special Sauce", "Salt and Pepper", "Spicy Pepper Sauce", "Marinate" };
        for (int k = 0; k < orderItems.size(); k++) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i] == orderItems[k].getName()) {
                    elements.push_back(orderItems[k]);
                }
            }
        }
        return elements;
    } else if (type == "side") {
        std::vector<OrderItem> elements = {};
        std::vector<std::string> items = { "Pickle Juice", "Crinkle-Cut Pickles", "Toasted Potato Roll", "Cheese", "Tangy Pickles", "Silver Onions", "Seed Bun", "Pickle", "Lettuce", "Tomato", "Onions" };
        for (int k = 0; k < orderItems.size(); k++) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i] == orderItems[k].getName()) {
                    elements.push_back(orderItems[k]);
                }
            }
        }
        return elements;
    } else {
        return this->orderItems;
    }
}

bool Order::getGrilled() {
    return this->grilled;
}

bool Order::getFried() {
    return this->fried;
}

void Order::setCost(double cost) {
    this->cost = cost;
}

double Order::getCost() {
    this->cost = 0;
    for (OrderItem orderItem : this->orderItems) {
        this->cost += orderItem.getPrice() * orderItem.getQuantity();
    }

    return this->cost;
}

void Order::setOrderNum(int num) {
    this->id = num;
}

int Order::getOrderNum() {
    return this->id;
}
