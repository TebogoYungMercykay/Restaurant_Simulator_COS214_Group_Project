#include "StaffCheckup.h"

StaffCheckup::StaffCheckup(int freq, vector<Iterator<TableComponent*>*> iterators) {
    this->frequency = freq;
    this->checkingUp = false;
    this->selectedStaff = -1;
    this->currentIterator = 0;
    this->iterators = iterators;

    staff.push_back(new Manager());
}

void StaffCheckup::addStaff(Staff* s) {
    this->staff.push_back(s);
}

void StaffCheckup::checkup() {
    if (checkingUp) {
        iterators[currentIterator]->getCurrent()->setStaff(
            staff[selectedStaff]
        );
    }
}

void StaffCheckup::progressCheckup() {
    if (checkingUp) {
        while (
            currentIterator < iterators.size() &&
            iterators[currentIterator]->isDone()) {
            currentIterator++;
        }

        if (currentIterator < iterators.size()) {
            iterators[currentIterator]->getCurrent()->setStaff(nullptr);
            iterators[currentIterator]->next();
        } else {
            checkingUp = false;
        }
    } else {
        if (Restaurant::instance().getFrame() % frequency == 0) {
            checkingUp = true;
            selectedStaff = rand() % staff.size();
            currentIterator = 0;
            for (Iterator<TableComponent*>* iterator : iterators) {
                iterator->reset();
            }
        }
    }
}