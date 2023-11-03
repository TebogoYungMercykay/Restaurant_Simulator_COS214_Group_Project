#pragma once

#include <iostream>

#include "BookingStrategy.h"
#include "BookingSystem.h"
#include "../Restaurant.h"

using namespace std;

class Reserved : public BookingStrategy {
public:
    Reserved(BookingSystem* bookingSystem);
    void addBooking(int numCustomers);
};