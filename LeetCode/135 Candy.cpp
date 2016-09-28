//
//  135 Candy.cpp
//  LeetCode
//
//  Created by 赵超 on 27/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

class SolutionIdiot {
public:
    int candy(vector<int>& ratings) {
        set<int> ratingSet;
        vector<int> ratingSort;
        for (auto it = ratings.begin(); it != ratings.end(); it++) {
            if (ratingSet.find(*it) == ratingSet.end()) {
                ratingSort.push_back(*it);
                ratingSet.insert(*it);
            }
        }
        sort(ratingSort.begin(), ratingSort.end());
        vector<int> distribution(ratings.size(), 0);
        int size = ratings.size();
        for (int r: ratingSort) {
            int lastPos = -1, lastValue = 0;
            for (int i = 0; i < size; i++) {
                if (ratings[i] == r) {
                    int around = 0;
                    if (i == 0) {
                        around = distribution[1];
                    } else if (i == size - 1) {
                        around = distribution[size - 2];
                    } else {
                        around = max(distribution[i - 1], distribution[i + 1]);
                    }
                    if (lastPos >= 0)
                        distribution[lastPos] = lastValue;
                    lastPos = i;
                    lastValue = around + 1;
                }
            }
            distribution[lastPos] = lastValue;
        }
        int res = 0;
        for (int i : distribution) {
            printf("%d ", i);
            res += i;
        }
        printf("\n");
        return res;
    }
    static void test() {
        SolutionIdiot solution;
        vector<int> vec({1, 1, 2, 2, 4, 1, 8, 1, 5, 3, 4});
        solution.candy(vec);
    }
};

class Solution {
public:
    int candy(vector<int> &ratings) {
        int size=ratings.size();
        if (size <= 1)
            return size;
        vector<int> num(size, 1);
        for (int i = 1; i < size; i++)
        {
            if (ratings[i] > ratings[i-1])
                num[i] = num[i-1] + 1;
        }
        for (int i = size - 1; i > 0 ; i--)
        {
            if(ratings[i-1] > ratings[i])
                num[i-1] = max(num[i]+1, num[i-1]);
        }
        int result = 0;
        for (int i = 0; i < size; i++)
        {
            result += num[i];
            // cout << num[i] << " ";
        }
        return result;
    }
    static void test() {
        Solution solution;
        vector<int> vec({1, 1, 2, 2, 4, 1, 8, 1, 5, 3, 4});
        solution.candy(vec);
    }
};
