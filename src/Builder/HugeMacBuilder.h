#ifndef HUGEMACBUILDER_H
#define HUGEMACBUILDER_H

#include "OrderBuilder.h"

class HugeMacBuilder : public OrderBuilder {
    private:
        Order* order;
    public:
        HugeMacBuilder();
        ~HugeMacBuilder();
        void addToGrill();
        void addToFry();
        void addToSide();
        void addSpecialSause();
        Order* getOrder();
        void reset();
};

#endif // HUGEMACBUILDER_H