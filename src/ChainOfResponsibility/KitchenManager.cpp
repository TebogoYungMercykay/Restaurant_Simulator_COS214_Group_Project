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

std::vector<Order*> KitchenManager::getCompletedOrders(int id_waiter) {
    std::vector<Order*> ordersForWaiter;

    for (auto it = this->completedOrders.begin(); it != this->completedOrders.end(); ) {
        if ((*it)->getWaiter() == id_waiter) {
            ordersForWaiter.push_back(*it);
            it = this->completedOrders.erase(it);
        } else {
            ++it;
        }
    }

    return ordersForWaiter;
}

std::vector<Order*> KitchenManager::getOrders() const {
    return this->orders;
}

void KitchenManager::progressKitchen() {
    if (orders.empty()) {
        return;
    }

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

    // // Process the pending orders
    // for (Order* dish : this->orders) {
    //     if (dish != nullptr) {
    //         this->kitchen->prepareDish(dish);
    //         // Order Complete, Add to completedOrders
    //         this->completedOrders.push_back(dish);
    //     }
    // }

    this->kitchen->prepareDish(orders.front());
    completedOrders.push_back(orders.front());
    orders.erase(orders.begin());

    // Clearing the Orders since all Orders have been Processed
    // this->orders.clear();
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

std::string KitchenManager::toString() {
    std::string details = "Orders:\n";
    for (auto it = this->orders.begin(); it != this->orders.end(); ++it) {
        details += "\tWaiter " + std::to_string((*it)->getWaiter()) + ": Table " + std::to_string((*it)->getTable()) + " ("+ (*it)->getMeal() + ")\n";
    }

    details += "Completed orders:\n";
    for (auto it = this->completedOrders.begin(); it != this->completedOrders.end(); ++it) {
        details += "\tWaiter " + std::to_string((*it)->getWaiter()) + ": Table " + std::to_string((*it)->getTable()) + " ("+ (*it)->getMeal() + ")\n";
    }

    return details;
}
