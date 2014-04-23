//
//  main.cpp
//  Vending Machine Object
//
//  Created by Aaron Covrig on 4/16/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "vend.h"
// #include "operations.cpp"

using namespace std;

/* 
    class point {
    double x = 1;
    double y;
};

random() {
    point p1;
    cout << p1.x;
    
    
}

int vend_initilyzer() {
    VendingMachine supply1;
    int product_price;
    int product_quantity;
    int transaction_total;
    int machine_total;
    
public:
    VendingMachine(price, amount)
    
}
 */

/*
VendingMachine(price, amount) {
    supply1.product_price = price;
    supply1.product_quantity = amount;
};
*/

VendingMachine::VendingMachine(int price, int quantity) {
    
    product_price = price;
    product_quantity = quantity;
    transaction_total = 0;
    machine_total = 0;
}
bool VendingMachine::input(int amount) {
    switch (amount) {
        case 5:
            transaction_total = transaction_total + amount;
            return true;
            break;
        case 10:
            transaction_total = transaction_total + amount;
            return true;
        case 25:
            transaction_total = transaction_total + amount;
            return true;
        default:
            return false;
            break;
    }
    
   /* if (amount == (5 or 10 or 25)) {
        transaction_total = transaction_total + amount;
        return true;
    }
    else
        return false;
*/
}
    
int VendingMachine::vend() {
    int x;
    if (transaction_total == product_price) {
        reset();
        product_quantity--;
        machine_total = product_price + machine_total;
        x = 0;
        
    }
    else if (transaction_total < product_price) {
        x = transaction_total -  product_price; // return the amount of change needed to purchase the product
    }
    else if (transaction_total > product_price) {
        reset();
        product_quantity--;
        machine_total = transaction_total + product_price;
        x = transaction_total - product_price;
        
    }
    return x;
}

int VendingMachine::reset() {
    int x = transaction_total;
    transaction_total = 0;
    return x;
}
int VendingMachine::price() const {
    return product_price;
}

int VendingMachine::quantity() const {
    return product_quantity;
}

int VendingMachine::total() const {
    return machine_total;
}

/*
int main()
{
    VendingMachine sample1(product_price, product_quantity);
}
 */


