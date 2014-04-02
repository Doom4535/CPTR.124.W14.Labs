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

int find(const vector<int>& v, int seek) {
    int result = -1;
    for (int i = 0; i < v.size(); i++) {
        if (seek == v[i]) {
            result = i;
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
    // incomplete
    return -1;
}



bool remove_first(vector<int>& v, int del) {
    // incomplete
    return -1;
}


int remove_all(vector<int>& v, int del) {
    // incomplete
    return -1;
}



void rotate(vector<int>& v, int n) {
    // incomplete
}


bool subsequence(const vector<int>& seq1, const vector<int>& seq2) {
    // incomplete
    return -1;
}









