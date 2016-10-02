//
//  309 Best Time to Buy and Sell Stock with Cooldown.cpp
//  LeetCode
//
//  Created by 赵超 on 30/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//
//  Reference: @SylvanasWindrunner's 7-line Java: only consider sell and cooldown
//  https://discuss.leetcode.com/topic/31349/7-line-java-only-consider-sell-and-cooldown

#include <stdio.h>
#include <vector>
using namespace std;

// profit1[i] = max profit on day i if I sell
// profit2[i] = max profit on day i if I do nothing

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit1 = 0, profit2 = 0;
        for(int i = 1; i < prices.size(); i++){
            int copy = profit1;
            profit1 = max(profit1 + prices[i] - prices[i-1], profit2);
            profit2 = max(copy, profit2);
        }
        return max(profit1, profit2);
    }
};
