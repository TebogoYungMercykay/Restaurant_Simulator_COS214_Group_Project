#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <vector>

using namespace std;

class Order {
    private:
        int table;
        int waiter;
        std::vector<std::string> orderItems;
        bool grilled;
        bool fried;
        int cost;
        string meal;
    public:
        Order();
        ~Order();
        Order(int table, int waiter, std::vector<std::string> orderItems, bool grilled, bool fried, int cost);
        bool contains(std::string item);
        void addItem(std::string item);
        void addItemCost(int costItem);
        string toStringItems();
        string getFirstItem();
        void setMeal(int meal);
        void setTable(int table);
        void setWaiter(int waiter);
        void setOrderItems(std::vector<std::string> orderItems);
        void setGrilled(bool grilled);
        void setFried(bool fried);
        void setCost(int cost);
        int getMeal();
        int getTable();
        int getWaiter();
        std::vector<std::string> getOrderItems();
        bool getGrilled();
        bool getFried();
        int getCost();
};

#endif // ORDER_H
