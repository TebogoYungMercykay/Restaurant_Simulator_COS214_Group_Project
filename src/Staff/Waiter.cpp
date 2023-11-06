#include "Waiter.h"

Waiter::Waiter(int id) {
    setName("Waiter " + to_string(id));

    this->id = id;
    assingedTables = new List<TableComponent*>();
    tableIterator = assingedTables->getIterator();
}

Waiter::~Waiter() {
    delete assingedTables;
    delete tableIterator;
}

int Waiter::getId() {
    return id;
}

void Waiter::addCompletedOrders(vector<Order*> orders) {
    for(Order* order : orders) {
        completedOrders.push_back(order);
    }
}


void Waiter::addOrder(Order* order) {
    pendingOrders.push_back(order);
}

bool Waiter::removeOrder(Order* order) {
    for (auto it = completedOrders.begin(); it != completedOrders.end(); ++it) {
        if (order == *it) {
            completedOrders.erase(it);
            return true;
        }
    }

    return false;
}

vector<Order*> Waiter::getPendingOrders() {
    vector<Order*> res;

    for (Order* order : pendingOrders) {
        res.push_back(order);
    }

    pendingOrders.clear();

    return res;
}

List<TableComponent*>* Waiter::getTables() {
    return assingedTables;
}

Iterator<TableComponent*>* Waiter::getIterator() {
    return tableIterator;
}

