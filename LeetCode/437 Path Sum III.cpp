//
//  437 Path Sum III.cpp
//  LeetCode
//
//  Created by 赵超 on 23/10/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include "TreeNode.h"

using namespace std;

class SolutionMLE {
private:
    typedef vector<int> intvec;
    typedef pair<intvec, intvec> vecpair;
    // the first of the pair include the node itself
    vecpair pathSumVec(TreeNode* root) {
        if (root == NULL) {
            return vecpair(intvec(), intvec());
        }
        vecpair leftPair = pathSumVec(root->left);
        vecpair rightPair = pathSumVec(root->right);
        intvec hasRoot, noRoot;
        for (auto it = leftPair.first.begin(); it != leftPair.first.end(); ++it) {
            hasRoot.push_back(*it + root->val);
        }
        for (auto it = rightPair.first.begin(); it != rightPair.first.end(); ++it) {
            hasRoot.push_back(*it + root->val);
        }
        hasRoot.push_back(root->val);
        noRoot.insert(noRoot.end(), leftPair.first.begin(), leftPair.first.end());
        noRoot.insert(noRoot.end(), leftPair.second.begin(), leftPair.second.end());
        noRoot.insert(noRoot.end(), rightPair.first.begin(), rightPair.first.end());
        noRoot.insert(noRoot.end(), rightPair.second.begin(), rightPair.second.end());
        return vecpair(hasRoot, noRoot);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        vecpair p = pathSumVec(root);
        int res = 0;
        for (int i : p.first) {
            if (i == sum)
                ++res;
        }
        for (int i : p.second) {
            if (i == sum)
                ++res;
        }
        return res;
    }
};

class SolutionSlow {
private:
    typedef vector<int> intvec;
    // the first of the pair include the node itself
    intvec pathSumVec(TreeNode* root, int sum, int& res) {
        if (root == NULL) {
            res = 0;
            return intvec();
        }
        int leftRes, rightRes;
        intvec leftVec = pathSumVec(root->left, sum, leftRes);
        intvec rightVec = pathSumVec(root->right, sum, rightRes);
        res = leftRes + rightRes;
        intvec vec;
        for (auto it = leftVec.begin(); it != leftVec.end(); ++it) {
            int tmp = *it + root->val;
            if (tmp == sum) ++res;
            vec.push_back(tmp);
        }
        for (auto it = rightVec.begin(); it != rightVec.end(); ++it) {
            int tmp = *it + root->val;
            if (tmp == sum) ++res;
            vec.push_back(tmp);
        }
        vec.push_back(root->val);
        if (root->val == sum) ++res;
        return vec;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        int res;
        pathSumVec(root, sum, res);
        return res;
    }
};

class Solution {
public:
    int help(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
        if (!root) return 0;
        root->val += pre;
        int res = (root->val == sum) + (store.count(root->val - sum) ? store[root->val - sum] : 0);
        store[root->val]++;
        res += help(root->left, sum, store, root->val) + help(root->right, sum, store, root->val);
        store[root->val]--;
        return res;
    }
    
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> store;
        return help(root, sum, store, 0);
    }
};
