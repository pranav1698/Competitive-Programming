// Reverse a linked list k at a time
// SlothyCoder16
// September 29, 2020

ListNode* Solution::reverseList(ListNode* A, int B) {
    int N=0;
    ListNode* curr=A;
    ListNode* prev=NULL;
    ListNode* next=NULL;

    while(N<B && curr) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        N++;
    }

    if(next) {
        A->next=reverseList(next, B);
    }

    return prev;
}
