#pragma once

#include <stdlib.h>     
#include <time.h> 

using namespace std;

class CustomerIntake {
private:
    int frequency;

public:
    CustomerIntake(int frequency);
    int check(bool* isBooking);
};