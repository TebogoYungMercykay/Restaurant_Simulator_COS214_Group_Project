#ifndef WAITING_H
#define WAITING_H

#include "TableState.h"
#include "Paying.h"

class Waiting : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
        string toString();
};

#endif // WAITING_H