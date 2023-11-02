#ifndef COMPLETE_H
#define COMPLETE_H

#include "TableState.h"

class Complete : public TableState {
    public:
        void setTableComponent(TableComponent* table);
        void serve();
};

#endif // COMPLETE_H