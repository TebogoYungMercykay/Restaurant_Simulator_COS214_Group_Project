#ifndef WACKCRISPYBUILDER_H
#define WACKCRISPYBUILDER_H

#include "OrderBuilder.h"

class WackCrispyBuilder : public OrderBuilder {
    private:
        Order* order;
    public:
        WackCrispyBuilder();
        ~WackCrispyBuilder();
        void addToGrill();
        void addToFry();
        void addToSide();
        void addSpecialSause();
        Order* getOrder();
        void reset();
};

#endif // WACKCRISPYBUILDER_H