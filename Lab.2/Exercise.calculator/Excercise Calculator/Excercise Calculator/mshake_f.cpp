//
//  mshake_f.cpp
//  Excercise Calculator
//
//  Created by Aaron Covrig on 1/15/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//

#include "burrito_f.h"
#include "salad_f.h"
#include "mshake_f.h"

using namespace std;
int x;

int burrito_f()
{
    int burrito;
    bool user_input;
    cout << "How many bean burritos did you eat? ";
    cin >> burrito;
    cout << "Are you sure? (Y/n)";
    cin >> user_input;
    if (user_input == 1)
        salad_f.h::salad_f();
    else burrito_f();
    
    
}