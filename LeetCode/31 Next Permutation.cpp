//
//  31 Next Permutation.cpp
//  LeetCode
//
//  Created by 赵超 on 29/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto it = nums.end() - 1;
        for (; it > nums.begin(); --it) {
            if (*it > *(it - 1)) {
                auto closestLarger = it;
                while (closestLarger + 1 < nums.end()
                       && *(closestLarger + 1) > *(it - 1)) {
                    ++closestLarger;
                }
                swap(*closestLarger, *(it - 1));
                break;
            }
        }
        reverse(it, nums.end());
    }
};
