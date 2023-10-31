#ifndef STAFFCHECKUP_H
#define STAFFCHECKUP_H

#include "TemporaryTableClass.h" // TODO: Will Remove
// TODO: Temporary Implementation - Incomplete Class

#include "Staff.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

class StaffCheckup {
    private:
        int frame;
        int frequency;
        bool checkingUp;
        int selectedStaff;
        std::vector<Staff*> staff;
        std::vector<TemporaryTableClass*> tables;
        std::vector<TemporaryTableClass*>::iterator it;
    public:
        StaffCheckup();
        StaffCheckup(int freq);
        ~StaffCheckup();
        void addStaff(Staff* s);
        void addTable(TemporaryTableClass* t);
        void progressCheckup();
};

#endif // STAFFCHECKUP_H