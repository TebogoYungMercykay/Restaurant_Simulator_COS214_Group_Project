#ifndef WAITING_H
#define WAITING_H

#include "TableState.h"

class Waiting : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
};

#endif // WAITING_H