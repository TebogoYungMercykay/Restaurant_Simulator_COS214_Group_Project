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
    changeState(nullptr);
    setCustomerSession(nullptr);
}