#include "CustomerSession.h"

CustomerSession :: CustomerSession(){
    total = 0;
    // TODO: Check how we will initialize customer name, in TableComponent or here
}

void CustomerSession :: createOrder(map<string, int> orderDetails){

}

Order* CustomerSession :: getOrder(){
    return tableOrder;
}

void CustomerSession :: createTab(string name){
    
}

void CustomerSession :: prepareBill(){
    // prompt user whether they would like to split the bill
    // pay it normally, or create a tab

    string prompt = "You have 3 options on how to handle your bill.";
    string promptInstruction = "Enter the number corresponding to one of the following options, then press ENTER:";
    string promptOptions = "1. Pay the whole bill once. \n 2. Split the bill equally among the table. \n 3. Create a tab to pay at a later date.";
    promptInstruction += "\n 4. Add to my existing tab. \n 5. Pay my bill and my tab.";

    string errorMessage = "You have entered an invalid number. Please try again.";

    cout <<"Your bill total is R" + to_string(total) << endl;
    cout << prompt << endl;
    cout << promptInstruction << endl;
    cout << promptOptions << endl;

    int input;

    cin >> input;

    if(input == 1){
        // single bill option

    }else if(input == 2){
        // split bill option
        
    }else if(input == 3){
        // create tab option

        // ask the user to provide their name
        cout << "Could you please provide us with your first name below, then press ENTER:";
        string nameInput;

        cin >> nameInput;

        // check if this person trying to create a new tab doesn't already have one
        if(!tabExistence(nameInput)){
            createTab(nameInput);
        }else{
            string errorMessage2 = "You already have a tab opened. Please try again.";
            cout << errorMessage2 << endl;
            prepareBill();
        }
        

    }else if(input == 4){
        // add total to existing customer tab

    }else if(input == 6){
        // add existing tab total to current bill total and pay
    
    }else{
        // this is our error handling block
        cout << errorMessage << endl;
        // it will call the function again until the user enters a valid option
        prepareBill();
    }
}

void CustomerSession :: payBill(){
    //
}

bool CustomerSession :: tabExistence(string customerName){
    // TODO: check if custom
}

