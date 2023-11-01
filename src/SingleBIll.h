#ifndef SINGELBILL_H
#define SINGLEBILL_H

#include "Bill.h"

using namespace std;

class SingleBill : public Bill{
    private:
        double amount;

    public:
        SingleBill(double amt);
        virtual double getAmount();
        virtual void addBill(Bill* b);
};
#endif