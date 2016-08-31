//
//  Median of Two Sorted Arrays.cpp
//  LeetCode
//
//  Created by 赵超 on 8/30/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <vector>

using namespace std;

class Solution {
private:
    void vectorprint(vector<int>& vec) {
        for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }
    
    inline void copyToEnd(const vector<int>& nums, vector<int>& res, int pos, int index) {
        while (pos < nums.size()) {
            res[index++] = nums[pos++];
        }
    }
    
    void mergeArray(const vector<int>& nums1, const vector<int>& nums2, vector<int>& res) {
        int count1 = 0, count2 = 0;
        int index = 0;
        while (index < res.size()) {
            if (count1 == nums1.size()) {
                copyToEnd(nums2, res, count2, index);
                return;
            }
            if (count2 == nums2.size()) {
                copyToEnd(nums1, res, count1, index);
                return;
            }
            if (nums1[count1] < nums2[count2]) {
                res[index++] = nums1[count1++];
            } else {
                res[index++] = nums2[count2++];
            }
        }
    }
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned long size = nums1.size() + nums2.size();
        vector<int> merge(size);
        mergeArray(nums1, nums2, merge);
        vectorprint(merge);
        double res;
        if (size % 2 == 0) {
            res = static_cast<double>(merge[size >> 1] + merge[(size >> 1) - 1]) / 2;
        } else {
            res = static_cast<double>(merge[size >> 1]);
        }
        return res;
    }
};
