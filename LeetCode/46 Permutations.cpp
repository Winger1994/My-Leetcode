//
//  46 Permutations.cpp
//  LeetCode
//
//  Created by 赵超 on 09/12/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<vector<bool>, vector<vector<int>>> map;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // int length = (int) nums.size();
        return {{1}};
    }
};
