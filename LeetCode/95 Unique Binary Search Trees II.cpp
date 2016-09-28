//
//  95 Unique Binary Search Trees II.cpp
//  LeetCode
//
//  Created by 赵超 on 28/09/2016.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<pair<int, int>, vector<TreeNode*>*> storage;
    void calculateTrees(pair<int, int> beginEnd) {
        int begin = beginEnd.first;
        int end = beginEnd.second;
        vector<TreeNode*> *res = new vector<TreeNode*>;
        if (end < begin) {
            res->push_back(NULL);
        } else {
            for (int rootValue = begin; rootValue <= end; ++rootValue) {
                pair<int, int> leftKey(begin, rootValue - 1);
                pair<int, int> rightKey(rootValue + 1, end);
                vector<TreeNode*> *leftTrees = getTrees(leftKey);
                vector<TreeNode*> *rightTrees = getTrees(rightKey);
                for (auto lit = leftTrees->begin(); lit != leftTrees->end(); ++lit) {
                    for (auto rit = rightTrees->begin(); rit != rightTrees->end(); ++rit) {
                        TreeNode *rootNode = new TreeNode(rootValue);
                        rootNode->left = *lit;
                        rootNode->right = *rit;
                        res->push_back(rootNode);
                    }
                }
            }
        }
        storage[beginEnd] = res;
    }
    vector<TreeNode*> *getTrees(pair<int, int> beginEnd) {
        if (storage.find(beginEnd) == storage.end()) {
            calculateTrees(beginEnd);
        }
        return storage[beginEnd];
    }
    vector<TreeNode*> *generateTrees(int begin, int end) {
        pair<int, int> beginEnd(begin, end);
        return getTrees(beginEnd);
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        return *generateTrees(1, n);
    }
};
