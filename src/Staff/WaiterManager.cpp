#include "WaiterManager.h"
#include "../State/TableState.h"
#include "../Restaurant.h"

WaiterManager::WaiterManager(int numWaiters, KitchenManager* kitchen) {
    this->kitchen = kitchen;
    this->numWaiters = numWaiters;
    nextToAssign = 0;

    for (int i = 0; i < numWaiters; i++) {
        waiters.push_back(new Waiter(i));
    }
}

WaiterManager::~WaiterManager() {
    for (Waiter* waiter : waiters) {
        delete waiter;
    }
}

void WaiterManager::assignTable(TableComponent* table) {
    waiters[nextToAssign++ % numWaiters]
        ->getTables()
        ->add(table);
}

void WaiterManager::serve() {
    for (Waiter* waiter : waiters) {
        Iterator<TableComponent*>* iterator = waiter->getIterator();

        if (!iterator->isDone()) {
            iterator->getCurrent()->serve();
        }
    }
}

void WaiterManager::progressWaiters() {
    for (Waiter* waiter : waiters) {
        Iterator<TableComponent*>* iterator = waiter->getIterator();

        if (iterator->isDone()) {
            kitchen->addOrders(waiter->getPendingOrders());
            waiter->addCompletedOrders(kitchen->getCompletedOrders(waiter->getId()));

            iterator->reset();
        } else {
            TableComponent* currentTable = iterator->getCurrent();
            currentTable->setWaiter(NULL);

            iterator->next();
            
            if (currentTable->getState()->toString() == "Complete") {
                Restaurant::instance().staffCheckup.skipTable(currentTable);
                Restaurant::instance().tables.freeTables(currentTable->getNumTables());

                currentTable->vacate();
                waiter->getTables()->remove(currentTable);

                delete currentTable;
            }
        }

        if (!iterator->isDone()) {
            iterator->getCurrent()->setWaiter(waiter);
        }

    }
}

vector<Iterator<TableComponent*>*> WaiterManager::getIterators() {
    vector<Iterator<TableComponent*>*> res;

    for (Waiter* waiter : waiters) {
        res.push_back(waiter->getTables()->getIterator());
    }
    
    return res;
}

string WaiterManager::toString() {
    string res;

    for (Waiter* waiter : waiters) {
        Iterator<TableComponent*>* waiterIterator = waiter
            ->getTables()
            ->getIterator();
        if (!waiterIterator->isDone()) {
            res += "Tables assinged to " + waiter->getName();
            res += "\nState\t\t#C\t\tTableID\t\t#T\t\tOther";
            
            for (; !waiterIterator->isDone(); waiterIterator->next()) {
                res += "\n";
                res += waiterIterator->getCurrent()->toString();
            }

            res += "\n\n\n";
        }
        delete waiterIterator;
    }

    return res;
}