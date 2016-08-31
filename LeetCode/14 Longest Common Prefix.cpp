//
//  14 Longest Common Prefix.cpp
//  LeetCode
//
//  Created by 赵超 on 8/31/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    string longestCommonPrefix(const string s1, const string s2) {
        int i = 0;
        while (i < s1.length() && i < s2.length()) {
            if (s1[i] == s2[i])
                i++;
            else
                break;
        }
        return s1.substr(0, i);
    }
    string longestCommonPrefix(vector<string>& strs, const int offset, const int length) {
        if (length == 0)
            return "";
        if (length == 1)
            return string(strs[offset]);
        if (length == 2)
            return longestCommonPrefix(strs[offset], strs[offset + 1]);
        return longestCommonPrefix(
                                   longestCommonPrefix(strs, offset, length >> 1),
                                   longestCommonPrefix(strs, offset + (length >> 1), length - (length >> 1))
                                   );
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        return longestCommonPrefix(strs, 0, (int) strs.size());
    }
};
