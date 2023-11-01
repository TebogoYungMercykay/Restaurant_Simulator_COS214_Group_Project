#include "SplitBill.h"

SplitBill :: SplitBill(){}

SplitBill :: ~SplitBill(){
    // need to delete the bill objects inside the vector
    for(Bill* ptr : bills){
        delete ptr;
        ptr = nullptr;
    }

    bills.clear();
}

void SplitBill :: addBill(Bill* bill){
    bills.push_back(bill);
}

double SplitBill :: getAmount(){
    // this will return the total amount for all the split bills together
    double amount = 0;

    for(Bill* ptr : bills){
        amount += ptr->getAmount();
    }

    return amount;
}

vector<Bill*>& SplitBill :: getBills(){
    return bills;
}