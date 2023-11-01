#include "Restaurant.h"

Restaurant :: Restaurant(){
    tabs = new TabStore();
}

Restaurant :: ~Restaurant(){
    delete tabs;
}

Restaurant& Restaurant :: instance(){
    static Restaurant onlyInstance_;
    return onlyInstance_;
}

TabStore* Restaurant :: getTabStore(){
    return tabs;
}