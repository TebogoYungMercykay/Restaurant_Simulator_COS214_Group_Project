#ifndef ORDERING_H
#define ORDERING_H

#include "TableState.h"

class Ordering : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
};

#endif // ORDERING_H