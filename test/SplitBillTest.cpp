#ifndef SPLITBILLTEST_CPP
#define SPLITBILLTEST_CPP

#include "allIncludes.h"

TEST(SplitBillUnitTest, SplitBillTestAssertionTrue) {
    SplitBill* splitBill = new SplitBill();

    SingleBill* s1 = new SingleBill(200);
    ASSERT_EQ(s1->getAmount(), 200);
    SingleBill* s2 = new SingleBill(200);
    ASSERT_EQ(s2->getAmount(), 200);

    SingleBill* s3 = new SingleBill(200);
    ASSERT_EQ(s3->getAmount(), 200);

    SingleBill* s4 = new SingleBill(200);
    ASSERT_EQ(s4->getAmount(), 200);

    splitBill->addBill(s1);
    splitBill->addBill(s2);
    splitBill->addBill(s3);
    splitBill->addBill(s4);

    ASSERT_EQ(splitBill->getAmount(),800);

    delete splitBill;
    splitBill = nullptr;
}

#endif