#ifndef CUSTOMERSESSION_H
#define CUSTOMERSESSION_H

#include "TabStore.h"
#include "Tab.h"
#include "Restaurant.h"
#include "Bill.h"
#include "SingleBill.h"
#include "SplitBill.h"
//#include "Order.h"

class Order;

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
        ~CustomerSession();
        void createOrder(map<string, int> orderDetails); //check what variables we will use for the map
        Order* getOrder();
        void createTab(string name);
        void prepareBill();
        void payBill(double billAmount);
        bool tabExistence(string customerName);
};
#endif