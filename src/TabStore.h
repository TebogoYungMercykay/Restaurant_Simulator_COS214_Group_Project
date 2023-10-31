#ifndef TABSTORE_H
#define TABSTORE_H
#include "Tab.h"

#include <vector>
#include <string>

class TabStore{
    private:
        vector<Tab*> tabs;

    public:
        void addTab(Tab* newTab);
        Tab* checkTab(string customerName);
};
#endif