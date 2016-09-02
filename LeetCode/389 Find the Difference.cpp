//
//  389 Find the Difference.cpp
//  LeetCode
//
//  Created by 赵超 on 9/1/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
private:
    inline int index(char c) {
        return c - 'a';
    }
public:
    char findTheDifference(string s, string t) {
        int charsNum[26];
        for (int i = 0; i < 26; i++)
            charsNum[i] = 0;
        for (auto it = s.begin(); it != s.end(); it++)
            charsNum[index(*it)] += 1;
        for (auto it = t.begin(); it != t.end(); it++) {
            if (charsNum[index(*it)] == 0)
                return *it;
            charsNum[index(*it)] -= 1;
        }
        return '*';
    }
};
