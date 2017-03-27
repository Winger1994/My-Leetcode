//
//  230 Kth Smallest Element in a BST.cpp
//  LeetCode
//
//  Created by 赵超 on 09/12/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include "TreeNode.h"

class Solution {
private:
    int core(TreeNode* root, int k, int& num, bool& valid) {
        if (root == NULL) {
            num = 0;
            valid = false;
            return 0;
        }
        printf("root: %d, k: %d\n", root->val, k);
        int leftNum, leftRes, rightNum, rightRes;
        bool leftValid, rightValid;
        leftRes = core(root->left, k, leftNum, leftValid);
        if (leftValid) {
            valid = true;
            return leftRes;
        }
        if (leftNum + 1 == k) {
            valid = true;
            return root->val;
        }
        rightRes = core(root->right, k - leftNum - 1, rightNum, rightValid);
        if (rightValid) {
            valid = true;
            return rightRes;
        }
        num = leftNum + rightNum + 1;
        valid = false;
        return 0;
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        bool valid;
        int num, res;
        res = core(root, k, num, valid);
        if (valid)
            return res;
        else
            return -1;
    }
};
