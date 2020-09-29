// Adding two number as Lists
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
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry=0;
    ListNode* l=new ListNode(0);
    ListNode* startl=l;

    while(A!=NULL && B!=NULL) {
        int sum=A->val+B->val+carry;
        carry=sum/10;
        l->next=new ListNode(sum%10);
        l=l->next;
        A=A->next;
        B=B->next;
    }

    while(A!=NULL) {
        int sum=A->val+carry;
        carry=sum/10;
        l->next=new ListNode(sum%10);
        l=l->next;
        A=A->next;
    }

    while(B!=NULL) {
        int sum=B->val+carry;
        carry=sum/10;
        l->next=new ListNode(sum%10);
        l=l->next;
        B=B->next;
    }

    if(carry!=0) {
        l->next=new ListNode(carry);
        l=l->next;
    }

    return startl->next;
}
