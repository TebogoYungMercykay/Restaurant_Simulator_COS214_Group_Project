#ifndef TABLESTATE_H
#define TABLESTATE_H

#include "./../Table/TableComponent.h"

using namespace std;

class TableState {
    private:
        TableComponent* table;
    public:
        virtual void setTableComponent(TableComponent* table) = 0;
        virtual void serve() = 0;
};

#endif // TABLESTATE_H