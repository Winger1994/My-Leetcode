//
//  Reverse Integer.cpp
//  LeetCode
//
//  Created by 赵超 on 8/30/16.
//  Copyright © 2016 赵超. All rights reserved.
//


#define MAX_TO_MUL10    ((~(1 << 31)) / 10)

class Solution {
private:
    
    int reversePositive(int x) {
        int num, ret = 0;
        while (x > 0) {
            num = x % 10;
            if (ret > MAX_TO_MUL10)
                return 0;
            ret *= 10;
            ret += num;
            if (ret < 0)
                return 0;
            x = x / 10;
        }
        return ret;
    }
    
public:
    
    int reverse(int x) {
        if (x == 0)
            return 0;
        if (x > 0)
            return reversePositive(x);
        else
            return -reversePositive(-x);
    }
    
};