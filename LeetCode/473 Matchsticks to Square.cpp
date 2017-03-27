//
//  473 Matchsticks to Square.cpp
//  LeetCode https://leetcode.com/problems/matchsticks-to-square/?tab=Description
//
//  Created by 赵超 on 24/02/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        return true;
    }
};
