#include "Booking.h"

Booking::Booking(string customerName, int numCustomers, int timeLeft) {
    this->customerName = customerName;
    this->numCustomers = numCustomers;
    this->timeLeft = timeLeft;
}

void Booking::progressTime() {
    timeLeft--;
}
