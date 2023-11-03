#include "CustomerIntake.h"

CustomerIntake::CustomerIntake(int frequency) : frequency(frequency) {
    srand(time(NULL));
}

int CustomerIntake::check(bool* isBooking) {
    if (Restaurant::instance().getFrame() % frequency == 0) {
        *isBooking = rand() % 2;
        return rand() % 10 + 1;
    }

    return 0;
}