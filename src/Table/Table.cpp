#include "Table.h"

#include "../CustomerSession.h"

Table::Table(int id) : id(id) {}

int Table::getId() {
    return id;
}

void Table::setOccupied(bool status) {
    occupied = status;
}

bool Table::getOccupied() {
    return occupied;
}

void Table::setCustomerSession(CustomerSession* session) {
    customerSession = session;
}

CustomerSession* Table::getCustomerSession() {
    return customerSession;
}

void Table::setCustomerName(string name) {
    customerName = name;
}

void Table::setWaiter(Waiter* waiter) {
    this->waiter = waiter;
}

void Table::setStaff(Staff* staff) {
    this->staff = staff;
}

void Table::changeState(TableState* state) {
    delete state;
    this->state = state;
}

void Table::serve() {
    // TODO: Implement
    // state->serve();
}

void Table::add(TableComponent* table) {}