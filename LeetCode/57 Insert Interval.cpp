//
//  57 Insert Interval.cpp
//  LeetCode
//
//  Created by 赵超 on 27/02/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int startIndex = 0;
        auto it = intervals.begin();
        for (; it != intervals.end(); it++) {
            if (newInterval.start < it->start)
                break;
            ++startIndex;
            if (newInterval.start <= it->end) // It is EQUAL or less!
                break;
            ++startIndex;
        }
        int endIndex = (it - intervals.begin()) * 2;
        for (; it != intervals.end(); it++) {
            if (newInterval.end < it->start)
                break;
            ++endIndex;
            if (newInterval.end <= it->end) // Same!
                break;
            ++endIndex;
        }
        vector<Interval> res;
        res.insert(res.end(), intervals.begin(), intervals.begin() + (startIndex / 2));
        int start, end;
        if (startIndex % 2)
            start = intervals[startIndex / 2].start;
        else
            start = newInterval.start;
        if (endIndex % 2)
            end = intervals[endIndex / 2].end;
        else
            end = newInterval.end;
        res.insert(res.end(), Interval(start, end));
        res.insert(res.end(), intervals.begin() + (endIndex + 1) / 2, intervals.end());
        return res;
    }
};
