#ifndef BILL_H
#define BILL_H

class Bill{
    public:
        virtual double getAmount() = 0;
        virtual void addBill(Bill* bill) = 0;
};
#endif