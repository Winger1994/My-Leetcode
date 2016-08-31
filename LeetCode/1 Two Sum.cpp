//
//  Two Sum.cpp
//  LeetCode
//
//  Created by 赵超 on 8/29/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            auto p = map.find(target - nums[i]);
            if (p != map.end()) {
                return {p->second, i};
            }
            map[nums[i]]=i;
        }
        return {0, 0};
    }
};