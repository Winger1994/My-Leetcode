//
//  337 House Robber III.cpp
//  LeetCode https://leetcode.com/problems/house-robber-iii/#/description
//
//  Created by 赵超 on 15/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

class Solution {
private:
    unordered_map<TreeNode*, int> map;
    int robWithoutHead(TreeNode* root) {
        if (root == NULL)
            return 0;
        return getRobMax(root->left) + getRobMax(root->right);
    }
    int getRobMax(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (map.find(root) == map.end())
            calcRobMax(root);
        return map[root];
    }
    void calcRobMax(TreeNode* root) {
        map[root] = max(robWithoutHead(root), root->val + robWithoutHead(root->left) + robWithoutHead(root->right));
    }
public:
    int rob(TreeNode* root) {
        return getRobMax(root);
    }
};
