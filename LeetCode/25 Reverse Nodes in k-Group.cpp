//
//  25 Reverse Nodes in k-Group.cpp
//  LeetCode
//
//  Created by 赵超 on 09/12/2016.
//  Copyright © 2016 赵超. All rights reserved.
//
// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
// You may not alter the values in the nodes, only nodes itself may be changed.
// Only constant memory is allowed.

// For example,
// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5

#include <stdio.h>
#include "ListNode.h"

class Solution {
private:
    ListNode* generateSample(ListNode* head, int k) {
        ListNode *shead = NULL, *snext;
        while (head != NULL && k > 0) {
            snext = new ListNode(head->val);
            snext->next = shead;
            shead = snext;
            head = head->next;
            --k;
        }
        if (k > 0)
            return NULL;
        return shead;
    }
    
    void reverseK(ListNode* &node, ListNode* shead) {
        while (shead != NULL) {
            node->val = shead->val;
            node = node->next;
            shead = shead->next;
        }
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head, *shead = generateSample(node, k);
        while (shead != NULL) {
            reverseK(node, shead);
            shead = generateSample(node, k);
        }
        return head;
    }
};
