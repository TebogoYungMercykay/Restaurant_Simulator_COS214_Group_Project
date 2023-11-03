#pragma once

#include <string>

using namespace std;

class Booking {
public:
    string customerName;
    int numCustomers;
    int timeLeft;

    Booking(string customerName, int numCustomers, int timeLeft);
    void progressTime();
};