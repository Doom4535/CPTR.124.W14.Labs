//
// Client code
// client.cpp
//
//  Vending Machine Object
//
//  Created by Aaron Covrig on 4/16/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>
#include "vend.h"

using namespace std;

int main() {
    cout << "What is the price of the product? ";
    int price, quantity;
    cin >> price;
    cout << endl << "How much product is there? ";
    cin >> quantity;
    cout << endl;
    int value = 0; // used to keep track of customer input
    VendingMachine sample1(price, quantity);
    cout << "Vending Machine ready, a negative entry resets the machine" << endl
        << "=======================" << endl;
    //insert code here (deleted because it needs to be redone
    while (sample1.quantity() > 0) {
        cout << "[Product quantity: " << sample1.quantity() << " Total: " << value << "  ] " << " Please enter  " << - sample1.vend() << " cents: ";
        int user_input = 0;
        int data = 0;
        cin >> user_input;
        if (user_input < 0) { //resets the machine if the user inputs a negative value (cancells the purchase)
            cout << "Transaction cancelled, change: " << sample1.price() + sample1.vend() << endl;
            data = 0;
            value = 0;
            sample1.reset();
        }
        else if (user_input >= 0 && sample1.input(user_input) != false) { // Determine if the user input is acceptable and usable
            value = value + user_input;
            data = sample1.vend();
            if (data == 0) {  // Vends the product (triggered when the customer pays with exact change)
                data = 0;
                cout << "Eject product, change = 0" << endl
                     << "----------------------------" << endl;
                value = 0;
                sample1.vend();
            }
            else if (data > 0) {  // Vends the product and dispenses the change (triggered when there is change)
                cout << "Eject product, change = " << data << endl
                     << "----------------------------" << endl;
                value = 0;
                sample1.vend();
            }
            
        }
    }
    
    cout << endl << "Total vending machine income: " << sample1.total() << endl
         << "Thank you for using My Vending Solutions LLC." << endl
         << "If you are interested in purchasing additional products, you can visit our offices on Mainstreet." << endl
         << "Should you want to file a complaint, please contact Brigs Vending Company on Mainstreet." << endl;
    
}
