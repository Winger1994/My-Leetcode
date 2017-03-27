//
//  368 Largest Divisible Subset.cpp
//  LeetCode https://leetcode.com/problems/largest-divisible-subset/#/description
//
//  Created by 赵超 on 16/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    template <class T>
    void printVec(vector<T> vec) {
        for (T i : vec) {
            cout << i << ' ';
        }
        printf("\n");
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0)
            return vector<int>();
        sort(nums.begin(), nums.end());
        vector<vector<int>> sets(nums.size());
        int max = 0, index = -1;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            int maxSize = 0, maxIndex = -1;
            for (auto jit = nums.begin(); jit != it; jit++) {
                if (*it % *jit == 0 && sets[jit - nums.begin()].size() > maxSize) {
                    maxIndex = jit - nums.begin();
                    maxSize = sets[maxIndex].size();
                }
            }
            vector<int> tmp;
            if (maxIndex != -1)
                tmp = sets[maxIndex];
            else
                tmp = vector<int>();
            tmp.push_back(*it);
            sets[it - nums.begin()] = tmp; // must record!!
            if (tmp.size() > max) {
                // printVec(tmp);
                max = tmp.size();
                index = it - nums.begin();
            }
        }
        return sets[index];
    }
    static void test() {
        Solution solution;
        vector<int> nums = {3,4,16,8}; // {1,2,3,4,5,6,7,8,9,10,11,12};
        for (int i : solution.largestDivisibleSubset(nums)) {
            printf("%d ", i);
        }
        printf("\n");
    }
};
