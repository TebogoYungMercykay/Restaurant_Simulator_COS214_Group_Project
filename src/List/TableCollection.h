#pragma once

#include "List.h"
#include "../Table/TableComposite.h"
#include "../Table/Table.h"

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
    void freeTables(int count);
    int getNumTables();
    int getNumRemaining();
    string toString();
};