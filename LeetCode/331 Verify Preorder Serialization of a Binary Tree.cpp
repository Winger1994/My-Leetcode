//
//  331 Verify Preorder Serialization of a Binary Tree.cpp
//  LeetCode
//
//  Created by 赵超 on 02/10/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
private:
    string nextToken(string preorder, int& pos) {
        while (pos < preorder.length() && preorder[pos] == ',')
            ++pos;
        int begin = pos;
        while (pos < preorder.length() && preorder[++pos] != ',');
        return preorder.substr(begin, pos - begin);
    }
public:
    bool isValidSerialization(string preorder) {
        int degree = 1; /* in-degree is negative and out-degree is positive */
        int pos = 0;
        while (pos < preorder.length()) {
            if (nextToken(preorder, pos) == "#")
                --degree;
            else
                ++degree;
            if (pos < preorder.length() && degree == 0)
                return false;
        }
        return degree == 0;
    }
};
