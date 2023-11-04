#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "List/TableCollection.h"
#include "Staff/WaiterManager.h"
#include "Booking/BookingSystem.h"
#include "Booking/CustomerIntake.h"
#include "Staff/StaffCheckup.h"
#include "Tab/TabStore.h"
#include "Booking/Reserved.h"
#include "Booking/WalkIn.h"

#include <iostream>
#include <string>

using namespace std;

class Restaurant{
    private:
        TableCollection tables;
        WaiterManager waiterManager;
        BookingSystem reservations;
        CustomerIntake customerIntake;
        StaffCheckup staffCheckup;
        KitchenManager kitchen;
        TabStore* tabs;
        int frame;
        
        Restaurant();
        ~Restaurant();

    public:
        static Restaurant& instance();
        TabStore* getTabStore();
        int getFrame();
        void nextFrame();
        void printStats();
};
#endif