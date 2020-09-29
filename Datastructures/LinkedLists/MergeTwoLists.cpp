// Merge Two Sorted Lists using Merge Knowledge
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
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(A == NULL) {
        return B;
    } else if(B == NULL) {
        return A;
    }

    ListNode* root = NULL;
    if(A->val <= B->val) {
        root=A;
        root->next = mergeTwoLists(A->next, B);
    } else {
        root=B;
        root->next = mergeTwoLists(A, B->next);
    }

    return root;
}
