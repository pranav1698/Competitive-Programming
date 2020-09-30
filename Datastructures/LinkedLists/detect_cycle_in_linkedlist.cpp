// Detecting a cycle in the linked list
// SlothyCoder16
// September 30, 2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL) {
            fast=fast->next;
            if(fast!=NULL) {
                slow=slow->next;
                fast=fast->next;
            }

            if(fast==slow) return true;
        }

        return false;
    }
};
