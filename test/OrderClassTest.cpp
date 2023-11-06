#ifndef ORDERCLASSTEST_CPP
#define ORDERCLASSTEST_CPP

#include "allIncludes.h"

TEST(OrderClassUnitTest, OrderClassTestAssertionTrue) {
    std::cout << "-------- TESTING ORDER CLASS -----------" << std::endl;

    // Creating an Order object with the updated constructor
    std::vector<OrderItem> orderItems = {OrderItem(1, 23.6, "Burger"), OrderItem(1, 23.6, "Fries")};
    Order order(1, 1, orderItems, false, false, 47.2);

    // Manipulating the Order object using the updated methods
    order.addItem("Pizza", 2.0, 2); // Adding 2 pizzas
    order.addItemCost(5);

    ASSERT_EQ(true, order.contains("Pizza"));
    ASSERT_EQ(56.2, order.getCost());

    order.setTable(2);
    order.setWaiter(2);
    order.setGrilled(false);
    order.setFried(true);
    order.setMeal("Fish and Chips");

    ASSERT_EQ(2, order.getTable());
    ASSERT_EQ(2, order.getWaiter());
    ASSERT_EQ(false, order.getGrilled());
    ASSERT_EQ(true, order.getFried());
    ASSERT_EQ(56.2, order.getCost());
    ASSERT_EQ("Fish and Chips", order.getMeal());

    ASSERT_EQ(true, order.contains("Fries"));
    order.removeItem("Fries");

    ASSERT_EQ(false, order.contains("Soda"));
    order.addDrink("Soda");
}

#endif
