#include "Restaurant.h"

Restaurant :: Restaurant() 
 :  waiterManager(5, &kitchen),
    tables(20),
    customerIntake(2),
    staffCheckup(1, waiterManager.getIterators()) {
    this->frame = 0;
    this->revenue = 0;
    this->tip = 0;
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

void Restaurant::printStats() {
    int hours = frame/12;
    int minutes = (frame - (hours * 12)) * 5;

    printf(
        "\nCurrent frame: %d\n"
        "Current time: %.2d:%.2d\n\n"

        "Number of tables remaining: %d/%d\n\n"

        "Total tips: %.2f\n"
        "Total Revenue: %.2f\n\n",

        frame, 
        hours, minutes, 

        tables.getNumRemaining(), tables.getNumTables(),

        tip,
        revenue
    );
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
        table->setCustomerName(booking->customerName);
        table->setNumCustomers(booking->numCustomers);
        waiterManager.assignTable(table);

        delete booking;
    }

    staffCheckup.progressCheckup();
    waiterManager.progressWaiters();

    cout << waiterManager.toString();
    cout << "\n\n";
    cout << kitchen.toString();

    waiterManager.serve();

    kitchen.progressKitchen();

    progressFrame();
}

void Restaurant::progressFrame() {
    frame++;
}

void Restaurant :: addTip(double amount){
    tip += amount;
}

void Restaurant :: addRevenue(double amount){
    revenue += amount;
}

void Restaurant :: addComplaint(string comp){
    complaints.push_back(comp);
}