//
//  main.cpp
//  Lab.2.Midpoint.function
//
//  Created by Aaron Covrig on 1/15/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    //  Defining user variables and input
    double x1, x2, y1, y2;
    char left_paren, comma, right_paren;
    cout << "Please enter first point: ";
    cin >> left_paren >> x1 >> comma >> y1 >> right_paren;
    cout << endl;
    cout << "Please enter second point: ";
    cin >> left_paren>> x2 >> comma >> y2 >> right_paren;
    cout << endl;
    //  The actual function
    double mid_x, mid_y;
    mid_x = (x1 + x2) / 2;
    mid_y = (y1 + y2) / 2;
    cout << "The midpoint of the line-segment from (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ") " << "is ";
    cout << "(" << mid_x << "," << mid_y << ")" << endl;
    
}
