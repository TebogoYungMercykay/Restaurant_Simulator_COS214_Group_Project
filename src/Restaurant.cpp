#include "Restaurant.h"

Restaurant :: Restaurant() 
 :  waiterManager(5, &kitchen),
    tables(20),
    customerIntake(10),
    staffCheckup(15, waiterManager.getIterators()) {
    this->frame = 0;
    this->tabs = new TabStore();
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

void Restaurant::nextFrame() {
    printStats();

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

        delete booking;
    }

    staffCheckup.checkup();
    waiterManager.serve();

    cout << waiterManager.toString();
    cout << "\n\n";
    cout << kitchen.toString();

    staffCheckup.progressCheckup();
    waiterManager.progressWaiters();
    progressFrame();
}

void Restaurant::progressFrame() {
    frame++;
}