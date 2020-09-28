// Kth node from middle
// SlothyCoder16
// September 28, 2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    int N=0;
    ListNode* temp=A;
    while(temp!=NULL) {
        N++;
        temp=temp->next;
    }

    if(B > (N/2)) return -1;
    int index=N/2-B;

    int i=0;
    while(i<index) {
        A=A->next;
        i++;
    }

    return A->val;
}
