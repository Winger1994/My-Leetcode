//
//  71 Simplify Path.cpp
//  LeetCode
//
//  Created by 赵超 on 9/5/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    int index = 0;
    string nextToken(string path) {
        do {
            if (index == path.length())
                return "";
            index++;
        } while (path[index] == '/');
        int begin = index;
        while (index < path.length() && path[index] != '/')
            index++;
        return path.substr(begin, index - begin);
    }
public:
    string simplifyPath(string path) {
        stack<string> s;
        string token;
        while (true) {
            token = nextToken(path);
            if (token == ".")
                continue;
            if (token == "..") {
                if (!s.empty())
                    s.pop();
                continue;
            }
            if (token == "")
                break;
            // printf("push token %s\n", token.c_str());
            s.push(token);
        }
        if (s.empty())
            return "/";
        string ret;
        while (!s.empty()) {
            ret = "/" + s.top() + ret;
            s.pop();
        }
        return ret;
    }
    static int test() {
        Solution solution;
        string s = solution.simplifyPath("//////////////ababa////cscs");
        printf("path: %s\n", s.c_str());
        return 0;
    }
};