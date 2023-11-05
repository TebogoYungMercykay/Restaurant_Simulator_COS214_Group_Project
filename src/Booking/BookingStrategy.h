#pragma once

#include <iostream>

using namespace std;

class BookingSystem;

class BookingStrategy {
protected:
    BookingSystem* bookingSystem;

public:
    virtual ~BookingStrategy() {};
    virtual void addBooking(int numCustomers, istream& input = cin) = 0;
};