#include "TableCollection.h"

TableCollection::TableCollection(int numTables) {
    this->numRemaining = this->numTables = numTables;

    for (int i = 0; i < numTables; i++) {
        add(new Table(i));
    }
}

TableCollection::~TableCollection() {
    Iterator<TableComponent*>* iterator = getIterator();

    for(; !iterator->isDone(); iterator->next()) {
        delete iterator->getCurrent();
    }

    delete iterator;
}

int TableCollection::calculateNeededTables(int customers) {
    return (customers - 1) / 2 + 1;
}

TableComponent* TableCollection::getTables(int count) {
    int neededTables = calculateNeededTables(count);

    TableComponent* groupedTables = new TableComposite();
    Iterator<TableComponent*>* iterator = getIterator();

    for (; neededTables > 0; iterator->next()) {
        if (!iterator->getCurrent()->getOccupied()) {
            groupedTables->add(iterator->getCurrent());
            neededTables--;
        }
    }

    delete iterator;

    groupedTables->occupy();
    return groupedTables;
}

bool TableCollection::useTables(int count) {
    int numTables = calculateNeededTables(count);

    if (numTables > numRemaining) {
        return false;
    }

    numRemaining -= numTables;
    return true;
}

int TableCollection::getNumTables() {
    return numTables;
}

int TableCollection::getNumRemaining() {
    return numRemaining;
}

string TableCollection::toString() {
    return "";
}
