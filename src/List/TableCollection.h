#pragma once

#include "List.h"
#include "../Table/TableComponent.h"

class TableCollection : public List<TableComponent*> {
private:
    int numTables;
    int numRemaining;

    int calculateNeededTables(int customers);

public:
    TableCollection(int numTables);
    ~TableCollection();
    TableComponent* getTables(int count);
    bool useTables(int count);
    int getNumTables();
    int getNumRemaining();
};