//
//  214 Shortest Palindrome.cpp
//  LeetCode
//
//  Created by 赵超 on 9/2/16.
//  Copyright © 2016 赵超. All rights reserved.
//
//  Reference: @Sammax's 8ms KMP based algprithm
//  https://discuss.leetcode.com/topic/14526/c-8-ms-kmp-based-o-n-time-o-n-memory-solution

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class KMP {
public:
    static vector<int> next(string pattern) {
        int length = (int) pattern.size();
        vector<int> ret(length + 1);
        ret[0] = -1;
        for (int i = 0; i < length; i++) {
            int j = ret[i];
            while (j != -1 && pattern[i] != pattern[j]) {
                j = ret[j];
            }
            ret[i + 1] = j + 1;
        }
        return ret;
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string l = s + "^" + rev;
        vector<int> next = KMP::next(l);
        int pos = *(next.end() - 1);
        return rev.substr(0, rev.length() - pos) + s;
    }
    static int test(string s) {
        printf("string: %s\n", s.c_str());
        vector<int> next = KMP::next(s);
        for (auto it = next.begin(); it != next.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
        return 0;
    }
};