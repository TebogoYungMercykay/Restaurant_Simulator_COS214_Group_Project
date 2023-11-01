#include "SingleBill.h"

SingleBill :: SingleBill(double amt){
    this->amount = amt;
}

double SingleBill :: getAmount(){
    return amount;
}

void SingleBill :: addBill(Bill* b){}