#include <gtest/gtest.h>
#include "../src/List/List.h"
#include "../src/List/Iterator.h"

class ListAndIteratorTest : public testing::Test {
protected:
    List<int> emptyInitially; 
    List<int> threeItemsInitially;
    Iterator<int>* emptyInitiallyIterator; 
    Iterator<int>* threeItemsInitiallyIterator;

    ListAndIteratorTest() {
        threeItemsInitially.add(1);
        threeItemsInitially.add(2);
        threeItemsInitially.add(3);

        emptyInitiallyIterator = emptyInitially.getIterator();
        threeItemsInitiallyIterator = threeItemsInitially.getIterator();
    }

    ~ListAndIteratorTest() {
        delete emptyInitiallyIterator;
        delete threeItemsInitiallyIterator;
    }
};

TEST_F(ListAndIteratorTest, CanIterate) {
    ASSERT_EQ(threeItemsInitiallyIterator->isDone(), false);

    for (int i = 1; i <= 3; i++) {
        EXPECT_EQ(threeItemsInitiallyIterator->getCurrent(), i);
        threeItemsInitiallyIterator->next();
    }

    EXPECT_EQ(threeItemsInitiallyIterator->isDone(), true);
}

TEST_F(ListAndIteratorTest, StartsEmpty) {
    EXPECT_EQ(emptyInitiallyIterator->isDone(), true);
}

TEST_F(ListAndIteratorTest, CanAdd) {
    emptyInitially.add(5);
    emptyInitiallyIterator->reset();
    EXPECT_EQ(emptyInitiallyIterator->getCurrent(), 5);

    threeItemsInitially.add(5);
    threeItemsInitiallyIterator->reset();
    for (int i = 0; i < 3; i++) {
        threeItemsInitiallyIterator->next();
    }
    EXPECT_EQ(threeItemsInitiallyIterator->getCurrent(), 5);
}

TEST_F(ListAndIteratorTest, CanRemove) {
    threeItemsInitially.remove(1);
    threeItemsInitiallyIterator->reset();
    EXPECT_EQ(threeItemsInitiallyIterator->getCurrent(), 2);

    threeItemsInitially.remove(3);
    threeItemsInitiallyIterator->reset();
    EXPECT_EQ(threeItemsInitiallyIterator->getCurrent(), 2);

    threeItemsInitially.remove(2);
    threeItemsInitiallyIterator->reset();
    EXPECT_EQ(threeItemsInitiallyIterator->isDone(), true);
}

