#ifndef STAFFCHECKUP_H
#define STAFFCHECKUP_H

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

#include "Staff.h"
#include "Manager.h"
#include "../Table/TableComponent.h"
#include "../List/Iterator.h"

using namespace std;

class StaffCheckup {
    private:
        int frequency;
        bool checkingUp;
        int selectedStaff;
        std::vector<Staff*> staff;
        int currentIterator;
        std::vector<Iterator<TableComponent*>*> iterators;

    public:
        StaffCheckup(int freq, vector<Iterator<TableComponent*>*> iterators);
        void addStaff(Staff* s);
        void checkup();
        void progressCheckup();
        void skipTable(TableComponent* table);
};

#endif // STAFFCHECKUP_H