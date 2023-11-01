#ifndef ASSEMBLYCHEF_H
#define ASSEMBLYCHEF_H

#include "KitchenStation.h"

class AssemblyChef : public KitchenStation {
    public:
        AssemblyChef();
        void prepareDish(Order* dish);
};

#endif // ASSEMBLYCHEF_H
