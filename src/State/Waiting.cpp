#include "Waiting.h"
#include <cstdlib>
#include <ctime>
#include "../CustomerSession.h"

void Waiting::setTableComponent(TableComponent* table) {
    this->table = table;
}

void Waiting::serve() {
    // Random number between 23 and 150
    int random_number = rand() % (128) + 23;
    this->table->getCustomerSession()->getOrder()->setOrderNum(random_number);

    bool orderDone = table->getWaiter()->removeOrder(
        table->getCustomerSession()->getOrder()
    );

    if (orderDone) {
        Paying* var = new Paying();
        var->setTableComponent(this->table);
        this->table->changeState(var);
    }

}

string Waiting::toString() {
    return "Waiting";
}