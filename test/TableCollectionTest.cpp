#include <gtest/gtest.h>
#include "../src/List/TableCollection.h"

TEST(TableCollectionTest, UseTableWorks) {
    TableCollection tables(20);

    tables.useTables(10);
    EXPECT_EQ(tables.getNumRemaining(), 15);

    tables.useTables(9);
    EXPECT_EQ(tables.getNumRemaining(), 10);

    tables.useTables(2);
    EXPECT_EQ(tables.getNumRemaining(), 9);

    tables.useTables(1);
    EXPECT_EQ(tables.getNumRemaining(), 8);
}

TEST(TableCollectionTest, GetTablesWorks) {
    TableCollection tables(20);
    Iterator<TableComponent*>* tablesIterator = tables.getIterator();

    TableComponent* tableForOne = tables.getTables(1);
    ASSERT_NE(tableForOne, nullptr);
    EXPECT_EQ(tablesIterator->getCurrent()->getOccupied(), true);

    tablesIterator->next();
    EXPECT_EQ(tablesIterator->getCurrent()->getOccupied(), false);

    TableComponent* tableForFour = tables.getTables(4);
    ASSERT_NE(tableForFour, nullptr);
    EXPECT_EQ(tablesIterator->getCurrent()->getOccupied(), true);
    tablesIterator->next();
    EXPECT_EQ(tablesIterator->getCurrent()->getOccupied(), true);

    tablesIterator->next();
    EXPECT_EQ(tablesIterator->getCurrent()->getOccupied(), false);

    tableForOne->vacate();
    delete tableForOne;
    tableForFour->vacate();
    delete tableForFour;
    delete tablesIterator;
}
