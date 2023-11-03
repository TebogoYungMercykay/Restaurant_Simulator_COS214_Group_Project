#include "WaiterManager.h"

WaiterManager::WaiterManager(int numWaiters, KitchenManager* kitchen) {
    this->kitchen = kitchen;
    this->numWaiters = numWaiters;
    nextToAssign = 0;

    for (int i = 0; i < numWaiters; i++) {
        waiters.emplace_back(i);
    }
}

void WaiterManager::assignTable(TableComponent* table) {
    // code here
}

void WaiterManager::serve() {
    // code here
}

void WaiterManager::progressWaiters() {
    // code here
}