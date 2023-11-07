#ifndef STAFFCHECKUPTESTS_CPP
#define STAFFCHECKUPTESTS_CPP

#include "allIncludes.h"

TEST(StaffCheckupUnitTest, StaffCheckupTestAssertionTrue) {
    // Creating StaffCheckup object
    StaffCheckup* checkup = new StaffCheckup(4, 5);

    // Adding some staff members
    for (int i = 0; i < 5; ++i) {
        Staff* staff = new Staff();
        staff->setName("Staff " + std::to_string(i + 1));
        checkup->addStaff(staff);
    }

    // Adding some tables
    for (int i = 0; i < 7; ++i) {
        TemporaryTableClass* table = new TemporaryTableClass(i + 1);
        checkup->addTable(table);
    }

    // Performing checkup
    checkup->progressCheckup();
    delete checkup;
    checkup = nullptr;
    std::cout << std::endl;
}

#endif