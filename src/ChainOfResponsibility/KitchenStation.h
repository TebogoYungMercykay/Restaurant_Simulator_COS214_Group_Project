#ifndef KITCHENSTATION_H
#define KITCHENSTATION_H

#include "../Staff/Staff.h"
#include "./../Builder/Order.h"
#include <string>
#include <iostream>

class KitchenStation : public Staff {
    protected:
        KitchenStation* nextStation;

    public:
        KitchenStation();
        virtual ~KitchenStation(){}
        virtual void prepareDish(Order* dish) = 0;
        void setNext(KitchenStation* next);
};

#endif // KITCHENSTATION_H
