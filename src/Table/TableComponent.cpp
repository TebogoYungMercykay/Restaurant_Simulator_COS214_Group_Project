#include "TableComponent.h"
#include "../CustomerSession.h"
#include "../State/Ready.h"
#include "../State/Unready.h"

TableComponent::~TableComponent() {}

void TableComponent::occupy() {
    setOccupied(true);
    setCustomerSession(new CustomerSession());

    TableState* state;
    if ((rand() % 10) < 2) {
        state = new Unready();
    } else {
        state = new Ready();
    }

    state->setTableComponent(this);
    changeState(state);
}

void TableComponent::vacate() {
    setOccupied(false);
    setNumCustomers(-1);
    changeState(nullptr);
    setCustomerSession(nullptr);
    setWaiter(nullptr);
    setStaff(nullptr);
}

string TableComponent::toString() {
    char res[256];

    sprintf(
        res, "%s\t\t%d\t\tTable %d\t\t%d\t\t%s\t%s",  
        (getState()->toString()).c_str(),
        getNumCustomers(),
        getId(), 
        getNumTables(),
        (getWaiter() ? getWaiter()->getName() : "").c_str(),
        (getStaff() ? getStaff()->getName() : "").c_str()
    );

    return res;
}