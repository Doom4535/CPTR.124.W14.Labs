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
    int y = 0;
    bool v = false;
    VendingMachine sample1(price, quantity);
    cout << "Vending Machine ready" << endl
        << "=======================" << endl;
    while (sample1.quantity() > 0) {
        int n = sample1.quantity();
        while (sample1.quantity() == n) {
            int value = sample1.vend();
            cout << "Prod Quant:  " << sample1.quantity() << " Total:  " << - value << " Please enter  " << - value << " cents:  ";
            int x;
            cin >> x;
            if (x < 0) {
                cout << "Transaction cancelled, change: " << sample1.price() + sample1.vend() << endl;
                sample1.reset();
                v = false;
                break;
            }
            sample1.input(x);
            value = sample1.vend();
            v = true;
        }
        if (v == true) {
            cout << "Vending... " << endl << "Change = " << sample1.price() + sample1.vend() << endl;
            v = false;
        }
    
    }
    cout << endl << "Total vending machine income: " << sample1.total() << endl;

    
}