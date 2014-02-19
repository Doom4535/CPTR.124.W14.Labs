//
//  main.cpp
//  Time.seconds
//
//  Created by Aaron Covrig on 1/15/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int hour, minute, second;
    cout << "This program will convert the given time into seconds." << endl;
    cout << "Please enter in the hours, minutes, and seconds: ";
    cin >> hour >> minute >> second;
    hour = hour * 3600;
    minute = minute * 60;
    cout << hour + minute + second << endl;
}

