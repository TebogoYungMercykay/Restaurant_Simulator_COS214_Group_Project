#include "TableComposite.h"


int TableComposite::getId() {
    return tables.front()->getId();
}

void TableComposite::setOccupied(bool status) {
    for (TableComponent* table : tables) {
        table->setOccupied(status);
    }
}

bool TableComposite::getOccupied() {
    return tables.front()->getOccupied();
}

void TableComposite::setCustomerSession(CustomerSession* session) {
    for (TableComponent* table : tables) {
        table->setCustomerSession(session);
    }
}

CustomerSession* TableComposite::getCustomerSession() {
    return tables.front()->getCustomerSession();
}

void TableComposite::setCustomerName(string name) {
    for (TableComponent* table : tables) {
        table->setCustomerName(name);
    }
}

void TableComposite::setWaiter(Waiter* waiter) {
    for (TableComponent* table : tables) {
        table->setWaiter(waiter);
    }
}

Waiter* TableComposite::getWaiter() {
    return tables.front()->getWaiter();
}

void TableComposite::setStaff(Staff* staff) {
    for (TableComponent* table : tables) {
        table->setStaff(staff);
    }
}

void TableComposite::changeState(TableState* state) {
    for (TableComponent* table : tables) {
        table->changeState(state);
    }
}

void TableComposite::serve() {
    tables.front()->serve();
}


void TableComposite::add(TableComponent* table) {
    tables.push_back(table);
}