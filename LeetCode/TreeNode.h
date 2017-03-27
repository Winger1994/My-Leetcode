//
//  TreeNode.h
//  LeetCode
//
//  Created by 赵超 on 23/10/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#ifndef TreeNode_h
#define TreeNode_h
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif /* TreeNode_h */
