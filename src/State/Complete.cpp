#include "Complete.h"

void Complete :: setTableComponent(TableComponent* table) {
    this->table = table;
}

void Complete :: serve() {
    std::cout << "Session Complete" << std::endl;
    // TODO: Clear Memory and Remove Table from Waiter
    this->table->setOccupied(false);
    this->table->setWaiter(nullptr);
    this->table->setStaff(nullptr);
    this->table->setCustomerSession(nullptr);
}