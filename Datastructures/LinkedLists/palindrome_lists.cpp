// Checking if list is palindrome or not
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
int Solution::lPalin(ListNode* A) {
    if(A==NULL) return 1;
    ListNode* curr=A;
    int N=0;
    while(curr!=NULL) {
        curr=curr->next;
        N++;
    }

    int mid=N/2;
    curr=A;
    int i=1;
    while(i<mid) {
        curr=curr->next;
        i++;
    }

    ListNode* l2=curr->next;
    if(l2==NULL) return true;
    curr->next=NULL;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    while(l2!=NULL) {
        next=l2->next;
        l2->next=prev;
        prev=l2;
        l2=next;
    }

    while(A && prev) {
        if(A->val != prev->val) return 0;
        A=A->next;
        prev=prev->next;
    }

    return 1;
}
