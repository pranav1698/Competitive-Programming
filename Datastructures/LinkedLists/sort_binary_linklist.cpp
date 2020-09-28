// Sort Binary Linked List
// SlothyCoder16
// September 28, 2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    int zeros=0;
    int ones=0;

    ListNode* temp=A;
    while(temp!=NULL) {
        if(temp->val == 0) {
            zeros++;
        } else {
            ones++;
        }

        temp=temp->next;
    }

    ListNode* temp1=A;
    while(A!=NULL) {
        if(zeros>0) {
            A->val=0;
            zeros--;
        } else {
            A->val=1;
            ones--;
        }
        A=A->next;
    }

    return temp1;
}
