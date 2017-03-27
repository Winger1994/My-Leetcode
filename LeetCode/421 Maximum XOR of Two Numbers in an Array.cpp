//
//  421 Maximum XOR of Two Numbers in an Array.cpp
//  LeetCode https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/#/description
//
//  Created by 赵超 on 15/03/2017.
//  Copyright © 2017 赵超. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
private:
    class Node {
    public:
        Node(): one(NULL), zero(NULL) {}
        Node *one, *zero;
    };
    
    void push(Node *root, int num) {
        int mask = 1 << 30;
        Node *current = root;
        while (mask) {
            if (mask & num) {
                if (current->one == NULL)
                    current->one = new Node;
                current = current->one;
            } else {
                if (current->zero == NULL)
                    current->zero = new Node;
                current = current->zero;
            }
            mask = mask >> 1;
        }
    }
    int core(Node* num1, Node* num2, int adder) {
        if (adder == 0)
            return 0;
        int res = -1;
        if (num1->one != NULL && num2->zero != NULL)
            res = adder + core(num1->one, num2->zero, adder >> 1);
        if (num1->zero != NULL && num2->one != NULL)
            res = max(res, adder + core(num1->zero, num2->one, adder >> 1));
        if (res >= 0)
            return res;
        if (num1->zero != NULL && num2->zero != NULL)
            return core(num1->zero, num2->zero, adder >> 1);
        return core(num1->one, num2->one, adder >> 1);
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        Node *root = new Node;
        for (int num : nums) {
            push(root, num);
        }
        int adder = 1 << 30;
        Node *current = root;
        while (current->one == NULL || current->zero == NULL) {
            current = current->one == NULL ? current->zero : current->one;
            adder = adder >> 1;
            if (adder == 0)
                return 0;
        }
        return adder + core(current->one, current->zero, adder >> 1);
    }
    static void test() {
        Solution solution;
        vector<int> num{0};
        printf("%d\n", solution.findMaximumXOR(num));
    }
};
