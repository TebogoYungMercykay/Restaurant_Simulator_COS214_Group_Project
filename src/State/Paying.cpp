#include "Paying.h"

void Paying :: setTableComponent(TableComponent* table) {
    this->table = table;
}

void Paying :: serve() {
    this->table->getCustomerSession()->prepareBill();
    this->table->payBill(this->table->getCustomerSession()->getOrder()->getCost());
    this->table->changeState(new Complete());
}