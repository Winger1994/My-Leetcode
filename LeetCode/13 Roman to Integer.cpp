//
//  13 Roman to Integer.cpp
//  LeetCode
//
//  Created by 赵超 on 8/31/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
private:
    int pos = 0;
    int oneRomanToInt(string s, const char one, const char five, const char ten) {
        if (s == "")
            return 0;
        if (s[s.length() - 1] == ten)
            return 9;
        if (s[s.length() - 1] == five) {
            if (s.length() == 1)
                return 5;
            else
                return 4;
        }
        return (int)s.length() + (s[0] == five ? 4 : 0);
    }
    string romanParser(string s, const char one, const char five, const char ten) {
        // static int pos = 0; // Leetcode forbids the use of global variables
        int begin = pos;
        while (pos < s.length() &&
               (s[pos] == one || s[pos] == five || s[pos] == ten))
            pos++;
        return s.substr(begin, pos - begin);
    }
public:
    int romanToInt(string s) {
        int ret = 0;
        ret += oneRomanToInt(romanParser(s, 'M', '*', '*'), 'M', 'E', 'E');
        ret *= 10;
        ret += oneRomanToInt(romanParser(s, 'C', 'D', 'M'), 'C', 'D', 'M');
        ret *= 10;
        ret += oneRomanToInt(romanParser(s, 'X', 'L', 'C'), 'X', 'L', 'C');
        ret *= 10;
        ret += oneRomanToInt(romanParser(s, 'I', 'V', 'X'), 'I', 'V', 'X');
        return ret;
    }
};