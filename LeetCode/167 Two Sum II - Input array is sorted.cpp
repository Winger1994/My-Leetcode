//
//  167 Two Sum II - Input array is sorted.cpp
//  LeetCode
//
//  Created by 赵超 on 07/12/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
    bool binarySearch(vector<int>& numbers, int num, int begin, int end, int& index) {
        int middle = (begin + end) >> 1;
        if (numbers[middle] == num) {
            index = middle;
            return true;
        }
        if (begin == end)
            return false;
        if (numbers[middle] > num) {
            return binarySearch(numbers, num, begin, middle, index);
        } else {
            return binarySearch(numbers, num, middle + 1, end, index);
        }
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int index1 = i + 1;
            int index2;
            if (binarySearch(numbers, target - numbers[i], index1, (int)numbers.size() - 1, index2)) {
                ++index2;
                return vector<int>{index1, index2};
            }
        }
        return vector<int>(2, 1);
    }
};
