#include "Paying.h"

#include "../CustomerSession.h"
#include "../Restaurant.h"

void Paying::setTableComponent(TableComponent* table) {
    this->table = table;
}

void Paying::serve() {
    std::cout << "Order #" << this->table->getCustomerSession()->getOrder()->getOrderNum() << " Complete."<< std::endl;
    this->table->getCustomerSession()->prepareBill();
    this->table
        ->getCustomerSession()
        ->payBill(this->table->getCustomerSession()->getOrder()->getCost());

    std::cout << std::endl << "How was your experience?" << std::endl;
    std::cout << "ENTER 1: Leave a tip" << std::endl;
    std::cout << "ENTER 2: Log a complaint" << std::endl;
    std::cout << "ENTER 3: Just leave" << std :: endl;
    std::cout << "Enter Option: ";
    int input;
    while(std::cin >> input && input != 1 && input != 2 && input != 3){
        std::cout << "Invalid Input, Choose Option 1 or 2 or 3" << std::endl;
        std::cout << "Enter Option: ";
    }

    cout << endl;
    
    switch (input) {
        case 1:
            std::cout << "Please enter Tip Amount: ";
            double tip;
            std::cin >> tip;
            if (tip > 0) {
                std::cout << "Thank you very much!" << std::endl;
                Restaurant::instance().addTip(tip);
            }
            break;
        case 2: {
            std::cout << "Please enter your complaint: ";
            std::string complaint;
            std::cin.ignore();
            std::getline(std::cin, complaint);
            Restaurant::instance().addComplaint(complaint);
        }
            break;
        case 3:
            std::cout << "Thank for Visiting WackDonald's" << std::endl;
            break;
    }

    
    Restaurant::instance().addRevenue(
        this->table->getCustomerSession()->getOrder()->getCost()
    );

    Complete* var = new Complete();
    var->setTableComponent(this->table);
    this->table->changeState(var);
}

string Paying::toString() {
    return "Paying";
}