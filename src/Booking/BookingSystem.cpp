#include "BookingSystem.h"

BookingSystem::BookingSystem() : bookingStrategy(NULL) {}

BookingSystem::~BookingSystem() {
    if (bookingStrategy) {
        delete bookingStrategy;
    }
}

void BookingSystem::addBooking(int numCustomers) {
    bookingStrategy->addBooking(numCustomers);
}

void BookingSystem::setBookingStrategy(BookingStrategy* strategy) {
    if (bookingStrategy) {
        delete bookingStrategy;
    }

    bookingStrategy = strategy;
}

Booking* BookingSystem::checkBookings() {
    Booking* booking = NULL;
    list<Booking*>::iterator bookingPosition;

    for (auto it = bookings.begin(); it != bookings.end(); it++) {
        (*it)->progressTime();

        if ((*it)->timeLeft <= 0) {
            bookingPosition = it;
            booking = *it;
        }
    }

    if (booking) {
        bookings.erase(bookingPosition);
    }

    return booking;
}