//
//  steps.cpp
//  LeetCode
//
//  Created by 赵超 on 9/19/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    static int findMinStepNumPass(int n) {
        int i = 0;
        while ((i + 1) * i / 2 < n) {
            i++;
        }
        return i;
    }
    static int steps(int n, vector<bool>& method) {
        int base = findMinStepNumPass(n);
        int distance = (base * (base + 1)) / 2;
        int diff = distance - n;
        if (diff % 2 == 0) {
            method[diff / 2] = false;
            return base;
        }
        if (base % 2 == 0) {
            method[(diff + base + 1) / 2] = false;
            return base + 1;
        } else {
            method[diff / 2] = false;
            method[base + 2] = false;
            return base + 2;
        }
    }
    static void printMethod(const vector<bool>& method, int steps) {
        for (int i = 1; i <= steps; i++) {
            if (method[i])
                cout << '+';
            else
                cout << '-';
            cout << i << ' ';
        }
        cout << endl;
    }
public:
    static void test() {
        const int capacity = 10000;
        vector<bool> method(capacity);
        for (vector<bool>::iterator it = method.begin(); it != method.end(); it++) {
            *it = true;
        }
        int n;
        cout << "input n = ";
        cin >> n;
        int s = steps(n, method);
        printMethod(method, s);
    }
};
