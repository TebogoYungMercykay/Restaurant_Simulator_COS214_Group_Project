#include "KitchenManager.h"
#include "FryCook.h"
#include "SousChef.h"
#include "GrillCook.h"
#include "KitchenStaff.h"
#include "AssemblyChef.h"

KitchenManager::KitchenManager() {
    this->kitchen = nullptr;
}

KitchenManager::~KitchenManager() {
    if (this->kitchen != nullptr) {
        delete this->kitchen;
        this->kitchen = nullptr;
    }
}

void KitchenManager::addOrder(Order* order) {
    orders.push_back(order);
}

void KitchenManager::addOrders(std::vector<Order*> orderList) {
    orders.insert(orders.end(), orderList.begin(), orderList.end());
}

std::vector<Order*> KitchenManager::getCompletedOrders() const {
    return this->completedOrders;
}

std::vector<Order*> KitchenManager::getOrders() const {
    return this->orders;
}

void KitchenManager::progressKitchen() {
    // Creating the Kitchen Chain
    this->kitchen = new KitchenStaff();
    GrillCook* grillCook = new GrillCook();
    FryCook* fryCook = new FryCook();
    SousChef* sousChef = new SousChef();
    AssemblyChef* assemblyChef = new AssemblyChef();


    this->kitchen->setNext(grillCook);
    grillCook->setNext(fryCook);
    fryCook->setNext(sousChef);
    sousChef->setNext(assemblyChef);
    assemblyChef->setNext(nullptr);

    // Process the pending orders
    for (Order* dish : this->orders) {
        if (dish != nullptr) {
            this->kitchen->prepareDish(dish);
            // Order Complete, Add to completedOrders
            this->completedOrders.push_back(dish);
        }
    }

    // Clearing the Orders since all Orders have been Processed
    this->orders.clear();
    // Deallocating all Dynamic Memory
    delete this->kitchen;
    this->kitchen = nullptr;
    delete grillCook;
    grillCook = nullptr;
    delete fryCook;
    fryCook = nullptr;
    delete sousChef;
    sousChef = nullptr;
    delete assemblyChef;
    assemblyChef = nullptr;
}
