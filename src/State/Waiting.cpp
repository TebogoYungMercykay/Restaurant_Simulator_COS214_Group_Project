#include "Waiting.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void Waiting :: setTableComponent(TableComponent* table) {
    this->table = table;
}

void Waiting :: serve() {
    srand(time(0));
    // Random number between 23 and 150
    int random_number = rand() % (128) + 23;
    std::cout << "Your order number is #" << random_number << ". You can use this number to track the status of your order." << std::endl;
    this->table->changeState(new Paying());
}