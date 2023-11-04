#pragma once

#include <vector>

#include "../ChainOfResponsibility/KitchenManager.h"

using namespace std;

class WaiterManager {
private:
    vector<Waiter> waiters;
    KitchenManager* kitchen;
    int numWaiters;
    int nextToAssign;

public:
    WaiterManager(int numWaiters, KitchenManager* kitchen);
    void assignTable(TableComponent* table);
    void serve();
    void progressWaiters();
};