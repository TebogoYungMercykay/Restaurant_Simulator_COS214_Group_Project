#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "OrderItem.h"

class Order {
    private:
        int table;
        int id;
        int waiter;
        std::vector<OrderItem> orderItems;
        bool grilled;
        bool fried;
        double cost;
        std::string meal;
    public:
        Order();
        ~Order();
        Order(int table, int waiter, std::vector<OrderItem> orderItems, bool grilled, bool fried, double cost);

        bool contains(std::string item);
        void addItem(std::string item, double price, int quantity = 1);
        void addItemCost(double costItem);
        void removeItem(std::string item);
        void addDrink(std::string drink);
        std::string toStringItems();
        std::string toStringSideItems();
        void setMeal(std::string meal);
        void setTable(int table);
        void setWaiter(int waiter);
        void setOrderItems(std::vector<OrderItem> orderItems);
        void setGrilled(bool grilled);
        void setFried(bool fried);
        void setCost(double cost);
        void setOrderNum(int num);
        int getOrderNum();
        std::string getMeal();
        int getTable();
        int getWaiter();
        std::vector<OrderItem> getOrderItems(std::string type = "all");
        bool getGrilled();
        bool getFried();
        double getCost();

};

#endif // ORDER_H
