#ifndef COFTEST_CPP
#define COFTEST_CPP

#include "allIncludes.h"

TEST(ChainOfResponsibilityTest, ChainOfResponsibilityTest1) {
    // Creating a KitchenManager object
    KitchenManager kitchenManager;

    // Creating some Order objects
    std::vector<OrderItem> orderItems1 = {OrderItem(1, 23.6, "beef patty"), OrderItem(1, 4.5, "onions"), OrderItem(1, 4.5, "pickles"), OrderItem(1, 1.5, "cheese")};
    std::vector<OrderItem> orderItems2 = {OrderItem(1, 23.6, "fries"), OrderItem(1, 4.5, "onions"), OrderItem(1, 4.5, "pickles"), OrderItem(1, 1.5, "cheese")};
    Order* order1 = new Order(1, 1, orderItems1, true, false, 10);
    Order* order2 = new Order(2, 2, orderItems2, false, true, 5);

    // Adding orders to the kitchen manager
    kitchenManager.addOrders({order1, order2});

    // Testing the getter for orders
    ASSERT_EQ(2, kitchenManager.getOrders().size());
    ASSERT_EQ(order1, kitchenManager.getOrders()[0]);
    ASSERT_EQ(order2, kitchenManager.getOrders()[1]);

    // Processing orders in the kitchen
    kitchenManager.progressKitchen();

    // Testing the getter for completedOrders
    ASSERT_EQ(1, kitchenManager.getCompletedOrders(1).size());
    ASSERT_EQ(order2, kitchenManager.getCompletedOrders(2)[0]);
    ASSERT_EQ(0, kitchenManager.getCompletedOrders(0).size());
    ASSERT_EQ(0, kitchenManager.getCompletedOrders(1).size());
    ASSERT_EQ(0, kitchenManager.getCompletedOrders(2).size());
}

#endif
