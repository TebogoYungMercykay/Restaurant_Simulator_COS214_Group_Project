#ifndef TABLESTATE_H
#define TABLESTATE_H

#include "../Table/TableComposite.h"
#include "../Table/Table.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class TableState {
    private:
        TableComponent* table;
    public:
        virtual void setTableComponent(TableComponent* table) = 0;
        virtual void serve() = 0;
};

#endif // TABLESTATE_H