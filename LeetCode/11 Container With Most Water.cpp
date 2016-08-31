//
//  Container With Most Water.cpp
//  LeetCode
//
//  Created by 赵超 on 8/31/16.
//  Copyright © 2016 赵超. All rights reserved.
//

// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container.

#include <stdio.h>
#include <vector>
using namespace std;

class SolutionRegular {
private:
    inline int min(int a, int b) {
        return a > b ? b : a;
    }
    inline int max(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        for (auto i = height.begin(); i != height.end() - 1; i++) {
            for (auto j = i; j != height.end(); j++) {
                maxA = max(maxA, min(*i, *j) * (int)(j - i));
            }
        }
        return maxA;
    }
};

class Solution {
private:
    inline int min(int a, int b) {
        return a > b ? b : a;
    }
    inline int max(int a, int b) {
        return a > b ? a : b;
    }
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = (int)height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            water = max(water, (j - i) * h);
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return water;
    }
};