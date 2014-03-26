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
    int m_value = 0;
    for (int i = 0; i <= v.size(); i++) {
        if (v[i] > m_value) {
            m_value = v[i];
        }
    }
    return m_value;
}

int find(const vector<int>& v, int seek) {
    for (int i = 0; i <= v.size(); i++) {
        if (seek == v[i]) {
            return i;
        }
    
    else
        return -1;
    }
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
    if (v1.size() == v2.size()) {
        // int n =0;
        int i = 0;
        // for (int i = 0 ; i <= v2.size() ; i++) replaced with while
        while (i <= v2.size()) {
            if (find(v2, v1[i]) != -1) {
                if (count(v2, v1[i]) == ::count(v1, v1[i]))
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
    
}




