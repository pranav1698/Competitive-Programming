// Get start of the loop in the Linked List
// SlothyCoder16
// October 01, 2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode* slow=A;
    ListNode* fast=A;

    while(fast!=NULL) {
        fast=fast->next;
        if(fast!=NULL) {
            fast=fast->next;
            slow=slow->next;
        }

        if(slow==fast) break;
    }

    if(fast) {
        slow=A;

        while(slow != fast) {
            slow=slow->next;
            fast=fast->next;
        }

        return slow;
    }

    return NULL;
}
