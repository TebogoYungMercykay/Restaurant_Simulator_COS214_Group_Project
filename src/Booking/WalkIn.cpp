#include "WalkIn.h"

WalkIn::WalkIn(BookingSystem* bookignSystem) {
    this->bookingSystem = bookignSystem;
}

void WalkIn::addBooking(int numCustomers) {
    cout << "Please enter your name: "; 

    string name; 
    cin >> name;

    Booking* booking = new Booking(name, numCustomers, 0);
    bookingSystem->bookings.push_back(booking);
}