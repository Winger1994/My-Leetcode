//
//  190 Reverse Bits.cpp
//  LeetCode https://leetcode.com/problems/reverse-bits/#/description
//
//  Created by 赵超 on 14/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int travel = 31;
        while (n != 0) {
            if (n % 2) {
                res += (1u << travel);
            }
            --travel;
            n  = n >> 1;
        }
        return res;
    }
    static void test() {
        Solution solution;
        printf("%x\n", solution.reverseBits(1));
    }
};
