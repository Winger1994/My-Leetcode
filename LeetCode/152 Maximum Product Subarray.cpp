//
//  152 Maximum Product Subarray.cpp
//  LeetCode https://leetcode.com/problems/maximum-product-subarray/#/description
//
//  Created by 赵超 on 21/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
    class Record: public vector<vector<int>> {
        int maxCount, counter;
    public:
        Record(int size):
        vector<vector<int>>(size, vector<int>(size, -1)),
        maxCount((size + 1) * size / 2), counter(0) {}
        
        bool isFull() {
            return counter == maxCount;
        }
    };
    
    int get(Record& record, int begin, int end) {
        if (begin > end)
            return -1;
        if (record[begin][end] == -1)
            calc(record, begin, end);
        return record[begin][end];
    }
    
    void calc(Record& record, int begin, int end) {
        int mid = (begin + end) / 2;
        
    }
    
public:
    int maxProduct(vector<int>& nums) {
        
    }
};
