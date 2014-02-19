//
//  tip.calculator.attempt.cpp
//  random
//
//  Created by Aaron Covrig on 1/8/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()

{
    // Meal price
    float mprice;
    cout << "Meal price" << endl;
    cin >> mprice;
    // Tip percent
    float percent;
    cout << "Input tip percent" << endl;
    cin >> percent;
    float tipamount;
    tipamount = mprice * (percent / 100);
    cout << "The tip comes to: $" << tipamount << endl;
    // Meal total
    float total;
    total = mprice + tipamount;
    // Total with tip
    cout << "The total with tip is: $" << total << endl;
}
