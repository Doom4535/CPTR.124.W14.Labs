//
//  main.cpp
//  Seconds.to.hours
//
//  Created by Aaron Covrig on 1/15/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int time, hour, minute, second;
    cout << "This calculator will convert seconds to hours" << endl;
    cout << "Please enter seconds now: ";
    cin >> time;
    hour = time / 3600;
    time = time % 3600;
    minute = time / 60;
    second = time % 60;
    cout << hour << " hrs " << minute << " min " << second << " sec" << endl;
    
}

