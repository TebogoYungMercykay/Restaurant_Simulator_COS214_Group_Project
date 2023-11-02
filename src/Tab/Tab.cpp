#include "Tab.h"

Tab :: Tab(string name, double amount){
    this->amount = amount;
    this->customerName = name;
}

double Tab :: getAmount(){
    return amount;
}

string Tab :: getCustomerName(){
    return customerName;
}

void Tab :: addAmount(double amt){
    this->amount += amt;
}