//
//  main.cpp
//  Number.to.Word
//
//  Created by Aaron Covrig on 1/19/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int number, remainder;
    cout << "Please enter a number from -100 to 100: ";
    cin >> number;
    
    // setting the bounds of the program
    
    if (number > 100) {
        cout << "That number is too big.";
        cout << endl;
        return -1;
    }
    if (number < -100) {
        cout << "That number is too small.";
        cout << endl;
        return -1;
    }
    
    // determining if the number is negative, printing the correct value and then adjusting it to work with the rest of the program
    
    if (number < 0) {
        cout << "negative ";
        number = - number;
        }
    remainder = number;
    
    // putting zero here because the variable number can obtain a value of zero later on independent from the user input
   
    if (number == 0) {
        cout << "zero";
    }
    if (number == 100) {
        cout << "one hundered";
        number = number - 100;
    }
    
    if (number >= 20 && number < 30) {
            cout << "twenty";
            number = number - 20;
    }
    else if (number >= 30 && number < 40) {
            cout << "thirty";
            number = number - 30;
    }
    else if (number >= 40 && number < 50) {
            cout << "fourty";
            number = number - 40;
    }
    else if (number >= 50 && number < 60) {
            cout << "fifty";
            number = number - 50;
    }
    else if (number >= 60 && number < 70) {
            cout << "sixty";
            number = number - 60;
    }
    else if (number >= 70 && number < 80) {
            cout << "seventy";
            number = number - 70;
    }
    else if (number >= 80 && number < 90) {
            cout << "eighty";
            number = number - 80;
    }
    else if (number >=90 && number < 100) {
            cout << "ninety";
            number = number - 90;
    }
    
    
    // deciding if a '-' is needed (ex. fifty-six)
    
    if (remainder > 20 && number > 0) {
            cout << "-";
    }
    
    
    // these numbers are at the end because numbers larger than 20 depend on them if there is a digit in the 1's place
    
    if (number == 1) {
        cout << "one";
        number = number - 1;
    }
    else if (number == 2) {
        cout << "two";
        number = number - 2;
    }
    else if (number == 3) {
        cout << "three";
        number = number - 3;
    }
    else if (number == 4) {
        cout << "four";
        number = number - 4;
    }
    else if (number == 5) {
        cout << "five";
        number = number - 5;
    }
    else if (number == 6) {
        cout << "six";
        number = number - 6;
    }
    else if (number == 7) {
        cout << "seven";
        number = number - 7;
    }
    else if (number == 8) {
        cout << "eight";
        number = number - 8;
    }
    else if (number == 9) {
        cout << "nine";
        number = number - 9;
    }
    
    // defining special numbers that don't follow the previous rules
    
    if (number == 10) {
        cout << "ten";
        number = number - 10;
    }
    else if (number == 11) {
        cout << "eleven";
        number = number - 11;
    }
    else if (number == 12) {
        cout << "twelve";
        number = number - 12;
    }
    else if (number == 13) {
        cout << "thirteen";
        number = number - 13;
    }
    else if (number == 14) {
        cout << "fourteen";
        number = number - 14;
    }
    else if (number == 15) {
        cout << "fifteen";
        number = number - 15;
    }
    else if (number == 16) {
        cout << "sixteen";
        number = number - 16;
    }
    else if (number == 17) {
        cout << "seventeen";
        number = number - 17;
    }
    else if (number == 18) {
        cout << "eighteen";
        number = number - 18;
    }
    else if (number == 19) {
        cout << "nineteen";
        number = number - 19;
    }
    cout << endl;
    
    
}
