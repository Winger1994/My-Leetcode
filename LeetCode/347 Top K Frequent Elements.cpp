//
//  347 Top K Frequent Elements.cpp
//  LeetCode https://leetcode.com/problems/top-k-frequent-elements/#/description
//
//  Created by 赵超 on 14/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    class IntPair: public pair<int, int> {
    public:
        IntPair(int k, int v): pair<int, int>(k, v){}
        IntPair(pair<int, int> p): pair<int, int>(p){}
        // the Comp in sort function will call the comparison between const IntPairs !!!
        bool operator> (const IntPair& p) const {
            return this->second > p.second;
        }
        bool operator< (const IntPair& p) const {
            return this->second < p.second;
        }
    };
//    class IntPair {
//    public:
//        int key, value;
//        IntPair(int k, int v) {
//            key = k;
//            value = v;
//        }
//        IntPair(pair<int, int> p) {
//            key = p.first;
//            value = p.second;
//        }
//        bool operator> (IntPair p) {
//            return this->value > p.value;
//        }
//        bool operator< (IntPair p) {
//            return this->value < p.value;
//        }
//    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (map.find(*it) == map.end()) {
                map[*it] = 1;
            } else {
                map[*it]++;
            }
        }
        vector<IntPair> kvVec;
        for (auto it = map.begin(); it != map.end(); ++it) {
            // printf("key:%d value:%d\n", it->first, it->second);
            kvVec.push_back(IntPair(*it));
        }
        sort(kvVec.begin(), kvVec.end(), greater<IntPair>());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(kvVec[i].first);
        }
        return res;
    }
    static void test() {
        Solution solution;
        vector<int> nums{6,1,1,1,2,2,3,3,3,3,3,3,4,4,4,4,5};
        int k = 2;
        printf("%d\n", IntPair(1, 3) > IntPair(2, 2));
        for (int i : solution.topKFrequent(nums, k)) {
            printf("%d ", i);
        }
        printf("\n");
        string s = "hello";
        reverse(s.begin(), s.end());
        printf("%s\n", s.c_str());
    }
};
