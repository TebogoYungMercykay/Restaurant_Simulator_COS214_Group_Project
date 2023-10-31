#include "StaffCheckup.h"

// TODO: Temporary Implementation - Incomplete Class

StaffCheckup::StaffCheckup() {
    std::srand(std::time(0));
    this->frequency = 10;
    this->checkingUp = false;
    this->selectedStaff = 0;
    this->frame = 0;
}

StaffCheckup::StaffCheckup(int freq, int frame) {
    std::srand(std::time(0));
    this->frequency = freq;
    this->checkingUp = false;
    this->selectedStaff = 0;
    this->frame = frame;
}

StaffCheckup::~StaffCheckup() {
    for (auto s : this->staff) delete s;
    for (auto t : this->tables) delete t;
}

void StaffCheckup::addStaff(Staff* s) {
    this->staff.push_back(s);
}

void StaffCheckup::addTable(TemporaryTableClass* t) {
    this->tables.push_back(t);
}

void StaffCheckup::progressCheckup() {
    if (staff.size() != 0) {
        int counter = 0;
        this->selectedStaff = std::rand() % staff.size();
        this->checkingUp = true;
        if (this->tables.size() != 0) {
            for (int k = 0; k < this->frequency; k++) {
                std::cout << this->staff[this->selectedStaff]->getName() << " Checking Table " << this->tables[this->frame]->getId() << std::endl;
                this->frame = (this->frame + 1) % this->tables.size();
            }
        }
    }
}