//
//  82 Remove Duplicates from Sorted List II.cpp
//  LeetCode
//
//  Created by 赵超 on 9/21/16.
//  Copyright © 2016 赵超. All rights reserved.
//

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *newNumHead = dummy;
        ListNode *numNode;
        bool del;
        while (newNumHead->next != NULL) {
            del = false;
            numNode = newNumHead->next;
            while (numNode->next != NULL &&
                   numNode->next->val == newNumHead->next->val) {
                numNode = numNode->next;
                del = true;
            }
            if (del) {
                ListNode* delHead = newNumHead->next;
                newNumHead->next = numNode->next;
                while (delHead != numNode) {
                    ListNode *tmp = delHead->next;
                    delete delHead;
                    delHead = tmp;
                }
                delete numNode;
            } else
                newNumHead = numNode;
        }
        return dummy->next;
    }
};
