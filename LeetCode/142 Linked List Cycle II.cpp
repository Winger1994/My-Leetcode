//
//  142 Linked List Cycle II.cpp
//  LeetCode
//
//  Created by 赵超 on 09/12/2016.
//  Copyright © 2016 赵超. All rights reserved.
//
// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
// Note: Do not modify the linked list.
// Follow up: Can you solve it without using extra space?

// 分析：两个指针，一个一次走一步，另一个一次走两步，走得慢的被追上时一定没有走过重复的节点

#include <stdio.h>
#include "ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        
        ListNode* firstp = head;
        ListNode* secondp = head;

        do {
            firstp = firstp->next;
            if (secondp->next == NULL)
                return NULL;
            secondp = secondp->next->next;
            if (secondp == NULL)
                return NULL;
        } while(firstp != secondp);

        firstp = head;
        while( firstp != secondp) {
            firstp = firstp->next;
            secondp = secondp->next;
        }
        return firstp;
    }
};
