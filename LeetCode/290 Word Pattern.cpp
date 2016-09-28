//
//  290 Word Pattern.cpp
//  LeetCode
//
//  Created by 赵超 on 28/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
private:
    vector<string> splitStr(string str) {
        int begin = -1, end;
        vector<string> res;
        while (true) {
            while (str[++begin] == ' ' && begin < str.length());
            if (begin >= str.length())
                break;
            end = begin - 1;
            while (str[++end] != ' ' && end < str.length());
            res.push_back(str.substr(begin, end - begin));
            begin = end;
        }
        return res;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> splits = splitStr(str);
        map<char, string> p2s;
        map<string, char> s2p;
        if (pattern.length() != splits.size())
            return false;
        for (int i = 0; i < pattern.length(); ++i) {
            char p = pattern[i];
            string s = splits[i];
            if (p2s.find(p) == p2s.end()) {
                if (s2p.find(s) == s2p.end()) {
                    p2s[p] = s;
                    s2p[s] = p;
                    printf("add pattern: %c, string: %s\n", p, s.c_str());
                } else {
                    return false;
                }
            } else {
                if (s2p.find(s) == s2p.end())
                    return false;
                if (p2s[p] != s || p != s2p[s])
                    return false;
            }
        }
        return true;
    }
    static void test() {
        Solution solution;
//        string s = "duag dgy wq   wgyqef csat";
//        vector<string> split = solution.splitStr(s);
//        for (auto it = split.begin(); it != split.end(); ++it) {
//            printf("%s\n", (*it).c_str());
//        }
        printf("%d\n", solution.wordPattern("abba", "dog cat cat dog"));
    }
};
