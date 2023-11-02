#include "Staff.h"

Staff::Staff() {
    this->name = "Staff Member";
}

string Staff::getName() {
    return this->name;
}

void Staff::setName(string newName) {
    this->name = newName;
}
