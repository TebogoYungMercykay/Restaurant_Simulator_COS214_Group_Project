#include "Ready.h"
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>

void Ready ::setTableComponent(TableComponent* table) {
    this->table = table;
}

void Ready ::serve() {
    if (this->table != nullptr) {
        int option;
        std::cout << "The waiter is ready to Serve, Please view the Menu to Order." << std::endl;
        std::cout << "------------------ WackDonald's Main MENU ------------------\n";
        std::cout << "\t1. HugeMac\n";
        std::cout << "\t2. WackCrispy\n";
        std::cout << "\t3. WackNuggets\n";
        std::cout << "\t4. Quarter Pounder\n";
        std::cout << "\t5. Custom Order\n";
        std::cout << "-------------------------------------------------------\n";
        cout << "Enter Option: ";
        while (cin >> option && (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)) {
            std::cout << "Invalid input. Please respond with '1' or '2' or '3' or '4' or '5'.\n";
            cout << "Enter Option: ";
        }
        if (option == 1) {
            this->table->getCustomerSession()->createOrder({"HugeMac"});
        } else if (option == 2) {
            this->table->getCustomerSession()->createOrder({"WackCrispy"});
        } else if (option == 3) {
            this->table->getCustomerSession()->createOrder({"WackNuggets"});
        } else if (option == 4) {
            this->table->getCustomerSession()->createOrder({"KotaPounder"});
        } else {
            // Custom Menu Options
            std::map<std::string, double> menu = {
                {"Nuggets", 2.50},
                {"Fries", 20.00},
                {"Pickle Juice", 22.50},
                {"Marinate", 3.50},
                {"Chicken Breast", 55.50},
                {"Crinkle-Cut Pickles", 9.50},
                {"Toasted Potato Roll", 15.00},
                {"Spicy Pepper Sauce", 2.50},
                {"Beef", 45.67},
                {"Bacon", 23.50},
                {"Cheese", 5.50},
                {"Tangy Pickles", 19.50},
                {"Silver Onions", 9.50},
                {"Seed Bun", 11.00},
                {"Salt and Pepper", 2.50},
                {"Beef Patty", 27.50},
                {"Pickle", 15.50},
                {"Lettuce", 4.50},
                {"Tomato", 2.50},
                {"Onions", 3.50},
                {"Special Sauce", 2.50}
            };
            // Printing the Custom Menu
            std::cout << "------------------ WackDonald's Custom Order MENU ------------------\n";
            int i = 1;
            for (const auto &item : menu) {
                std::cout << "\t" << std::setfill('0') << std::setw(2) << std::right << i << "." << std::setfill(' ') << std::setw(25) << std::left << item.first << "$" << std::fixed << std::setprecision(2) << item.second << "\n";
                i++;
            }
            std::cout << "------------------------------------------------------------------\n";
            std::string order_items;
            vector<std::string> orderItems = {};
            std::cout << "Enter a comma-separated list of items numbers to Add to your Order: ";
            std::cin.ignore();
            std::getline(std::cin, order_items);
            std::stringstream streamObj (order_items);
            std::string item_number;
            // Extracting Items from the Comma Delimited List
            while (std::getline(streamObj, item_number, ',')) {
                int item_index = std::stoi(item_number) - 1;
                if (item_index >= 0 && item_index < menu.size()) {
                    auto it = menu.begin();
                    std::advance(it, item_index);
                    std::cout << "Added " << it->first << " to your order.\n";
                    orderItems.push_back(it->first);
                }
            }
            // Creating the Order
            this->table->getCustomerSession()->createOrder(orderItems);
        }
    } else {
        std::cout << "Error: No Table Assigned Yet.\n";
        return;
    }
    std::cout << "Thank you for your order! Your order is being prepared." << std::endl;
    this->table->changeState(new Waiting());
}
