//
//  101 Symmetric Tree.cpp
//  LeetCode
//
//  Created by 赵超 on 9/9/16.
//  Copyright © 2016 赵超. All rights reserved.
//


// Definition for a binary tree node.
#include <stdio.h>
#include "TreeNode.h"

class Solution {
private:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }
};
