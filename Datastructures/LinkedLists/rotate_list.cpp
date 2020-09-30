// Rotate List in right by B places
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
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int N=0;
    ListNode* curr=A;
    while(curr!=NULL) {
        curr=curr->next;
        N++;
    }

    int index = N-(B%N)+1;

    curr=A;
    ListNode* l1=new ListNode(0);
    ListNode* startl1=l1;
    int i=0;
    while(i<index-1 && curr) {
        l1->next=curr;
        curr=curr->next;
        l1=l1->next;
        i++;
    }

    ListNode* l2=l1->next;
    if(l2 == NULL) return startl1->next;
    l1->next=NULL;
    ListNode* startl2=l2;
    while(l2->next != NULL) {
        l2=l2->next;
    }
    l2->next=startl1->next;

    return startl2;
}
