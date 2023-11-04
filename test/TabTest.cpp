#ifndef TABTEST_CPP
#define TABTEST_CPP

#include "allIncludes.h"

TEST(TabUnitTest, TabTestAssertionTrue) {

    Tab* tab = new Tab("Customer 1", 600);

    ASSERT_EQ(tab->getCustomerName(), "Customer 1");
    ASSERT_EQ(tab->getAmount(), 600);

    delete tab;
    tab = nullptr;
}

#endif