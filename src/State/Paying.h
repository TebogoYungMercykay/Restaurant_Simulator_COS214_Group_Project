#ifndef PAYING_H
#define PAYING_H

#include "TableState.h"
#include "Complete.h"

class Paying : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
        string toString();
};

#endif // PAYING_H