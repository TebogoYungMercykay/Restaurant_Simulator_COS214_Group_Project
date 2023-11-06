#ifndef TABSTORE_CPP
#define TABSTORE_CPP

#include "allIncludes.h"

TEST(TabStore, TabStoreTestAssertionTrue) {
    TabStore* tabStorage = new TabStore();

    Tab* tab1 = new Tab("Customer 1", 600);
    Tab* tab2 = new Tab("Customer 2", 800);
    Tab* tab3 = new Tab("Customer 3", 300);
    Tab* tab4 = new Tab("Customer 4", 2500);
    Tab* tab5 = new Tab("Customer 5", 6000);

    tabStorage->addTab(tab1);
    tabStorage->addTab(tab2);
    tabStorage->addTab(tab3);
    tabStorage->addTab(tab4);
    tabStorage->addTab(tab5);

    ASSERT_EQ(tabStorage->getNumTabs(), 5);
    ASSERT_EQ(tabStorage->getTab("Customer 1")->getCustomerName(), "Customer 1");
    ASSERT_EQ(tabStorage->getTab("Customer 10"), nullptr);
    ASSERT_EQ(tabStorage->tabExists("Customer 1"), false);
    ASSERT_EQ(tabStorage->tabExists("Customer 2"), true);
    ASSERT_EQ(tabStorage->getNumTabs(), 4);
}

#endif