//
//  main.cpp
//  Pizza.calculator
//
//  Created by Aaron Covrig on 1/21/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float pizza1_p, pizza2_p; // price of pizzas
    float pizza1_d, pizza2_d; // diameter of pizzas
    float pizza1_ppi, pizza2_ppi; // price per square inch of pizzas
    const float PI = 3.14159;
    cout << "Please enter the price of the first pizza: ";
    cin >> pizza1_p;
    cout << "Please enter the diameter of the first pizza: ";
    cin >> pizza1_d;
    cout << "Please enter the price of the second pizza: ";
    cin >> pizza2_p;
    cout << "Please enter the diameter of the second pizza: ";
    cin >> pizza2_d;
    cout << endl;
    // Computing the price per square inch of the two pizzas (assuming same thickness, ect.)
    pizza1_ppi = (pizza1_p * 100) / (PI * pow((pizza1_d / 2), 2));
    pizza2_ppi = (pizza2_p * 100) / (PI * pow((pizza2_d / 2), 2));
    
    cout << "The price per inch for the first pizza in cents is: " << pizza1_ppi << endl;
    cout << "The price per inch for the second pizza in cents is: " << pizza2_ppi << endl;

    cout << "-------------------------------------------------------------------";
    
    if (pizza1_ppi < pizza2_ppi) {
        cout << "The first pizza is a better deal." << endl;
        cout << "It is " << pizza2_ppi / pizza1_ppi<< " times cheaper." << endl;
    }
    else if (pizza2_ppi < pizza1_ppi) {
        cout << "The second pizza is a better deal." << endl;
        cout << "It is " << pizza1_ppi / pizza2_ppi << " times cheaper." << endl;
    }
    else
        cout << "Both pizzas are of equal value." << endl;
    
    return 0;
}

