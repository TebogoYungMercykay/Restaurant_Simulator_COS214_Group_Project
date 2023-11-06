#ifndef GRILLCOOK_H
#define GRILLCOOK_H

#include "KitchenStation.h"

class GrillCook : public KitchenStation {
    public:
        GrillCook();
        void prepareDish(Order* dish);
};

#endif // GRILLCOOK_H
