#ifndef PAYING_H
#define PAYING_H

#include "TableState.h"

class Paying : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
};

#endif // PAYING_H