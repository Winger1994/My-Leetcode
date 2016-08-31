//
//  Add Two Numbers.cpp
//  LeetCode
//
//  Created by 赵超 on 8/29/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <iostream>
#define getval(l)   (l == NULL? 0 : l->val)
#define nextNode(l) (l == NULL? NULL : l->next)

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr = new ListNode(-1);
        ListNode* ret = ptr;
        int carriage = 0;
        int val;
        while (true) {
            val = getval(l1) + getval(l2) + carriage;
            if (val == 0 && l1 == NULL && l2 == NULL) {
                if (ptr == ret)
                    return new ListNode(0);
                return ret->next;
            }
            carriage = val / 10;
            val = val % 10;
            l1 = nextNode(l1);
            l2 = nextNode(l2);
            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }
    }
};
