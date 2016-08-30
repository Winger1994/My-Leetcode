//
//  ZigZag Conversion.cpp
//  LeetCode
//
//  Created by 赵超 on 8/30/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <string>
using namespace std;

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R

// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if (numRows == 1) {
            return s;
        }
        int group = numRows * 2 - 2;
        int index = 0;
        while (index < s.length()) {
            res.push_back(s[index]);
            index += group;
        }
        for (index = 1; index < numRows - 1; index++) {
            int i = index;
            while (i < s.length()) {
                res.push_back(s[i]);
                if (group - index + (i - index) < s.length()) {
                    res.push_back(s[group - index + (i - index)]);
                }
                i += group;
            }
        }
        index = numRows - 1;
        while (index < s.length()) {
            res.push_back(s[index]);
            index += group;
        }
        return res;
    }
};