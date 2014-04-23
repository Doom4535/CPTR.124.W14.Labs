// Client code
// client.cpp

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
    int change = 0;
    bool v = false;
    VendingMachine sample1(price, quantity);
    cout << "Vending Machine ready" << endl
        << "=======================" << endl;
    while (sample1.quantity() > 0) {
        int n = sample1.quantity();
        while (sample1.quantity() == n) {
            int value = sample1.vend();
            if (value < 0 )) {
                cout << "Prod Quant:  " << sample1.quantity() << " Total:  " << sample1.price() << " Please enter  " << - value << " cents:  ";
                int x;
                cin >> x;
                change = value;
            
            if (x < 0) {
                cout << "Transaction cancelled, change: " << change << endl;
                sample1.reset();
                v = false;
                break;
            }
            sample1.input(x);
            int y = sample1.vend();
            v = true;
            change = value + sample1.price();
                    }
        cout << "*******************" << endl;
                if (v == true) {
            cout << "Vending... " << endl << "Change = " << change - sample1.price() << endl;
            v = false;
            cout << "-----------------" << endl;
            // cout << sample1.reset();
        }
    
    }
    cout << endl << "Total vending machine income: " << sample1.total() << endl;

    
}
