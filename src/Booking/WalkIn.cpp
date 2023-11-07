#include "WalkIn.h"

WalkIn::WalkIn(BookingSystem* bookignSystem) {
    this->bookingSystem = bookignSystem;
}

void WalkIn::addBooking(int numCustomers, istream& input) {
    cout << "Please enter your name: "; 

    string name; 
    input >> name;

    Booking* booking = new Booking(name, numCustomers, 0);
    bookingSystem->bookings.push_back(booking);
}