#include "StaffCheckup.h"
#include "../Restaurant.h"
#include "../State/TableState.h"

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

void StaffCheckup::checkup() {}

void StaffCheckup::progressCheckup() {
    if (checkingUp) {
        iterators[currentIterator]->getCurrent()->setStaff(nullptr);
        iterators[currentIterator]->next();

        while (
            currentIterator < iterators.size() &&
            iterators[currentIterator]->isDone()) {
            currentIterator++;

            if (currentIterator < iterators.size()) {
                iterators[currentIterator]->reset();
            }
        }

        if (currentIterator >= iterators.size()) {
            checkingUp = false;
        }
    } else {
        int frame = Restaurant::instance().getFrame();
        if (frame > 1 && frame % frequency == 0) {
            checkingUp = true;
            selectedStaff = rand() % staff.size();
            currentIterator = 0;
            for (Iterator<TableComponent*>* iterator : iterators) {
                iterator->reset();
            }

            while (
                currentIterator < iterators.size() &&
                iterators[currentIterator]->isDone()) {
                currentIterator++;
            }

            if (currentIterator >= iterators.size()) {
                checkingUp = false;
            }
        }
    }

    if (checkingUp) {
        iterators[currentIterator]->getCurrent()->setStaff(
            staff[selectedStaff]
        );
    }
}

void StaffCheckup::skipTable(TableComponent* table) {
    if (checkingUp && iterators[currentIterator]->getCurrent() == table) {
        progressCheckup();
    }
}