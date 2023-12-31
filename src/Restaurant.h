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
        KitchenManager kitchen;
        WaiterManager waiterManager;
        BookingSystem reservations;
        CustomerIntake customerIntake;
        StaffCheckup staffCheckup;
        TabStore* tabs;
        double revenue;
        double tip;
        vector<string> complaints;
        int frame;
        
        Restaurant();
        ~Restaurant();

    public:
        static Restaurant& instance();
        TabStore* getTabStore();
        void addRevenue(double amount);
        void addTip(double amount);
        void addComplaint(string complaint);
        int getFrame();
        void nextFrame();
        void printStats();
        void progressFrame();

        friend WaiterManager;
};
#endif