//
//  Longest Substring Without Repeating Characters.cpp
//  LeetCode
//
//  Created by 赵超 on 8/30/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <string>
#include <unordered_map>

using namespace std;

class SolutionRegular {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int begin = 0, current = 0;
        int max = 0;
        while (current < s.length()) {
            auto findRes = map.find(s[current]);
            if (findRes == map.end()) {
                map[s[current]] = current;
            } else {
                max = max > (current - begin)? max : (current - begin);
                for (int i = begin; i < findRes->second; i++) {
                    map.erase(s[i]);
                }
                begin = findRes->second + 1;
                map[findRes->first] = current;
            }
            current++;
        }
        max = max > (current - begin)? max : (current - begin);
        return max;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int begin = 0, length = 0;
        int maxBegin = 0, maxLen = 0;
        int prev[256];
        for (int i = 0; i < 256; i++)
            prev[i] = -1;
        for (int i = 0; i < s.length(); i++) {
            if (prev[(int)s[i]] < begin) {
                length++;
            } else {
                if (length > maxLen) {
                    maxLen = length;
                    maxBegin = begin;
                }
                length -= prev[(int)s[i]] - begin;
                begin = prev[(int)s[i]] + 1;
            }
            prev[(int)s[i]] = i;
        }
        if (length > maxLen) {
            maxLen = length;
            maxBegin = begin;
        }
        return maxLen;
    }
};
