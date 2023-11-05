#include "Paying.h"

#include "../CustomerSession.h"

void Paying::setTableComponent(TableComponent* table) {
    this->table = table;
}

void Paying::serve() {
    this->table->getCustomerSession()->prepareBill();
    this->table
        ->getCustomerSession()
        ->payBill(this->table->getCustomerSession()->getOrder()->getCost());
    this->table->changeState(new Complete());
}

string Paying::toString() {
    return "Paying";
}