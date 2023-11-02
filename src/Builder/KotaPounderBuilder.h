#ifndef KOTAPOUNDERBUILDER_H
#define KOTAPOUNDERBUILDER_H

#include "OrderBuilder.h"

class KotaPounderBuilder : public OrderBuilder {
    private:
        Order* order;
    public:
        KotaPounderBuilder();
        ~KotaPounderBuilder();
        void addToGrill();
        void addToFry();
        void addToSide();
        void addSpecialSause();
        Order* getOrder();
        void reset();
};

#endif // KOTAPOUNDERBUILDER_H