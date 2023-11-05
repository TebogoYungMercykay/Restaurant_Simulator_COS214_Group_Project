#pragma once

#include <string>

using namespace std;

class CustomerSession;
class TableState;
class Waiter;
class Staff;

class TableComponent {
public:
    virtual ~TableComponent();
    virtual int getId() = 0;
    virtual void setOccupied(bool status) = 0;
    virtual bool getOccupied() = 0;
    virtual void setCustomerSession(CustomerSession* session) = 0;
    virtual CustomerSession* getCustomerSession() = 0;
    virtual void setCustomerName(string name) = 0;
    virtual void setWaiter(Waiter* waiter) = 0;
    virtual Waiter* getWaiter() = 0;
    virtual void setStaff(Staff* staff) = 0;
    virtual void changeState(TableState* state) = 0;
    virtual void serve() = 0;
    virtual void add(TableComponent* table) = 0;
    virtual void occupy();
    virtual void vacate();
};