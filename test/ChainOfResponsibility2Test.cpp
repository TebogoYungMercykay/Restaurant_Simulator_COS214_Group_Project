#ifndef COF2TEST_CPP
#define COF2TEST_CPP

#include "allIncludes.h"

TEST(ChainOfResponsibilityTest, ProgressKitchen) {
    // Creating a KitchenManager object
    KitchenManager kitchenManager;

    // Creating some Order objects
    std::vector<OrderItem> orderItems1 = {OrderItem(1, 23.6, "beef patty"), OrderItem(1, 2.5, "special sauce"), OrderItem(1, 1.5, "cheese"), OrderItem(1, 4.5, "lettuce"), OrderItem(1, 4.5, "pickle"), OrderItem(1, 4.5, "onions"), OrderItem(1, 1.0, "seed bun")};
    Order* order1 = new Order(1, 1, orderItems1, true, false, 42.1);

    std::vector<OrderItem> orderItems2 = {OrderItem(6, 23.0, "nuggets"), OrderItem(1, 4.5, "onions"), OrderItem(1, 4.5, "pickles"), OrderItem(1, 1.5, "cheese"), OrderItem(1, 1.0, "seed bun")};
    Order* order2 = new Order(2, 2, orderItems2, false, true, 149.5);

    std::vector<OrderItem> orderItems3 = {OrderItem(1, 23.6, "beef"), OrderItem(1, 4.5, "onions"), OrderItem(1, 4.5, "pickles"), OrderItem(1, 1.5, "cheese"), OrderItem(1, 1.0, "seed bun")};
    Order* order3 = new Order(3, 3, orderItems3, true, false, 35.1);

    std::vector<OrderItem> orderItems4 = {OrderItem(1, 6.0, "chicken fillet"), OrderItem(2, 3.0, "potato"), OrderItem(2, 2.0, "roll"), OrderItem(1, 1.0, "seed bun")};
    Order* order4 = new Order(4, 4, orderItems4, false, false, 12);

    // Adding orders to the kitchen manager
    kitchenManager.addOrders({order1, order2, order3, order4});

    // Process orders in the kitchen
    kitchenManager.progressKitchen();

    // Testing the number of completed orders
    ASSERT_EQ(4, kitchenManager.getCompletedOrders().size());

    // Additional assertions for each completed order
    Order* completedOrder1 = kitchenManager.getCompletedOrders()[0];
    ASSERT_EQ(1, completedOrder1->getTable());
    ASSERT_EQ(1, completedOrder1->getWaiter());
    ASSERT_EQ(42.1, completedOrder1->getCost());

    Order* completedOrder2 = kitchenManager.getCompletedOrders()[1];
    ASSERT_EQ(2, completedOrder2->getTable());
    ASSERT_EQ(2, completedOrder2->getWaiter());
    ASSERT_EQ(149.5, completedOrder2->getCost());


    Order* completedOrder3 = kitchenManager.getCompletedOrders()[2];
    ASSERT_EQ(3, completedOrder3->getTable());
    ASSERT_EQ(3, completedOrder3->getWaiter());
    ASSERT_EQ(35.1, completedOrder3->getCost());

    Order* completedOrder4 = kitchenManager.getCompletedOrders()[3];
    ASSERT_EQ(4, completedOrder4->getTable());
    ASSERT_EQ(4, completedOrder4->getWaiter());
    ASSERT_EQ(17, completedOrder4->getCost());

    // Clean up memory
    delete order1;
    delete order2;
    delete order3;
    delete order4;
}

#endif