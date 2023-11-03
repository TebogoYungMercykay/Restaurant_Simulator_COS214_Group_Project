#include "BookingSystem.h"

BookingSystem::BookingSystem() {
    this->bookingStrategy = nullptr;
}

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
    Booking* booking = nullptr;
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