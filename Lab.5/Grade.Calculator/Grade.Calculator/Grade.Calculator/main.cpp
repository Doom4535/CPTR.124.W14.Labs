//
//  main.cpp
//  Grade.Calculator
//
//  Created by Aaron Covrig on 2/5/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    // This program is used to calculate the number
    // of students passing and failing a class
    // along with the class grade point average.
    char input;
    int grade = 0;
    double students = 0;
    float average = 0.0;
    int fail = 0;
    cout << "Please enter the letter grades of the students (without + or -) and Z ends the list" << endl;
    while ((input != 'Z') && (input != 'z')) {
        cin >> input;
        if ((input == 'A') || (input == 'a')) {
            grade = grade + 4;
            students++;
        }
        else if ((input == 'B') || (input == 'b')) {
            grade = grade + 3;
            students++;
        }
        else if ((input == 'C') || (input == 'c')) {
            grade = grade + 2;
            students++;
        }
        else if ((input == 'D') || (input == 'd')) {
            grade = grade + 1;
            students++;
        }
        else if ((input == 'F') || (input == 'f')) {
            grade = grade;
            students++;
            fail++;
        }
    }
    // cout << grade << endl;
    average = grade / students;
    cout << "The class size is: " << students << endl;
    cout << "Students failing: " << fail << " (" << (fail / students) * 100 << "%" << ")" << endl;
    cout << "Students passing: " << (students - fail) << " (" << ((students - fail) / students) * 100 << "%" << ")" << endl;
    cout << "The GPA is: " << (grade / students) << endl;
    return 0;
}

