#ifndef CUSTOMERSESSION_H
#define CUSTOMERSESSION_H

#include "Tab/TabStore.h"
#include "Tab/Tab.h"
#include "Restaurant.h"
#include "Bill/Bill.h"
#include "Bill/SingleBill.h"
#include "Bill/SplitBill.h"
#include "Builder/OrderBuilder.h"
#include "Builder/OrderDirector.h"
#include "Builder/WackNuggetsBuilder.h"
#include "Builder/WackCrispyBuilder.h"
#include "Builder/KotaPounderBuilder.h"
#include "Builder/HugeMacBuilder.h"

#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CustomerSession{
    private:
        double total;
        OrderBuilder* tableOrderBuilder;
        Bill* tableBill;
        string customerName;

    public:
        CustomerSession();
        ~CustomerSession();
        void createOrder(vector<std::string> orderDetails);
        Order* getOrder();
        void createTab(string name);
        void prepareBill();
        void payBill(double billAmount);
        bool tabExistence(string customerName);
        void setCustomerName(string customerName);
        string getCustomerName();
};
#endif