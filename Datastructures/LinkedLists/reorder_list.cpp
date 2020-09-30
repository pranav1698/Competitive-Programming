// Reorder List
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
ListNode* Solution::reorderList(ListNode* A) {
    int N=0;
    ListNode* l1=A;
    ListNode* startl1=l1;
    while(l1!=NULL) {
        N++;
        l1=l1->next;
    }

    l1=A;
    int i=0;
    while(i<(N/2)) {
        l1=l1->next;
        i++;
    }

    ListNode* l2=l1->next;
    ListNode* prev=NULL;
    ListNode* next=NULL;
    while(l2!=NULL) {
        next=l2->next;
        l2->next=prev;
        prev=l2;
        l2=next;
    }

    l2=prev;
    l1->next=NULL;

    ListNode* l=new ListNode(0);
    ListNode* startl=l;
    while(startl1!=NULL && l2!=NULL) {
        l->next=startl1;
        l=l->next;
        startl1=startl1->next;
        l->next=l2;
        l=l->next;
        l2=l2->next;
    }

    while(startl1!=NULL) {
        l->next=startl1;
        startl1=startl1->next;
        l=l->next;
    }

    while(l2!=NULL) {
        l->next=l2;
        l2=l2->next;
        l=l->next;
    }

    return startl->next;
}
