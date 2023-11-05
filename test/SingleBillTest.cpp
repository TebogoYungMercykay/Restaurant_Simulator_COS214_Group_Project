#ifndef SINGLEBILLTEST_CPP
#define SINGLEBILLTEST_CPP

#include "allIncludes.h"

TEST(SingleBillUnitTest, SingleBillTestAssertionTrue) {
    SingleBill singleBill(600);
    ASSERT_EQ(singleBill.getAmount(), 600);
}

#endif