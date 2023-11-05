#include "WaiterManager.h"

WaiterManager::WaiterManager(int numWaiters, KitchenManager* kitchen) {
    this->kitchen = kitchen;
    this->numWaiters = numWaiters;
    nextToAssign = 0;

    /* 
     * I was getting a weird error here because of storing the 
     * Waiters by value. It looks like the Waiter object was created on 
     * the stack of the current function, copied over to the vector and then 
     * when the for loop ended the local copies went out of scope and were 
     * deleted. This also deleted the pointers they stored. When the program
     * ended and the copies in the vector were destroyed they tried to delete 
     * the pointers again n I got double free erros.
    */
    for (int i = 0; i < 1; i++) {
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
        waiter->getIterator()->getCurrent()->setWaiter(waiter);
        waiter->getIterator()->getCurrent()->serve();
    }
}

void WaiterManager::progressWaiters() {
    for (Waiter* waiter : waiters) {
        Iterator<TableComponent*>* iterator = waiter->getIterator();

        if (iterator->isDone()) {
            kitchen->addOrders(waiter->getPendingOrders());
            waiter->addCompletedOrders(kitchen->getCompletedOrders());
            // TODO: Add id parameter to add getCompletedOrders

            iterator->reset();
            continue;
        }

        iterator->getCurrent()->setWaiter(NULL);
        iterator->next();
    }
}
