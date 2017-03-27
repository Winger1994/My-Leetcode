//
//  26 Remove Duplicates from Sorted Array.cpp
//  LeetCode https://leetcode.com/problems/remove-duplicates-from-sorted-array/#/description
//
//  Created by 赵超 on 9/17/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        auto change = nums.begin() + 1;
        for (auto it = change; it != nums.end(); ++it) {
            if (*it != *(it - 1)) {
                *(change++) = *it;
            }
        }
        return static_cast<int>(change - nums.begin());
    }
};
