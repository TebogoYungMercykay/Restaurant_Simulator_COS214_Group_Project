#include "CustomerSession.h"

CustomerSession :: CustomerSession(){
    this->customerName = "";
    this->tableBill = nullptr;
    this->tableOrderBuilder = nullptr;
}

CustomerSession :: ~CustomerSession(){

    if(tableBill != nullptr){
        delete tableBill;
        tableBill = nullptr;
    }
    
    if(tableOrderBuilder != nullptr){
        delete tableOrderBuilder;
        tableOrderBuilder = nullptr;
    }

}

void CustomerSession :: createOrder(map<string, int> orderDetails){
    OrderDirector tempDirector;
    if (this->tableOrderBuilder != nullptr) {
        delete tableOrderBuilder;
    }
    if (orderDetails.size() == 1 && orderDetails[0] == "HugeMac") {
        this->tableOrderBuilder = new HugeMacBuilder();
    } else if (orderDetails.size() == 1 && orderDetails[0] == "KotaPounder") {
        this->tableOrderBuilder = new KotaPounderBuilder();
    } else if (orderDetails.size() == 1 && orderDetails[0] == "WackCrispy") {
        this->tableOrderBuilder = new WackCrispyBuilder();
    } else if (orderDetails.size() == 1 && orderDetails[0] == "WackNuggets") {
        this->tableOrderBuilder = new WackNuggetsBuilder();
    } else {
        this->tableOrderBuilder = new HugeMacBuilder();
        tempDirector.setOrderBuilder(this->tableOrderBuilder);
        for (int k = 0; k < orderDetails.size(); k++) {
            tempDirector.addExtras(orderDetails[k]);
        }
        return;
    }
    tempDirector.setOrderBuilder(this->tableOrderBuilder);
    tempDirector.constructOrder();
}

Order* CustomerSession :: getOrder(){
    if(tableOrderBuilder != nullptr){
        return tableOrderBuilder->getOrder();
    }
    return nullptr;
}

void CustomerSession :: createTab(string name){
    Tab* newTab = new Tab(name, tableOrderBuilder->getOrder()->getCost());

    TabStore* ptr = Restaurant::instance().getTabStore();

    ptr->addTab(newTab);
}

void CustomerSession :: prepareBill(){
    // prompt user whether they would like to split the bill
    // pay it normally, create a tab, add to existing tab, or pay bill and tab total

    if(tableOrderBuilder->getOrder()->getCost() == 0){
        cout << "You have not ordered any food." << endl;
        return;
    }

    string prompt = "You have 3 options on how to handle your bill.";
    string promptInstruction = "Enter the number corresponding to one of the following options, then press ENTER:";
    string promptOptions = "1. Pay the whole bill once. \n 2. Split the bill equally among the table. \n 3. Create a tab to pay at a later date.";
    promptInstruction += "\n 4. Add to my existing tab. \n 5. Pay my bill and my tab.";

    string errorMessage = "You have entered an invalid number. Please try again.";

    cout <<"Your bill total is R" + to_string(tableOrderBuilder->getOrder()->getCost()) << endl;
    cout << prompt << endl;
    cout << promptInstruction << endl;
    cout << promptOptions << endl;

    int input;

    cin >> input;

    if(input == 1){
        // single bill option

        tableBill = new SingleBill(tableOrderBuilder->getOrder()->getCost());
        payBill(tableOrderBuilder->getOrder()->getCost());

    }else if(input == 2){
        // split bill option

        int numSplit;

        cout << "How many ways would you like to split the bill?" << endl;

        cin >> numSplit;

        double splitAmount = tableOrderBuilder->getOrder()->getCost() / numSplit;

        // create composite for split bill
        
        Bill* splitBill = new SplitBill();
        
        for(int i = 0; i < numSplit; i++){
            SingleBill* single = new SingleBill(splitAmount);
            splitBill->addBill(single);
        }
        

        tableBill = splitBill;
        payBill(tableOrderBuilder->getOrder()->getCost());

    }else if(input == 3){
        // create tab option

        // ask the user to provide their name
        cout << "Could you please provide us with your first name below, then press ENTER:";
        string nameInput;

        cin >> nameInput;

        // check if this person trying to create a new tab doesn't already have one
        if(!tabExistence(nameInput)){
            createTab(nameInput);

            cout << "Your tab has been successfully created. Please note that you have a maximum of R3000, you will then have to pay."<<endl;
            cout << "Payment Successful. Thank you for choosing WackDonalds, see you soon!" << endl;
            return;

        }else{
            string errorMessage2 = "You already have a tab opened. Please try again.";
            cout << errorMessage2 << endl;
            prepareBill();
        }

    }else if(input == 4){
        // add total to existing customer tab

        cout << "Could you please provide us with your first name below, then press ENTER:";
        string nameInput;

        cin >> nameInput;

        if(!tabExistence(nameInput)){
            string errorMessage3 = "You do not have a tab open with us. Please try again.";
            cout << errorMessage3 << endl;
            prepareBill();
        }else{
            // tab does exist for the customer
            
            // find tab
            TabStore* ptr = Restaurant::instance().getTabStore();
            Tab* currCustomerTab = ptr->getTab(nameInput);

            // if current tab total is exceeding 5000 ZAR, they will be asked to pay
            if(currCustomerTab->getAmount() >= 3000){
                cout << "Unfortunately you have reached the tab limit of over R3000.00. Please pay everything immediately";
                
                tableBill = new SingleBill(tableOrderBuilder->getOrder()->getCost() + currCustomerTab->getAmount());
                payBill(tableOrderBuilder->getOrder()->getCost() + currCustomerTab->getAmount());

                //delete the tab
                delete currCustomerTab;
                currCustomerTab = nullptr;
            }else{
                // add the current total to the tab total
                currCustomerTab->addAmount(tableOrderBuilder->getOrder()->getCost() + currCustomerTab->getAmount());

                // add the tab back to TabStore
                ptr->addTab(currCustomerTab);
            }
        }

    }else if(input == 5){
        // add existing tab total to current bill total and pay

        cout << "Could you please provide us with your first name below, then press ENTER:";
        string nameInput;

        cin >> nameInput;

        if(!tabExistence(nameInput)){
            string errorMessage3 = "You do not have a tab open with us. Please try again.";
            cout << errorMessage3 << endl;
            prepareBill();
        }else{
            // get the tab
            TabStore* ptr = Restaurant::instance().getTabStore();
            Tab* currCustomerTab = ptr->getTab(nameInput);
            // make customer pay tab total + current bill total

            tableBill = new SingleBill(tableOrderBuilder->getOrder()->getCost() + currCustomerTab->getAmount());
            payBill(tableOrderBuilder->getOrder()->getCost() + currCustomerTab->getAmount());

            //delete tab
            delete currCustomerTab;
            currCustomerTab = nullptr;
        }
    
    }else{
        // this is our error handling block
        cout << errorMessage << endl;

        // it will call the function again until the user enters a valid option
        prepareBill();
    }
}

void CustomerSession :: payBill(double billAmount){
    // this will handle the actual bill payment functionality

    // this line checks what kind of bill tableBill is
    if(SplitBill* split = dynamic_cast<SplitBill*>(tableBill)){
        
        // iterate through split bills and simulate payment
        int i = 1;

        for(Bill* ptr : split->getBills()){
            double amount = ptr->getAmount();

            cout << "Payment number" + to_string(i) + "of the amount R" + to_string(amount) + " Successful"<<endl;
            i++;
        }
    }else{
        // this will process a single bill

        cout << "Customer is currently paying this single bill of R" + to_string(billAmount) + "..." <<endl;

        cout << "Payment Successful. Thank you for choosing WackDonalds, see you soon!" << endl;

    }
}

bool CustomerSession :: tabExistence(string customerName){
    // check if customer tab exists
    TabStore* ptr = Restaurant::instance().getTabStore();
    return ptr->tabExists(customerName);
}