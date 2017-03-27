//
//  475 Heaters.cpp
//  LeetCode
//
//  Created by 赵超 on 26/02/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        auto heaterIt = heaters.begin();
        int maxRad = 0;
        for (auto it = houses.begin(); it != houses.end(); it++) {
            int r1 = abs(*heaterIt - *it);
            if (heaterIt + 1 == heaters.end()) {
                return max(max(maxRad, r1), abs(*heaterIt - *(houses.end() - 1)));
            }
            int r2 = abs(*(heaterIt + 1) - *it);
            while (heaterIt + 1 != heaters.end() && r1 >= r2) {
                heaterIt++;
                r1 = r2;
                r2 = abs(*(heaterIt + 1) - *it);
            }
            maxRad = max(maxRad, r1);
        }
        return maxRad;
    }
};
