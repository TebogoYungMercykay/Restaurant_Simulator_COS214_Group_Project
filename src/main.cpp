#include "KitchenManager.h"
#include "Order.h"
#include <cassert>
#include <iostream>

void testingOrderClass();
void testChainOfResponsibility1();
void testChainOfResponsibility2();

int main(int argc, char **argv) {
    std::cout << "Hello, 214 Project!" << std::endl;
    testingOrderClass();
    testChainOfResponsibility1();
    testChainOfResponsibility2();
    return 0;
}

void testingOrderClass() {
    std::cout << "-------- TESTING ORDER CLASS -----------" << std::endl;
    // Creating an Order object
    Order order(1, 1, {"Burger", "Fries"}, true, false, 10);

    // Testing the getters
    std::cout << "Table: " << order.getTable() << std::endl;
    std::cout << "Waiter: " << order.getWaiter() << std::endl;
    std::cout << "Grilled: " << (order.getGrilled() ? "Yes" : "No") << std::endl;
    std::cout << "Fried: " << (order.getFried() ? "Yes" : "No") << std::endl;
    std::cout << "Cost: " << order.getCost() << std::endl;

    // Testing the contains method
    std::cout << "Contains 'Burger': " << (order.contains("Burger") ? "Yes" : "No") << std::endl;
    std::cout << "Contains 'Pizza': " << (order.contains("Pizza") ? "Yes" : "No") << std::endl;

    // Testing the addItem and addItemCost methods
    order.addItem("Pizza");
    order.addItemCost(5);
    std::cout << "After adding 'Pizza':\n";
    std::cout << "Contains 'Pizza': " << (order.contains("Pizza") ? "Yes" : "No") << std::endl;
    std::cout << "Cost: " << order.getCost() << std::endl;
    std::cout << std::endl;
}

void testChainOfResponsibility1() {
    std::cout << "-------- TESTING Chain Of Responsibility 1 -----------" << std::endl;
    // Creating a KitchenManager object
    KitchenManager kitchenManager;

    // Creating some Order objects
    Order* order1 = new Order(1, 1, {"Burger"}, true, false, 10);
    Order* order2 = new Order(2, 2, {"Fries"}, false, true, 5);

    // Adding orders to the kitchen manager
    kitchenManager.addOrders({order1, order2});

    // Testing the getter for orders
    assert(kitchenManager.getOrders().size() == 2);
    assert(kitchenManager.getOrders()[0] == order1);
    assert(kitchenManager.getOrders()[1] == order2);

    // Processing orders in the kitchen
    kitchenManager.progressKitchen();

    // Testing the getter for completedOrders
    assert(kitchenManager.getCompletedOrders().size() == 2);
    assert(kitchenManager.getCompletedOrders()[0] == order1);
    assert(kitchenManager.getCompletedOrders()[1] == order2);

    // Cleaning up
    delete order1;
    delete order2;
    std::cout << std::endl;
}

// fries, ensure, preparation, takeaway, dine-in, steak

void testChainOfResponsibility2() {
    std::cout << "-------- TESTING Chain Of Responsibility 2 -----------" << std::endl;
    // Creating a KitchenManager object
    KitchenManager kitchenManager;

    // Creating some Order objects
    Order* order1 = new Order(1, 1, {"ice-cream"}, true, false, 10);
    Order* order2 = new Order(2, 2, {"fries"}, false, true, 5);
    Order* order3 = new Order(3, 3, {"fries", "ensure", "preparation", "takeaway", "steak"}, true, false, 70);
    Order* order4 = new Order(4, 4, {"preparation", "steak", "fries", "ensure", "dine-in"}, false, false, 65);

    // Adding orders to the kitchen manager
    kitchenManager.addOrders({order1, order2, order3, order4});

    // Process orders in the kitchen
    kitchenManager.progressKitchen();

    // Printing completed orders
    std::cout << "Completed Orders:" << std::endl;
    for (Order* order : kitchenManager.getCompletedOrders()) {
        std::cout << "Table: " << order->getTable() << ", Waiter: " << order->getWaiter() << ", Cost: " << order->getCost() << std::endl;
        delete order;  // Don't forget to delete the orders when you're done with them!
    }
    std::cout << std::endl;
}