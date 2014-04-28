//
//  main.cpp
//  Lab.final
//
//  Created by Aaron Covrig on 4/28/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

//Important:  Add your name as a comment here

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//----------------------------------------------
//  Question #1
//----------------------------------------------

void interactive_maximum() {
    vector<int> vec1;
    int x = 0;
    int y = 0;
    // cout << "Please enter the numbers you wish to use: "; // removing because of specifications
    while (x != 9999999) {
        cin >> x;
        vec1.push_back(x);
        }
    
    if (vec1.size() > 1) {
        y = vec1[0];
        vec1.pop_back();
        for (int i = 0; i < vec1.size(); i++) {
            if (vec1[i] > y)
                y = vec1[i];
        
        }
        cout << y << endl;
    }
    
}

//----------------------------------------------
//  Question #2
//----------------------------------------------

bool sign_balanced(const vector<int>& v) {
    
    int pos = 0;
    int neg = 0;
    for (int e = 0; e < v.size(); e++) {
         if (v[e] > 0)
             pos++;
         else if (v[e] < 0)
             neg++;
     }
    // cout << "Negative: " << neg << " Positive: " << pos << endl; // Debug code
     if (pos == neg)
         return true;
     else
         return false;
}



//----------------------------------------------
//  Question #3
//----------------------------------------------

class Point {
public:
    double x;  // x component of the point
    double y;  // y component of the point
};

class Circle {
public:
    Point center;  // Center of the circle
    double radius; // Radius of the circle
};

//  Determines if point pt is inside circle circ
bool inside(Circle circ, Point pt) {
    double distance;
    // compute the distance from the center of the circle to the point
    distance = sqrt((circ.center.x - pt.x ) * (circ.center.x - pt.x ) + (circ.center.y - pt.y) * (circ.center.y - pt.y));
    // cout << "Radius: " << circ.radius << " Distance: " << distance << endl; // Debug code
    if (distance <= circ.radius)
        return true;
    else
        return false;
}

//----------------------------------------------
//  Question #4
//----------------------------------------------

int replace(vector<int>& v, int src, int dest) {
    //  Replace the following statement with your code
    return 0;
}



//----------------------------------------------
//  Helper functions
//----------------------------------------------

//  Easily make a point object from x, y components
Point make_point(double x, double y) {
    Point result;
    result.x = x;
    result.y = y;
    return result;
}

//  Easily make a circle object from a (x,y) center and
//  r radius
Circle make_circle(double x, double y, double r) {
    Point cent = make_point(x, y);
    Circle result;
    result.center = cent;
    result.radius = r;
    return result;
}

//  Print a vector of integers
ostream& operator<<(ostream& os, const vector<int>& v) {
    os << '{';
    int n = v.size();
    if (n > 0) {
        os << v[0];
        for (int i = 1; i < n; i++)
            cout << ',' << v[i];
    }
    os << '}';
    return os;
}

//----------------------------------------------
//  Main function: adapt as needed during your testing.
//  Remove your main function before submitting.
//----------------------------------------------

int main() {
    //  Exercise interactive_maximum function
    cout << "Please enter the numbers that you would like to find the maximum of ( 9999999 exits): ";
    interactive_maximum();
    
    cout << endl << "-------------------------------------" << endl;
    
    //  Exercise sign_balanced function
    cout << sign_balanced({10, 3, -12, -5, 19, -1}) << endl;
    
    cout << "-------------------------------------" << endl;
    
    //  Exercise inside function
    cout << inside(make_circle(0.0, 0.0, 5.0), make_point(0.0, 4.9)) << endl;
    
    cout << "-------------------------------------" << endl;
    
    vector<int> vec { 3, 6, 2, 3, 5, 2, 2, 7 };
    cout << replace(vec, 2, 7) << ": " << vec << endl;
    
}
