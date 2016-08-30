//
//  Longest Palindromic Substring.cpp
//  LeetCode
//
//  Created by 赵超 on 8/30/16.
//  Copyright © 2016 赵超. All rights reserved.
//

// Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

// Manacher's Algorithm of O(n) time complexity

#include <string>
using namespace std;

class SolutionRegular {
    
    int halfLengthForOneCenter(int center, const string& s) {
        int half = 0;
        while ((center + half) < s.length() && (center - half) >= 0
               && s[center + half] == s[ center - half])
            half++;
        return half;
    }
    
    int halfLengthForTwoCenter(int leftCenter, const string& s) {
        int rightCenter = leftCenter + 1;
        int half = 0;
        while (rightCenter < s.length() && leftCenter >= 0
               && s[leftCenter--] == s[rightCenter++])
            half++;
        return half;
    }
    
public:
    
    string longestPalindrome(string s) {
        string res;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int half = halfLengthForOneCenter(i, s);
            if (half * 2 - 1 > maxLen) {
                maxLen = half * 2 - 1;
                res = s.substr(i - half + 1, maxLen);
            }
            half = halfLengthForTwoCenter(i, s);
            if (half * 2 > maxLen) {
                maxLen = half * 2;
                res = s.substr(i - half + 1, maxLen);
            }
        }
        return res;
    }
    
};
