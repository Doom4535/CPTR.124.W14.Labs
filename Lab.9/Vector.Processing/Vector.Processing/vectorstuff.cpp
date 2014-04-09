//
//  vectorstuff.cpp
//  Vector.Processing
//
//  Created by Aaron Covrig on 3/26/14.
//  Copyright (c) 2014 Aaron Covrig. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <vector>
#include "vectorstuff.h"

using namespace std;
using std::vector;

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


int maximum(const vector<int>& v) {
    
    /*  Old code (replacing with built in function
    for (int i = 0; i < v.size(); i++) {
        max(v[i] , v[i+1]);
    }
    */
    int m_value = 1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > m_value) {
            m_value = v[i];
        }
    }
    return m_value;
}

int find(const vector<int>& v, int seek) { //finds first occurance of a number (seek)
    int result = -1;
    for (int i = 0; i < v.size(); i++) {
        if (seek == v[i]) {
            result = i;
            break;
        }
    }
    return result;
}

int count(const vector<int>& v, int seek) {
    int count = 0;
    for (int elem : v)
        if (elem == seek)
            count++;
    return count;
}

bool equivalent(const vector<int>& v1, const vector<int>& v2) {
    bool result = true;
    if (v1.size() == v2.size()) {  // determining if the two vectors are the same size, if not they cannot be equivalent
        // int n =0;
        int i = 0;
        // for (int i = 0 ; i <= v2.size() ; i++) replaced with while
        while (i < v2.size()) {
            if (find(v2, v1[i]) != -1) {  // determining if the two vectors have the same numbers, if not they cannot be equivalent
                if (count(v2, v1[i]) == ::count(v1, v1[i]))  // determining if the two vectors have the same number of each element
                    i++;
                else {
                    break;
                    result = false;
                }
            }
            else {
                break;
                result = false;
            }
        }
    }
    return result;
}

bool prefix(const vector<int>& v1, const vector<int>& v2) {
    bool result = true;
    for (int i = 0 ; i < v1.size() ; i++) {
        if (v1[i] == v2[i]) {
            i++;
        }
        else
            result = false;
    }
    return result;
}

void sort(vector<int>& v) {
    // Should probably use a different method
    /*
    int m = 0 , size =0 , s = 0;
    m = maximum(v);
    size = v.size();
    s = find(v , m);
    v[size - 1] = m;
    */
    
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[smallest]) {
                smallest = j;
            }
        }
        int temp = v[i];
        v[i] = v[smallest];
        v[smallest] = temp;
    }
}

bool is_ascending(const vector<int>& v){
    bool ascending = true;
    for ( int i = 0 ; i < v.size() - 1 ; i++ )
        if (v[i] > v[i + 1]) {
            ascending = false;
        }
    return ascending;
}



bool remove_first(vector<int>& v, int del) {
    bool removal = false;
    
        int location = -1;
        location = find(v, del);
        for (int i = location; i < (v.size() - 1); i++) {
            v[i] = v[i + 1];
        }
        v.pop_back();
        removal = true;
    
    return removal;
}


int remove_all(vector<int>& v, int del) {
    int i = 0; // calls remove_first however many times count detects the number (del) to be removed.
    int repeat = count(v, del);
    while (i < repeat) {
        if (find(v, del) != -1) {
        remove_first(v, del);
        i++;
        }
    }
    return i;
}



void rotate(vector<int>& v, int n) {
    int m = abs(n);
    if (n > 0) {
        for (int i = 0; i < n; i++) {
        v.push_back(v[0]);
        remove_first(v, v[0]);
        }
    }
    else if (n < 0) {
        int size = v.size();
        for (int g = 0; (size - g) > (v.size() / 2) ; g++) {
            int last;
            last = v[size - (g + 1)];
            v[v.size() - (g + 1)] = v[0 + g];
            v[0 + g] = last;
            
        }
        for (int i = 0; i < m; i++) {
            v.push_back(v[0]);
            remove_first(v, v[0]);
        }
            for (int g = 0; (size - g) > (v.size() / 2) ; g++) {
                int last;
                last = v[size - (g + 1)];
                v[v.size() - (g + 1)] = v[0 + g];
                v[0 + g] = last;
                
            }

    }
}


// bool subsequence(const vector<int>& seq1, const vector<int>& seq2) {
    //   incomplete (currently breaks if the sequence occurs after a duplicate number in the sequence
    // int z = -1; // used to keep count of current match
    // int h = -1; // used to keep count of previous location of a match in seq1
    // bool test;
    // for (int i = 0; i < seq2.size(); i++) {
        // z = find(seq1, seq2[i]);
        // if (h < z) {
            // test = true;
            // h = z;
        // }
        // else
            // test = false;
        // cout << z << " : " << test << endl;
    // }
    // return test;
// }

int find_modified(const vector<int>& v, int seek, int round, int last) { //finds first occurance of a number (seek) and round is the number of times that it has been called, and last is used to remember the position of the previous match
    int result = -1;
    int occurances = count(v, seek);
    for (int i = ( 0 + last); i < v.size(); i++) {
        if (seek == v[i]) {
            result = i;
            break;
        }
    }
    return result;
}

bool subsequence(const vector<int>& seq1, const vector<int>& seq2) {
    // incomplete (currently breaks if the sequence occurs after a duplicate number in the sequence
    int v = -1;
    int z = -1; // used to keep count of current match
    int h = -1; // used to keep count of previous location of a match in seq1
    bool result;
    bool test;
    int last = 0; // used to move i up for each failure
    int round = 0; // used to keep track of the number of fails
    cout << "List 2 " << seq2 << " List 1 " << seq1 << endl;
    for (int i = 0; i < seq2.size(); i++) {
        z = find_modified(seq1, seq2[i], round, last);
        last = i;
        if (h < z) {
            test = true;
            h = z;
            last = h;
        }
        else {
            test = false;
            round++;
            last++;
        }
        // cout << z << " : " << test << endl; // used to view progress through loop
    }
    return test;
}


        









