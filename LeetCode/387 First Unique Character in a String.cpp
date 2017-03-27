//
//  387 First Unique Character in a String.cpp
//  LeetCode https://leetcode.com/problems/first-unique-character-in-a-string/?tab=Description
//
//  Created by 赵超 on 23/02/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int rec[26];
        for (int i = 0; i < 26; ++i)
            rec[i] = -1;
        for (int i = 0; i < s.length(); ++i) {
            int index = s[i] - 'a';
            if (rec[index] == -1)
                rec[index] = i;
            else
                rec[index] = -2;
        }
        int res = static_cast<int>(s.length());
        for (int i = 0; i < 26; ++i) {
            if (rec[i] >= 0)
                res = min(res, rec[i]);
        }
        if (res == s.length())
            res = -1;
        return res;
    }
};
