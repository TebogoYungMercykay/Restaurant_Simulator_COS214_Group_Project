#ifndef ORDERBUILDER_H
#define ORDERBUILDER_H

#include "Order.h"

class OrderBuilder {
    public:
        virtual ~OrderBuilder() {};
        virtual void addToGrill() = 0;
        virtual void addToFry() = 0;
        virtual void addToSide() = 0;
        virtual void addSpecialSause() = 0;
        virtual Order* getOrder() = 0;
        virtual void reset() = 0;
};

#endif // ORDERBUILDER_H