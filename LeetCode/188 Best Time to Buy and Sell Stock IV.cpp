//
//  188 Best Time to Buy and Sell Stock IV.cpp
//  LeetCode https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/?tab=Description
//
//  Created by 赵超 on 23/02/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> getCriticalPrices(vector<int>& prices) {
        vector<int> critical;
        bool high = false;
        int pos = 1;
        while (pos < prices.size()) {
            if (high ^ (prices[pos] > prices[pos - 1])) {
                critical.push_back(prices[pos - 1]);
                high = !high;
            }
            pos++;
        }
        if (high)
            critical.push_back(prices[pos - 1]);
        return critical;
    }
    int** storage;
    vector<int> critical;
    int groupNum;
    void getStorageSpace(int m, int n) {
        storage = new int*[m];
        for (int i = 0; i < m; ++i) {
            storage[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                storage[i][j] = -1;
            }
        }
    }
    
    void calc(int group, int k) {
        if (group == groupNum - 1) {
            storage[group][k] = critical[group * 2 + 1] - critical[group * 2];
            return;
        }
        int greatest = 0;
        for (int g = group; g < groupNum; ++g) {
            if (critical[g * 2] < critical[group * 2])
                break;
            if (critical[g * 2 + 1] < critical[group * 2 + 1])
                continue;
            int tmp = critical[g * 2 + 1] - critical[group * 2] + get(g + 1, k - 1);
            greatest = max(greatest, tmp);
        }
        greatest = max(greatest, get(group + 1, k));
        storage[group][k] = greatest;
    }
    
    int get(int group, int k) {
        if (k == 0 || group == groupNum)
            return 0;
        if (storage[group][k] == -1) {
            calc(group, k);
        }
        printf("get group: %d k: %d result: %d\n", group, k, storage[group][k]);
        return storage[group][k];
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        critical = getCriticalPrices(prices);
        groupNum = static_cast<int>(critical.size()) / 2;
        if (groupNum == 0)
            return 0;
        if (k >= groupNum) {
            int res = 0;
            for (int g = 0; g < groupNum; ++g) {
                res += critical[g * 2 + 1] - critical[g * 2];
            }
            return res;
        }
        getStorageSpace(groupNum, k + 1);
        return get(0, k);
    }
    static void test() {
        Solution solution;
        vector<int> prices{3,5,3,4,1,4,5,0,7,8,5,6,9,4,1};
        vector<int> critical = solution.getCriticalPrices(prices);
        for (auto it = critical.begin(); it != critical.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
        printf("max profit is %d\n", solution.maxProfit(2, prices));
    }
};
