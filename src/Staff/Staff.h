#ifndef STAFF_H
#define STAFF_H

#include <string>

using namespace std;

class Staff {
    private:
        string name;
    public:
        Staff();
        string getName();
        void setName(string name);
};

#endif // STAFF_H