#ifndef CUSTOMERSESSION_H
#define CUSTOMERSESSION_H

#include "TabStore.h"

#include <map>
#include <string>
#include <iostream>

using namespace std;

class CustomerSession{
    private:
        double total;
        Order* tableOrder;
        Bill* tableBill;
        string customerName;

    public:
        CustomerSession();
        void createOrder(map<string, int> orderDetails); //check what variables we will use for the map
        Order* getOrder();
        void createTab(string name);
        void prepareBill();
        void payBill();
        bool tabExistence(string customerName);
};
#endif