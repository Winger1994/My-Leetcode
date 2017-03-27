//
//  98 Validate Binary Search Tree.cpp
//  LeetCode https://leetcode.com/problems/validate-binary-search-tree/#/description
//
//  Created by 赵超 on 15/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"

class Solution {
private:
    bool varify(TreeNode* root, int *max, int *min) {
        if (root == NULL)
            return true;
        if (max != NULL && root->val >= *max)
            return false;
        if (min != NULL && root->val <= *min)
            return false;
        return varify(root->left, &(root->val), min) && varify(root->right, max, &(root->val));
    }
public:
    bool isValidBST(TreeNode* root) {
        return varify(root, NULL, NULL);
    }
};
