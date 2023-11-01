#include "TabStore.h"

TabStore :: TabStore(){
    numTabs = 0;
}

TabStore :: ~TabStore(){
    for (Tab* tab : tabs) {
        delete tab;
    }
    tabs.clear();
}

void TabStore :: addTab(Tab* newTab){
    tabs.push_back(newTab);
    numTabs++;
}

Tab* TabStore :: getTab(string customerName){
    // this function will look for the tab

    // if it is found, it will remove it from the vector then return it
    for(auto it = tabs.begin(); it != tabs.end(); ++it) {
        if ((*it)->getCustomerName() == customerName) {
            Tab* foundTab = *it;
            tabs.erase(it);
            numTabs--;
            return foundTab;
        }
    }
    return nullptr; // if tab not found, return nullptr
}

bool TabStore :: tabExists(string customerName){
    for(auto it = tabs.begin(); it != tabs.end(); ++it) {
        if ((*it)->getCustomerName() == customerName) {
            return true;
        }
    }
    return false; // if tab not found
}

int TabStore :: getNumTabs(){
    return numTabs;
}