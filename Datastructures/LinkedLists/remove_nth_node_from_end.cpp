// Remove Nth Node from end
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
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int N=0;
    ListNode* temp=A;
    while(temp!=NULL) {
        N++;
        temp=temp->next;
    }

    int index=N-B+1;
    if(B>=N) return A->next;
    int i=1;
    ListNode* temp1=A;

    while(i<(index-1)) {
        i++;
        A=A->next;
    }

    A->next=A->next->next;

    return temp1;
}
