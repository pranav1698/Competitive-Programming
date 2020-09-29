// Reverse Linked List
// SlothyCoder16
// September 29, 2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* A) {
        if(A==NULL || A->next==NULL) return A;
        ListNode* prev=NULL;
        ListNode* forw=NULL;

        while(A!=NULL) {
            forw=A->next;
            A->next=prev;
            prev=A;
            A=forw;
        }

        return prev;
    }
};
