//
//  91 Decode Ways.cpp
//  LeetCode
//
//  Created by 赵超 on 9/9/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    string str;
    int get(vector<int> &res, int index) {
        if (index >= res.size())
            return 1;
        if (res[index] == -1)
            calc(res, index);
        return res[index];
    }
    void calc(vector<int> &res, int index) {
        if (str[index] == '0') {
            res[index] = 0;
            return;
        }
        if (index + 1 < res.size() && (str[index] == '1' || (str[index] == '2' && str[index + 1] <= '6'))) {
            res[index] = get(res, index + 1) + get(res, index + 2);
            return;
        }
        res[index] = get(res, index + 1);
    }
public:
    int numDecodings(string s) {
        if (s == "")
            return 0;
        str = s;
        vector<int> res(s.length(), -1);
        return get(res, 0);
    }
};