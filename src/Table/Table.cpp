#include "Table.h"
#include "../State/TableState.h"
#include "../CustomerSession.h"

Table::Table(int id) {
    this->id = id;
    numCustomers -1;
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

void Table::setCustomerName(string name) {
    customerName = name;
}

CustomerSession* Table::getCustomerSession() {
    return customerSession;
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
    state->serve();
}

void Table::add(TableComponent* table) {}

TableState* Table::getState() {
    return state;
}

void Table::setNumCustomers(int customers) {
    numCustomers = customers;
}

int Table::getNumCustomers() {
    return numCustomers;
}

int Table::getNumTables() {
    return 1;
};

Staff* Table::getStaff() {
    return staff;
}
