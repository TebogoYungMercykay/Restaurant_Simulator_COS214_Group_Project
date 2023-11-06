#include "WalkIn.h"

WalkIn::WalkIn(BookingSystem* bookignSystem) {
    this->bookingSystem = bookignSystem;
}

void WalkIn::addBooking(int numCustomers, istream& input) {
    cout << "\nA customer has walked in and would like a table" << endl; 

    cout << "\nPlease enter your name: "; 

    string name; 
    input >> name;

    Booking* booking = new Booking(name, numCustomers, 0);
    bookingSystem->bookings.push_back(booking);
}