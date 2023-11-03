#pragma once

#include <list>

#include "Booking.h"
#include "BookingStrategy.h"

class WalkIn;
class Reserved;

using namespace std;

class BookingSystem {
private:
    list<Booking*> bookings;
    BookingStrategy* bookingStrategy;

public:
    BookingSystem();
    ~BookingSystem();
    void addBooking(int numCustomers);
    void setBookingStrategy(BookingStrategy* strategy);
    Booking* checkBookings();

    friend WalkIn;
    friend Reserved;
};