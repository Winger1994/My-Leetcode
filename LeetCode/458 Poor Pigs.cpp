//
//  458 Poor Pigs.cpp
//  LeetCode
//
//  There are 1000 buckets, one and only one of them contains poison, the rest are filled with water. They all look the same. If a pig drinks that poison it will die within 15 minutes. What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.
//
//  Answer this question, and write an algorithm for the follow-up general case.
//
//  If there are n buckets and a pig drinking poison will die within m minutes, how many pigs (x) you need to figure out the "poison" bucket within p minutes? There is exact one bucket with poison.
//
//  Created by 赵超 on 08/11/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets == 1) return 0;
        int times = minutesToTest / minutesToDie;
        int powerNum, pigs = 0;
        do {
            ++pigs;
            int tmpTimes = times, tmpPigs = pigs;
            powerNum = 0;
            while (tmpPigs > 0 && tmpTimes > 0) {
                powerNum += tmpPigs;
                --tmpPigs;
                --tmpTimes;
            }
        } while (buckets < (1 << powerNum));
        return pigs;
    }
};
