#ifndef READY_H
#define READY_H

#include "TableState.h"
#include "Ready.h"
#include "Waiting.h"

class Ready : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
        string toString();
};

#endif // READY_H