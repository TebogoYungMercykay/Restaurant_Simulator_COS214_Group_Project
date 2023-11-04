#ifndef BUILDER_CPP
#define BUILDER_CPP

#include "allIncludes.h"

TEST(BuilderTest, BuilderClassTest) {
    OrderDirector director;

    std::vector<OrderBuilder*> builders = {
        new WackNuggetsBuilder(),
        new WackCrispyBuilder(),
        new KotaPounderBuilder(),
        new HugeMacBuilder()
    };

    std::vector<double> buildersPrices = { 47.06, 101.06, 135.73, 91.06 };
    int index = 0;
    for (OrderBuilder* builder : builders) {
        director.setOrderBuilder(builder);
        director.constructOrder();

        std::vector<std::string> removeItems = {"Fries"};
        director.addExtras("Soda", removeItems);

        Order* order = director.getOrder();

        ASSERT_EQ(0, order->getTable());
        ASSERT_EQ(0, order->getWaiter());
        ASSERT_EQ(false, order->getGrilled());
        ASSERT_EQ(false, order->getFried());
        ASSERT_EQ(buildersPrices[index++], order->getCost());

        delete builder;
    }
}

#endif