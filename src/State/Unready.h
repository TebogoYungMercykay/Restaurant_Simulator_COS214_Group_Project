#ifndef UNREADY_H
#define UNREADY_H

#include "TableState.h"
#include "Ready.h"

class Unready : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
};

#endif // UNREADY_H