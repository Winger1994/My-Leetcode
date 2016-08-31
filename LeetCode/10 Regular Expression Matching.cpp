//
//  Regular Expression Matching.cpp
//  LeetCode
//
//  Created by 赵超 on 8/30/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <string>
#include <stdio.h>
using namespace std;

class Solution {
private:
    bool isMatchSub(string s, int si, string p, int pi) {
        if (si == s.length() && pi == p.length()) {
            printf("match! (si = %d, pi = %d)\n", si, pi);
            return true;
        }
        if (pi == p.length()) {
            printf("string p hits limit, return false! (si = %d, pi = %d)\n", si, pi);
            return false;
        }
        printf("compare %s and %s\n", s.substr(si).c_str(), p.substr(pi).c_str());
        char cs = s[si];
        if (p[pi] == cs) {
            if (pi + 1 == p.length() || p[pi + 1] != '*') {
                return isMatchSub(s, si + 1, p, pi + 1);
            } else {
                int i = si;
                for (;i < s.length() && s[i] == cs; ++i) {
                    if (isMatchSub(s, i, p, pi + 2))
                        return true;
                    printf("s[%d] = %d\n", i + 1, s[i + 1]);
                }
                if (isMatchSub(s, i, p, pi + 2))
                    return true;
                return false;
            }
        }
        if (p[pi] == '.') {
            if (pi + 1 == p.length() || p[pi + 1] != '*') {
                return isMatchSub(s, si + 1, p, pi + 1);
            } else {
                for (int i = si; i <= s.length(); ++i) {
                    if (isMatchSub(s, i, p, pi + 2))
                        return true;
                }
                return false;
            }
        }
        if (p[pi + 1] == '*')
            return isMatchSub(s, si, p, pi + 2);
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return isMatchSub(s, 0, p, 0);
    }
};
