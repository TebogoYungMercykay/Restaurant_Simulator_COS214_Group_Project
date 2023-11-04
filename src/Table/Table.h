#pragma once

#include "TableComponent.h"

class Table : public TableComponent {
private:
    int id;
    bool occupied;
    TableState* state;
    CustomerSession* customerSession;
    string customerName;
    Waiter* waiter;
    Staff* staff;

public:
    Table(int id);
    int getId();
    void setOccupied(bool status);
    bool getOccupied();
    void setCustomerSession(CustomerSession* session);
    CustomerSession* getCustomerSession();
    void setCustomerName(string name);
    void setWaiter(Waiter* waiter);
    Waiter* getWaiter();
    void setStaff(Staff* staff);
    void changeState(TableState* state);
    void serve();
    void add(TableComponent* table);
};