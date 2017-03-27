//
//  123 Best Time to Buy and Sell Stock III.cpp
//  LeetCode
//
//  Created by 赵超 on 29/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
    struct DiffInfo {
        int begin;
        int end;
        int diff;
        int lowestPos;
        int highestPos;
        DiffInfo(int b, int e, int d, int l, int h): begin(b), end(e), diff(d), lowestPos(l), highestPos(h) {}
    };
    DiffInfo maxDiff(const vector<int>& prices, int begin, int end) {
        printf("begin: %d, end: %d\n", begin, end);
        if (begin == end) {
            return DiffInfo(begin, end, 0, begin, end);
        }
        int mid = (begin + end) >> 1;
        DiffInfo left = maxDiff(prices, begin, mid);
        DiffInfo right = maxDiff(prices, mid + 1, end);
        int lowPos = prices[left.lowestPos] < prices[right.lowestPos] ? left.lowestPos : right.lowestPos;
        int highPos = prices[left.highestPos] > prices[right.highestPos] ? left.highestPos : right.highestPos;
        DiffInfo maxDiffInfo = left.diff > right.diff ? left : right;
        /* reuse the variables "begin" and "end", they have different meanings from the parameters*/
        int diff = 0;
        int newPotentialMaxDiff = prices[right.highestPos] - prices[left.lowestPos];
        if (maxDiffInfo.diff > newPotentialMaxDiff) {
            begin = maxDiffInfo.begin;
            end = maxDiffInfo.end;
            diff = maxDiffInfo.diff;
        } else {
            begin = left.lowestPos;
            end = right.highestPos;
            diff = newPotentialMaxDiff;
        }
        printf("rise begin: %d, rise end: %d, diff: %d, lowest: %d. highest: %d\n",
               begin, end, diff, lowPos, highPos);
        return DiffInfo(begin, end, diff, lowPos, highPos);
    }
public:
    int maxProfit(vector<int>& prices) {
        int size = static_cast<int>(prices.size());
        if (size <= 1)
            return 0;
        DiffInfo top = maxDiff(prices, 0, size - 1);
        int topBegin = top.begin;
        int topEnd = top.end;
        int topDiff = top.diff;
        printf("top price gap is %d, from %d to %d\n", topDiff, topBegin, topEnd);
        int leftDiff = 0;
        if (topBegin >= 2)
            leftDiff = maxDiff(prices, 0, topBegin - 1).diff;
        int rightDiff = 0;
        if (topEnd < size - 2)
            rightDiff = maxDiff(prices, topEnd + 1, size - 1).diff;
        printf("left diff is %d, right diff is %d\n", leftDiff, rightDiff);
        int secondDiff = max(leftDiff, rightDiff);
        for (int i = topBegin; i <= topEnd; ++i) {
            prices[i] = -prices[i];
        }
        int maxIntervalDiff = maxDiff(prices, topBegin, topEnd).diff;
        return topDiff + max(secondDiff, maxIntervalDiff);
    }
    static void test() {
        Solution solution;
        vector<int> prices = {3, 2, 6, 5, 0, 3};
        printf("max profit: %d\n", solution.maxProfit(prices));
    }
};
