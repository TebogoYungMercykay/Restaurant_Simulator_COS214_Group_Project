#pragma once

#include <iostream>

#include "BookingStrategy.h"
#include "BookingSystem.h"

using namespace std;

class WalkIn : public BookingStrategy {
public:
    WalkIn(BookingSystem* bookignSystem);
    void addBooking(int numCustomers);
};