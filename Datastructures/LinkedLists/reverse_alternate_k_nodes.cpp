// Reverse alternate k nodes
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
ListNode* reverse(ListNode* A, int B, int count) {
    if((count&1) ==0 ) {
        ListNode* curr=A;
        int N=0;
        while(N<B-1 && curr) {
            curr=curr->next;
            N++;
        }

        if(curr->next) {
            curr->next=reverse(curr->next, B, count+1);
        }

        return A;
    }


    ListNode* curr=A;
    ListNode* prev=NULL;
    ListNode* next=NULL;

    int N=0;
    while(N<B && curr) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        N++;
    }

    if(next) {
        A->next=reverse(next, B, count+1);
    }

    return prev;
}

ListNode* Solution::solve(ListNode* A, int B) {
    return reverse(A, B, 1);
}
