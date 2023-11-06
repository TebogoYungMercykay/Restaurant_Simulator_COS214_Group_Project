#include "CustomerIntake.h"

#include "../Restaurant.h"

CustomerIntake::CustomerIntake(int frequency) {
    this->frequency = (frequency);
}

int CustomerIntake::check(bool* isBooking) {
    int frame = Restaurant::instance().getFrame();
    if (frame > 1 && frame % frequency == 0) {
        *isBooking = rand() % 2;
        return rand() % 10 + 1;
    }

    return 0;
}