//  File simplevectortestfile.cpp

#include <iostream>
#include "vectorstuff.h"

using namespace std;

//  This code performs *extremely* simple
//  tests.  This is only the first steps to any
//  testing you may want to perform.  You must ensure
//  that your vectorstuff.cpp file compiles cleanly
//  with this file.  If the compiler generates errors
//  when using your code and this code together, your
//  code has no chance passing my more extensive test
//  suite.
//
//  Since this is only a very test simple suite, you should
//  create more interesting tests in an attempt to reveal
//  the logic errors that may be lurking in your
//  functions.

// Modifying cout to print vectors
ostream& operator<<(ostream& os, const vector<int>& v) {
    os << '{';
    int n = v.size();
    if (n > 0) {
        os << v[0];
        for (int i = 1; i < n; i++)
            os << ',' << v[i];
    }
    os << '}';
    return os;
}

int main() {
    //  Make a small vector of integers
    vector<int> list { 1, 5, 3, 10 };
    
    //  Some variables to ensure the function return types
    //  are properly assignable.
    int i;
    bool b;
    
    i = maximum(list);
    cout << "Maximum: " << i << endl;
    int num = 10;
    i = find(list, num);
    cout << "Location of first occurance of " << num << " is: " << i << endl;
    i = count(list, num);
    cout << "Number of occurances of " << num << " is: " << i << endl;
    b = equivalent(list, list);
    b = prefix(list, list);
    cout << "Order of vector before sorting: " << list << endl;
    sort(list);
    cout << "Order of vector after sorting: " << list << endl;
    b = is_ascending(list);
    b = remove_first(list, num);
    i = remove_all(list, num);
    rotate(list, 2);
    b = subsequence(list, list);
}
