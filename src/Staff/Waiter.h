#pragma once

#include <vector>
#include <stdio.h>

#include "../List/TableCollection.h"
#include "../Builder/Order.h"
#include "Staff.h"

using namespace std;

class Waiter : public Staff {
private:
    int id;
    List<TableComponent*>* assingedTables;
    Iterator<TableComponent*>* tableIterator;
    vector<Order*> pendingOrders;
    vector<Order*> completedOrders;

public:
    Waiter(int id);
    ~Waiter();
    int getId();
    void addCompletedOrders(vector<Order*> orders);
    vector<Order*> getPendingOrders();
    List<TableComponent*>* getTables();
    Iterator<TableComponent*>* getIterator();
};