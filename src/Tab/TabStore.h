#ifndef TABSTORE_H
#define TABSTORE_H

#include "Tab.h"

#include <vector>
#include <string>

class TabStore{
    private:
        vector<Tab*> tabs;
        int numTabs;

    public:
        TabStore();
        ~TabStore();
        void addTab(Tab* newTab);
        Tab* getTab(string customerName); // will remove the tab from the vector and return it
        bool tabExists(string customerName);
        int getNumTabs();
};
#endif