#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "TabStore.h"

#include <iostream>
#include <string>

using namespace std;

class Restaurant{
    private:
        TabStore* tabs;
        
        Restaurant();
        ~Restaurant();

    public:
        Restaurant& instance();
        TabStore* getTabStore();
};
#endif