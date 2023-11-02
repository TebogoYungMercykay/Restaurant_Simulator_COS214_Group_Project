#ifndef READY_H
#define READY_H

#include "TableState.h"

class Ready : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
};

#endif // READY_H