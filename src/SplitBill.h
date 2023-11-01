#ifndef SPLITTBILL_H
#define SPLITBILL_H

#include "Bill.h"

#include <vector>

using namespace std;

class SplitBill : public Bill{
    private:
        vector<Bill*> bills;

    public:
        SplitBill();
        ~SplitBill();
        virtual void addBill(Bill* bill);
        virtual double getAmount();
        vector<Bill*>& getBills();
};
#endif