// Swap Linked List in pairs
// SlothyCoder16
// September 29, 2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* temp=A;

    while(A!=NULL) {
        if(A->next!=NULL) {
            int temp=A->val;
            A->val=A->next->val;
            A->next->val=temp;
            A=A->next->next;
        } else {
            A=A->next;
        }
    }

    return temp;
}
