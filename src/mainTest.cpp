#include "CustomerSession.h"
#include "SingleBill.h"
#include "SplitBill.h"
#include "Tab.h"
#include "TabStore.h"

#include <iostream>
#include <cassert>

void testSingleBill();
void testSplitBill();
void testTab();
void testTabStore();
void testCustomerSession();

using namespace std;

int main(){
    testSingleBill();
    testSplitBill();
    testTab();
    testTabStore();
    testCustomerSession();
    return 0;
}

void testSingleBill(){
    cout << "-------- TESTING SINGLE BILL CLASS -----------" << endl;
    SingleBill singleBill(600);
    assert(singleBill.getAmount());
    cout << "SINGLE BILL TESTS PASSED"<<endl;
}

void testSplittBill(){
    cout << "-------- TESTING SPLIT BILL CLASS -----------" << endl;

    SplitBill* splitBill = new SplitBill();

    SingleBill* s1 = new SingleBill(200);
    SingleBill* s2 = new SingleBill(200);
    SingleBill* s3 = new SingleBill(200);
    SingleBill* s4 = new SingleBill(200);

    splitBill->addBill(s1);
    splitBill->addBill(s2);
    splitBill->addBill(s3);
    splitBill->addBill(s4);

    assert(splitBill->getAmount() ==800);

    delete splitBill;
    splitBill = nullptr;

    cout << "SPLIT BILL TESTS PASSED"<<endl;

}

void testTab(){
    cout << "-------- TESTING TAB CLASS -----------" << endl;

    Tab* tab = new Tab("Customer 1", 600);

    assert(tab->getCustomerName() == "Customer 1");
    assert(tab->getAmount() == 600);

    delete tab;
    tab = nullptr;

    cout << "TAB TESTS PASSED"<<endl;
}

void testTabStore(){
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

    assert(tabStorage->getNumTabs() == 5);
    assert(tabStorage->getTab("Customer 1")->getCustomerName() == "Customer 1");
    assert(tabStorage->getTab("Customer 10") == nullptr);
    assert(tabStorage->tabExists("Customer 1") == false);
    assert(tabStorage->tabExists("Customer 2") == true);
    assert(tabStorage->getNumTabs() == 4);

    cout << "TAB STORE TESTS PASSED" << endl;
}

void testCustomerSession(){
}