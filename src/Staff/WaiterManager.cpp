#include "WaiterManager.h"

WaiterManager::WaiterManager(int numWaiters, KitchenManager* kitchen) {
    this->kitchen = kitchen;
    this->numWaiters = numWaiters;
    nextToAssign = 0;

    for (int i = 0; i < numWaiters; i++) {
        waiters.emplace_back(i);
    }
}

void WaiterManager::assignTable(TableComponent* table) {
    waiters[nextToAssign++ % numWaiters]
        .getTables()
        ->add(table);
}

void WaiterManager::serve() {
    for (Waiter& waiter : waiters) {
        waiter.getIterator()->getCurrent()->setWaiter(&waiter);
        waiter.getIterator()->getCurrent()->serve();
    }
}

void WaiterManager::progressWaiters() {
    for (Waiter& waiter : waiters) {
        Iterator<TableComponent*>* iterator = waiter.getIterator();

        if (iterator->isDone()) {
            kitchen->addOrders(waiter.getPendingOrders());
            waiter.addCompletedOrders(kitchen->getCompletedOrders(waiter.getId()));
            // TODO: Add id parameter to add getCompletedOrders

            iterator->reset();
            continue;
        }

        iterator->getCurrent()->setWaiter(NULL);
        iterator->next();
    }
}
