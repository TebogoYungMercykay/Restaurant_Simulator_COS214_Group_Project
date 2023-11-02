#include "KitchenStation.h"

KitchenStation::KitchenStation() {
    this->nextStation = nullptr;
    this->setName("Kitchen Station");
}

void KitchenStation::setNext(KitchenStation* next) {
    this->nextStation = next;
}
