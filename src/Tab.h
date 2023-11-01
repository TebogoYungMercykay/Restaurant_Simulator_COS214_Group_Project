#ifndef TAB_H
#define TAB_H

#include <string>

using namespace std;

class Tab{
    private: 
        string customerName;
        double amount;
    public:
        Tab(string name, double amount);
        double getAmount();
        void addAmount(double input);
        string getCustomerName();
};
#endif