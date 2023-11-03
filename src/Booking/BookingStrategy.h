#pragma once

class BookingSystem;

class BookingStrategy {
protected:
    BookingSystem* bookingSystem;

public:
    virtual ~BookingStrategy() {};
    virtual void addBooking(int numCustomers) = 0;
};