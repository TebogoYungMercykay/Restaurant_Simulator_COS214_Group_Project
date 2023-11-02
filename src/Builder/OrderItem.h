#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>
#include <vector>

using namespace std;

class OrderItem {
    private:
        int quantity;
        double price;
        string name;
    public:
        OrderItem(int quantity, double price, string name);

        int getQuantity();
        double getPrice();
        string getName();

        void setQuantity(int quantity);
        void setPrice(double price);
        void setName(string name);
};

#endif // ORDERITEM_H
