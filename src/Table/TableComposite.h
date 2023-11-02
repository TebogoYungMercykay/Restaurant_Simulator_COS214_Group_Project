#include "TableComponent.h"

#include "list"

using namespace std;

class TableComposite : public TableComponent {
private:
    list<TableComponent*> tables;

public:
    int getId();
    void setOccupied(bool status);
    bool getOccupied();
    void setCustomerSession(CustomerSession* session);
    CustomerSession* getCustomerSession();
    void setCustomerName(string name);
    void setWaiter(Waiter* waiter);
    Waiter* getWaiter();
    void setStaff(Staff* staff);
    void changeState(TableState* state);
    void serve();
    void add(TableComponent* table);
};