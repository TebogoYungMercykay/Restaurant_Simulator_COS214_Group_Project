#include "SingleBill.h"

SingleBill :: SingleBill(double amt){
    this->amount = amt;
}

double SingleBill :: getAmount(){
    return amount;
}

void SingleBill :: addBill(Bill* b){
    // Since this is a leaf node this function will not be used, so it can be left empty.
}