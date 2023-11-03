#include "Restaurant.h"

Restaurant :: Restaurant() 
 :  waiterManager(5, &kitchen),
    tables(20),
    customerIntake(10) {
    frame = 0;
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

int Restaurant :: getFrame() {
    return frame;
}

int Restaurant::getFrame() {
    bool isBooking;
    int numCustomers;

    if (numCustomers = customerIntake.check(&isBooking)) {
        if (tables.useTables(numCustomers)) {
            if (isBooking) {
                reservations.setBookingStrategy(new Reserved(&reservations));
            } else {
                reservations.setBookingStrategy(new WalkIn(&reservations));
            }

            reservations.addBooking(numCustomers);
        }
    }

    Booking* booking = NULL;
    if (booking = reservations.checkBookings()) {
        TableComponent* table = tables.getTables(booking->numCustomers);
        waiterManager.assignTable(table);
    }

    waiterManager.serve();
    staffCheckup.checkup();

    cout << tables.toString();
    cout << kitchen.toString();

    waiterManager.progressWaiters();
    staffCheckup.progressCheckup();
    frame++;
}