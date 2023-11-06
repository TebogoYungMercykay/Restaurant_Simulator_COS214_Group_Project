#ifndef KITCHENMANAGER_H
#define KITCHENMANAGER_H

#include "KitchenStation.h"
#include "./../Builder/Order.h"
#include <vector>

class KitchenManager {
    private:
        KitchenStation* kitchen;
        std::vector<Order*> completedOrders;
        std::vector<Order*> orders;

    public:
        KitchenManager();
        ~KitchenManager();
        void addOrder(Order* order);
        void addOrders(std::vector<Order*> orderList);
        std::vector<Order*> getCompletedOrders(int id_waiter = 0);
        std::vector<Order*> getOrders() const;
        void progressKitchen();
        string toString();
};

#endif // KITCHENMANAGER_H
