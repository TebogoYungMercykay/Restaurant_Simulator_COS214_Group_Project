#include "Table.h"
#include "../State/TableState.h"
#include "../CustomerSession.h"

Table::Table(int id) {
    this->id = id;
    occupied = false;
    state = nullptr;
    customerSession = nullptr;
    waiter = nullptr;
    staff = nullptr;
}

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
    if (customerSession) {
        delete customerSession;
    }

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

Waiter* Table::getWaiter() {
    return waiter;
}

void Table::setStaff(Staff* staff) {
    this->staff = staff;
}

void Table::changeState(TableState* state) {
    if (this->state) {
        delete this->state;
    }

    this->state = state;
}

void Table::serve() {
    // TODO: Implement
    state->serve();
}

void Table::add(TableComponent* table) {}
