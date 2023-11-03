#include "CustomerIntake.h"

CustomerIntake::CustomerIntake(int frequency) {
    this->frequency = (frequency);
    srand(time(nullptr));
}

int CustomerIntake::check(bool* isBooking) {
    if (Restaurant::instance().getFrame() % frequency == 0) {
        *isBooking = rand() % 2;
        return rand() % 10 + 1;
    }

    return 0;
}