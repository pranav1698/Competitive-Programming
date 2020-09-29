// Remove duplicates from sorted list
// SlothyCoder16
// September 29, 2020

// Remove duplicates from sorted list
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
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* temp=A;
    if(A==NULL && A->next==NULL) return A;

    while(A!=NULL) {
        if(A->next!=NULL && A->val==A->next->val) {
            A->next=A->next->next;
        } else {
            A=A->next;
        }
    }

    return temp;
}
