#ifndef FRYCOOK_H
#define FRYCOOK_H

#include "KitchenStation.h"

class FryCook : public KitchenStation {
    public:
        FryCook();
        void prepareDish(Order* dish);
};

#endif // FRYCOOK_H
