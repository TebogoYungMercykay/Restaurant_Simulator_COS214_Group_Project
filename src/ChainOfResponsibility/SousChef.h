#ifndef SOUSCHEF_H
#define SOUSCHEF_H

#include "KitchenStation.h"

class SousChef : public KitchenStation {
    public:
        SousChef();
        void prepareDish(Order* dish);
};

#endif // SOUSCHEF_H
