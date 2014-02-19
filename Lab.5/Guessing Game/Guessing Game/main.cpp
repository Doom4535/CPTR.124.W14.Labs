//
//  main.cpp
//  Guessing Game
//
//  Created by Aaron Covrig on 1/27/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Xcode seems to generate a larger rand() output then Visual studio (need to find the actual value)

int main()
{
    srand(static_cast<unsigned>(time(0)));
    
    int i = 0;
    int random = 0;
    int guess = 0;
    // using i to keep track of the number of guesses
    random = (rand() % 100) + 1;  // converts the random output into a value that ranges from 1 to 100
    while (i >= 0) {    // making an infinite loop that ends when the player guesses correctly
        // cout << random << endl; // This line is used to see the random value before conversion (for debugging purposes)
        cout << "Make a guess from 1 to 100: ";
        cin >> guess;
        cout << endl;
        if ( guess == random) {
            cout << "Congradulations! You guessed correctly!" << endl;
            break;
        }
        else {
            cout << "I'm sorry, that answer is wrong." << endl;
            if (guess < random)
                cout << "Your guess of " << guess << " was to low." << endl;
            else
                cout << "Your guess of " << guess << " was to high." << endl;
        }
        i++;
        // cout << "Answer: " << random << endl;  // This is the correct answer (to be used for debugging purposes
    }
    cout << "It took you " << i << " tries to guess the right number";
}

