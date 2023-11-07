#include "TableComponent.h"
#include "../CustomerSession.h"
#include "../State/Ready.h"
#include "../State/Unready.h"

TableComponent::~TableComponent() {}

void TableComponent::occupy() {
    setOccupied(true);
    setCustomerSession(new CustomerSession());

    if ((rand() % 10) < 2) {
        changeState(new Unready());
    } else {
        changeState(new Ready());
    }
}

void TableComponent::vacate() {
    setOccupied(false);
    setNumCustomers(-1);
    changeState(nullptr);
    setCustomerSession(nullptr);
}

string TableComponent::toString() {
    char res[256];

    sprintf(
        res, "%15.s %2.d  Table %2.d %10.d %15.s %15.s %s", 
        getState()->toString(),
        getNumCustomers(),
        getId(), 
        getNumTables(),
        getWaiter()->getName(),
        getStaff()->getName()
    );

    return res;
}