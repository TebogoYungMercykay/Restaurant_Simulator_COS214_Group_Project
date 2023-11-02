#include "Paying.h"

void setTableComponent(TableComponent* table) {
    this->table = table;
}

void serve() {
    this->table->getCustomerSession()->prepareBill();
    this->table->payBill(this->table->getCustomerSession()->getOrder()->getCost());
    this->table->changeState(new Complete());
}