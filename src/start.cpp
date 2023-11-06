#include <iostream>
#include "Restaurant.h"

using namespace std;

int main() {
    srand(42);
    char input = '\0';

    while (input != 'q') {
        Restaurant::instance().nextFrame();
        
        cout << "\n\n(Press Enter for next or q to quit) ";
        cout << "\n------------------------------------- ";
        
        input = getc(stdin);
    }
}
