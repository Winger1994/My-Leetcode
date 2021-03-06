//
//  226 Invert Binary Tree.cpp
//  LeetCode
//
//  Created by 赵超 on 9/5/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};
