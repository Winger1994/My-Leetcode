//
//  Palindrome Number.cpp
//  LeetCode
//
//  Created by 赵超 on 8/30/16.
//  Copyright © 2016 赵超. All rights reserved.
//

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 || ( x != 0 && x % 10 == 0))
            return false;
        int sum=0;
        while(x > sum)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return x == sum || x == sum / 10;
    }
};