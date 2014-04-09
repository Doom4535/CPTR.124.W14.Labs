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
static ostream& operator<<(ostream& os, const vector<int>& v) {
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
    vector<int> list { -1, 5, 7, 26, 37, 51};
    
    //  Some variables to ensure the function return types
    //  are properly assignable.
    int i;
    bool b;
    
    int num = -5;
    vector<int> list1 { 5, 7, -9, 15 , 17 };
    vector<int> list2 { 5, 7, 8 };
    
    i = maximum(list);
    cout << "Maximum: " << i << endl;
    i = find(list, num);
    cout << "Location of first occurance of " << num << " is: " << i << endl;
    i = count(list, num);
    cout << "Number of occurances of " << num << " is: " << i << endl;
    b = equivalent(list1, list2);
    cout << "Are " << list1 << " and " << list2 << " equivalent? " << b << endl;
    b = prefix(list1, list2);
    cout << "Is list list 2 " << list2 << " a prefix of " << list1 << " ? " << b << endl;
    cout << "Is the vector " << list << " in ascending order? " << is_ascending(list) << endl;
    cout << "Order of vector before sorting: " << list << endl;
    sort(list);
    cout << "Order of vector after sorting: " << list << endl;
    b = is_ascending(list);
    cout << "Is the vector in ascending order? " << b << endl;
    cout << "The vector before removal of a component is: " << list << endl;
    b = remove_first(list, num);
    cout << "Was a number removed from the vector? " << b << endl
         << " The vector after removal of the first occurance of " << num << " is: " << list << endl;
    i = remove_all(list, num);
    cout << "The number of times " << num << " was removed: " << i << endl
         << "The vector after the removal of all occurances of " << num << " is: " << list << endl;
    rotate(list, 2);
    cout << "The vector after rotation is: " << list << endl;
    rotate(list, -2);
    cout << "The vector after rotation with a negative is: " << list << endl;
    b = subsequence(list1, list2);
    cout << "Is " << list2 << " a subsequence of " << list1 << endl;
    cout << b << endl;
}
