#include "Reserved.h"

Reserved::Reserved(BookingSystem* bookingSystem) {
    this->bookingSystem = bookingSystem;
}

void Reserved::addBooking(int numCustomers) {
    cout << "Please enter your name: "; 

    string name; 
    cin >> name;

    cout << "What time would you like to book for (hh:mm): ";

    string timeString;
    cin >> timeString;

    // TODO: Check for incorrect input
    int colonPosition = timeString.find_first_of(':');
    int hours = stoi(timeString.substr(0, colonPosition));
    int minutes = stoi(timeString.substr(colonPosition + 1));

    // Taking that each frame represents 5 minutes
    int timeInFrames = (hours * 12) + (minutes / 5);

    // 12 frames per hours * 24 hours in a day = 288 frames per day
    int timeLeft = timeInFrames - (Restaurant::instance().getFrame() % 288);

    Booking* booking = new Booking(name, numCustomers, timeLeft);
    bookingSystem->bookings.push_back(booking);
}