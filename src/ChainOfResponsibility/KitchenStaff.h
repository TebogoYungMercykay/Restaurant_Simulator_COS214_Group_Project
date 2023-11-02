#ifndef KITCHENSTAFF_H
#define KITCHENSTAFF_H

#include "KitchenStation.h"

class KitchenStaff : public KitchenStation {
    public:
        KitchenStaff();
        void prepareDish(Order* dish);
};

#endif // KITCHENSTAFF_H
