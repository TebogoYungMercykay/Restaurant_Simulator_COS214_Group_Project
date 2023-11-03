#include "Booking.h"

Booking::Booking(
    string customerName, 
    int numCustomers, 
    int timeLeft
) : customerName(customerName),
    numCustomers(numCustomers),
    timeLeft(timeLeft) {}

void Booking::progressTime() {
    timeLeft--;
}
