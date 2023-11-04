#include "TableComposite.h"

#include "../CustomerSession.h"

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
    tables.front()->setCustomerSession(session);
}

CustomerSession* TableComposite::getCustomerSession() {
    return tables.front()->getCustomerSession();
}

void TableComposite::setCustomerName(string name) {
    tables.front()->setCustomerName(name);
}

void TableComposite::setWaiter(Waiter* waiter) {
    tables.front()->setWaiter(waiter);
}

Waiter* TableComposite::getWaiter() {
    return tables.front()->getWaiter();
}

void TableComposite::setStaff(Staff* staff) {
    tables.front()->setStaff(staff);
}

void TableComposite::changeState(TableState* state) {
    tables.front()->changeState(state);
}

void TableComposite::serve() {
    tables.front()->serve();
}

void TableComposite::add(TableComponent* table) {
    tables.push_back(table);
}