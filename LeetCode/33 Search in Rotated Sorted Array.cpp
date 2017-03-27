//
//  33 Search in Rotated Sorted Array.cpp
//  LeetCode
//
//  Created by 赵超 on 09/12/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;


class Solution {
private:
    int length, zero;
    int findBegin(vector<int>& nums, int begin, int end) {
        // printf("begin: %d, end: %d\n", begin, end);
        /* 要考虑到顺序数组的情况 */
        if (end <= begin)
            return 0;
        if (end - begin == 1) {
            if (nums[end] < nums[begin])
                return end;
            return 0;
        }
        int mid = (begin + end) >> 1;
        if (nums[mid] > nums[begin])
            return findBegin(nums, mid, end);
        else
            return findBegin(nums, begin, mid);
    }
    
    inline int real(int i) {
        return (i + zero) % length;
    }
    
    int binarySearch(vector<int>& nums, int begin, int end, int target) {
        // printf("begin: %d, end: %d\n", begin, end);
        if (end < begin)
            return -1;
        int mid = (begin + end) >> 1;
        if (nums[real(mid)] == target)
            return real(mid);
        if (begin == end)
            return -1;
        if (nums[real(mid)] > target)
            return binarySearch(nums, begin, mid, target);
        else
            return binarySearch(nums, mid + 1, end, target);
    }
    
public:
    int search(vector<int>& nums, int target) {
        length = (int) nums.size();
        zero = findBegin(nums, 0, length - 1);
        // printf("zero: %d\n", zero);
        return binarySearch(nums, 0, length - 1, target);
    }
};
