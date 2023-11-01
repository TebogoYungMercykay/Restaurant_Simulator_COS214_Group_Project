#ifndef WACKNUGGETSBUILDER_H
#define WACKNUGGETSBUILDER_H

#include "OrderBuilder.h"

class WackNuggetsBuilder : public OrderBuilder {
    private:
        Order* order;
    public:
        WackNuggetsBuilder();
        ~WackNuggetsBuilder();
        void addToGrill();
        void addToFry();
        void addToSide();
        void addSpecialSause();
        Order* getOrder();
        void reset();
};

#endif // WACKNUGGETSBUILDER_H
