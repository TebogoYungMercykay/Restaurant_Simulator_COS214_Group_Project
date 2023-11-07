#include <gtest/gtest.h>
#include <fstream>
#include "../src/Booking/WalkIn.h"
#include "../src/Booking/Reserved.h"
#include "../src/Booking/CustomerIntake.h"
#include "../src/Booking/BookingSystem.h"
#include "../src/Restaurant.h"

class BookingTest : public testing::Test {
protected:
    CustomerIntake customerIntake;
    BookingSystem bookingSystem;
    Reserved reserved;
    WalkIn walkIn;

    BookingTest() : 
        walkIn(&bookingSystem), 
        reserved(&bookingSystem),
        customerIntake(5) {}
};

TEST_F(BookingTest, CanWalkIn) {
    fstream file;
    file.open("walkInPrompt.txt", ios::in);

    walkIn.addBooking(2, file);
    Booking* booking = bookingSystem.checkBookings();
    ASSERT_NE(booking, nullptr);
    EXPECT_EQ(booking->customerName, "Doof");
    EXPECT_EQ(booking->numCustomers, 2);

    file.close();
    delete booking;
}

TEST_F(BookingTest, CanRerseve) {
    fstream file;
    file.open("reservePrompt.txt", ios::in);

    reserved.addBooking(5, file);
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(bookingSystem.checkBookings(), nullptr);
    }
    Booking* booking = bookingSystem.checkBookings();
    ASSERT_NE(booking, nullptr);

    EXPECT_EQ(booking->customerName, "Chronos");
    EXPECT_EQ(booking->numCustomers, 5);

    file.close();
    delete booking;
}

TEST_F(BookingTest, CustomerIntakeWorks) {
    bool isBooking;

    for (int i = 0; i < 4; i++) {
        Restaurant::instance().progressFrame();
        EXPECT_EQ(customerIntake.check(&isBooking), 0);
    }

    Restaurant::instance().progressFrame();
    EXPECT_GT(customerIntake.check(&isBooking), 0);
}

