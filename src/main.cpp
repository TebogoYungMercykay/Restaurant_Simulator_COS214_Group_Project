#include <cassert>
#include <iostream>
#include <vector>

#include "./Staff/StaffCheckup.h"
#include "./ChainOfResponsibility/KitchenManager.h"
#include "./Builder/Order.h"
#include "./Builder/OrderItem.h"
#include "./Builder/OrderDirector.h"
#include "./Builder/WackNuggetsBuilder.h"
#include "./Builder/WackCrispyBuilder.h"
#include "./Builder/KotaPounderBuilder.h"
#include "./Builder/HugeMacBuilder.h"
#include "CustomerSession.h"
#include "Bill/SingleBill.h"
#include "Bill/SplitBill.h"
#include "Tab/Tab.h"
#include "Tab/TabStore.h"

void testSingleBill();
void testSplitBill();
void testTab();
void testTabStore();
void testingOrderClass();
void testingStaffCheckupClass();
void testChainOfResponsibility1();
void testChainOfResponsibility2();
void testingBuilder();

int main(int argc, char **argv) {
    std::cout << "Hello, 214 Project!" << std::endl;
    testSingleBill();
    testSplitBill();
    testTab();
    testTabStore();
    testingOrderClass();
    testChainOfResponsibility1();
    testChainOfResponsibility2();
    testingStaffCheckupClass();
    testingBuilder();
    return 0;
}


void testingOrderClass() {
    std::cout << "-------- TESTING ORDER CLASS -----------" << std::endl;

    // Creating an Order object with the updated constructor
    std::vector<OrderItem> orderItems = {OrderItem(1, 23.6, "Burger"), OrderItem(1, 23.6, "Fries")};
    Order order(1, 1, orderItems, false, false, 10);

    // Manipulating the Order object using the updated methods
    order.addItem("Pizza", 2.0, 2); // Adding 2 pizzas
    order.addItemCost(5);
    std::cout << "After adding 'Pizza':\n";
    std::cout << "Contains 'Pizza': " << (order.contains("Pizza") ? "Yes" : "No") << std::endl;
    std::cout << "Cost: " << order.getCost() << std::endl;

    std::cout << "Items as string: " << order.toStringItems() << std::endl;

    order.setTable(2);
    order.setWaiter(2);
    order.setGrilled(false);
    order.setFried(true);
    order.setMeal("Fish and Chips");
    std::cout << "After using setter methods:\n";
    std::cout << "Table: " << order.getTable() << std::endl;
    std::cout << "Waiter: " << order.getWaiter() << std::endl;
    std::cout << "Grilled: " << (order.getGrilled() ? "Yes" : "No") << std::endl;
    std::cout << "Fried: " << (order.getFried() ? "Yes" : "No") << std::endl;
    std::cout << "Cost: " << order.getCost() << std::endl;
    std::cout << "Meal: " << order.getMeal() << std::endl;

    std::cout << "Before removing 'Fries':\n";
    std::cout << "Contains 'Fries': " << (order.contains("Fries") ? "Yes" : "No") << std::endl;
    order.removeItem("Fries");
    std::cout << "After removing 'Fries':\n";
    std::cout << "Contains 'Fries': " << (order.contains("Fries") ? "Yes" : "No") << std::endl;

    std::cout << "Before adding 'Soda':\n";
    std::cout << "Contains 'Soda': " << (order.contains("Soda") ? "Yes" : "No") << std::endl;
    order.addDrink("Soda");
    std::cout << "After adding 'Soda':\n";
    std::cout << "Contains 'Soda': " << (order.contains("Soda") ? "Yes" : "No") << std::endl;

    std::cout << std::endl;
}

void testingStaffCheckupClass() {
    // TODO: Temporary Code
    std::cout << "-------- TESTING STAFF CHECKUP CLASS ----------" << std::endl;
    // Creating StaffCheckup object
    StaffCheckup* checkup = new StaffCheckup(4, 5);

    // Adding some staff members
    for (int i = 0; i < 5; ++i) {
        Staff* staff = new Staff();
        staff->setName("Staff " + std::to_string(i + 1));
        checkup->addStaff(staff);
    }

    // Adding some tables
    for (int i = 0; i < 7; ++i) {
        TemporaryTableClass* table = new TemporaryTableClass(i + 1);
        checkup->addTable(table);
    }

    // Performing checkup
    checkup->progressCheckup();
    delete checkup;
    checkup = nullptr;
    std::cout << std::endl;
}

void testChainOfResponsibility1() {
    std::cout << "-------- TESTING Chain Of Responsibility 1 -----------" << std::endl;
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
    assert(kitchenManager.getOrders().size() == 2);
    assert(kitchenManager.getOrders()[0] == order1);
    assert(kitchenManager.getOrders()[1] == order2);

    // Processing orders in the kitchen
    kitchenManager.progressKitchen();

    // Testing the getter for completedOrders
    assert(kitchenManager.getCompletedOrders(1).size() == 1);
    assert(kitchenManager.getCompletedOrders(2)[0] == order2);
    assert(kitchenManager.getCompletedOrders(0).size() == 0);
    assert(kitchenManager.getCompletedOrders(1).size() == 0);
    assert(kitchenManager.getCompletedOrders(2).size() == 0);

    std::cout << std::endl;
}

void testChainOfResponsibility2() {
    std::cout << "-------- TESTING Chain Of Responsibility 2 -----------" << std::endl;
    // Creating a KitchenManager object
    KitchenManager kitchenManager;

    // Creating some Order objects
    std::vector<OrderItem> orderItems1 = {OrderItem(1, 23.6, "beef patty"), OrderItem(1, 2.5, "special sauce"), OrderItem(1, 1.5, "cheese"), OrderItem(1, 4.5, "lettuce"), OrderItem(1, 4.5, "pickle"), OrderItem(1, 4.5, "onions"), OrderItem(1, 1.0, "seed bun")};
    Order* order1 = new Order(1, 1, orderItems1, true, false, 10);

    std::vector<OrderItem> orderItems2 = {OrderItem(6, 23.0, "nuggets"), OrderItem(1, 4.5, "onions"), OrderItem(1, 4.5, "pickles"), OrderItem(1, 1.5, "cheese"), OrderItem(1, 1.0, "seed bun")};
    Order* order2 = new Order(2, 2, orderItems2, false, true, 5);

    std::vector<OrderItem> orderItems3 = {OrderItem(1, 23.6, "beef"), OrderItem(1, 4.5, "onions"), OrderItem(1, 4.5, "pickles"), OrderItem(1, 1.5, "cheese"), OrderItem(1, 1.0, "seed bun")};
    Order* order3 = new Order(3, 3, orderItems3, true, false, 70);

    std::vector<OrderItem> orderItems4 = {OrderItem(1, 6.0, "chicken fillet"), OrderItem(2, 3.0,"potato"), OrderItem(2, 2.0,"roll"), OrderItem(1, 1.0, "seed bun")};
    Order* order4 = new Order(4, 4, orderItems4,false,false ,65);


    // Adding orders to the kitchen manager
    kitchenManager.addOrders({order1, order2, order3, order4});

    // Process orders in the kitchen
    kitchenManager.progressKitchen();

    // Printing completed orders
    int orderNum = 1;
    std::cout << "Completed Orders:" << std::endl;
    for (Order* order : kitchenManager.getCompletedOrders(orderNum++)) {
        std::cout << "Table: " << order->getTable() << ", Waiter: " << order->getWaiter() << ", Cost: " << order->getCost() << std::endl;
        delete order;  // Don't forget to delete the orders when you're done with them!
    }
    std::cout << std::endl;
}

void testingBuilder() {
    std::cout << "-------- TESTING BUILDER CLASS -----------" << std::endl;

    OrderDirector director;

    std::vector<OrderBuilder*> builders = {
        new WackNuggetsBuilder(),
        new WackCrispyBuilder(),
        new KotaPounderBuilder(),
        new HugeMacBuilder()
    };

    for (OrderBuilder* builder : builders) {
        director.setOrderBuilder(builder);
        director.constructOrder();

        std::vector<std::string> removeItems = {"Fries"};
        director.addExtras("Soda", removeItems);

        Order* order = director.getOrder();

        std::cout << "----- Order Details: " << order->getMeal() << " -----\n";
        std::cout << "Table: " << order->getTable() << std::endl;
        std::cout << "Waiter: " << order->getWaiter() << std::endl;
        std::cout << "Grilled: " << (order->getGrilled() ? "Yes" : "No") << std::endl;
        std::cout << "Fried: " << (order->getFried() ? "Yes" : "No") << std::endl;
        std::cout << "Cost: " << order->getCost() << std::endl;
        std::cout << "Meal: " << order->getMeal() << std::endl;
        std::cout << "Items: " << order->toStringItems() << std::endl;
        std::cout << std::endl;
    }
}

void testSingleBill(){
    cout << "-------- TESTING SINGLE BILL CLASS -----------" << endl;
    SingleBill singleBill(600);
    assert(singleBill.getAmount());
    cout << "SINGLE BILL TESTS PASSED"<<endl;
}

void testSplitBill(){
    cout << "-------- TESTING SPLIT BILL CLASS -----------" << endl;

    SplitBill* splitBill = new SplitBill();

    SingleBill* s1 = new SingleBill(200);
    SingleBill* s2 = new SingleBill(200);
    SingleBill* s3 = new SingleBill(200);
    SingleBill* s4 = new SingleBill(200);

    splitBill->addBill(s1);
    splitBill->addBill(s2);
    splitBill->addBill(s3);
    splitBill->addBill(s4);

    assert(splitBill->getAmount() ==800);

    delete splitBill;
    splitBill = nullptr;

    cout << "SPLIT BILL TESTS PASSED"<<endl;

}

void testTab(){
    cout << "-------- TESTING TAB CLASS -----------" << endl;

    Tab* tab = new Tab("Customer 1", 600);

    assert(tab->getCustomerName() == "Customer 1");
    assert(tab->getAmount() == 600);

    delete tab;
    tab = nullptr;

    cout << "TAB TESTS PASSED"<<endl;
}

void testTabStore(){
    cout << "-------- TESTING TAB STORE CLASS -----------" << endl;
    TabStore* tabStorage = new TabStore();

    Tab* tab1 = new Tab("Customer 1", 600);
    Tab* tab2 = new Tab("Customer 2", 800);
    Tab* tab3 = new Tab("Customer 3", 300);
    Tab* tab4 = new Tab("Customer 4", 2500);
    Tab* tab5 = new Tab("Customer 5", 6000);

    tabStorage->addTab(tab1);
    tabStorage->addTab(tab2);
    tabStorage->addTab(tab3);
    tabStorage->addTab(tab4);
    tabStorage->addTab(tab5);

    assert(tabStorage->getNumTabs() == 5);
    assert(tabStorage->getTab("Customer 1")->getCustomerName() == "Customer 1");
    assert(tabStorage->getTab("Customer 10") == nullptr);
    assert(tabStorage->tabExists("Customer 1") == false);
    assert(tabStorage->tabExists("Customer 2") == true);
    assert(tabStorage->getNumTabs() == 4);

    cout << "TAB STORE TESTS PASSED" << endl;
}

// void testCustomerSession(){
//     // TODO
// }
