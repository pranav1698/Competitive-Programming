// Reversing the positions of evenly positioned elements
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
ListNode* Solution::solve(ListNode* A) {
    int i=1;
    ListNode* temp=A;
    vector<int> evens;
    while(temp!=NULL) {
        if((i&1)==0) evens.push_back(temp->val);
        temp=temp->next;
        i++;
    }

    reverse(evens.begin(), evens.end());
    ListNode* temp1=A;
    i=1;
    int j=0;

    while(A!=NULL) {
        if((i&1)==0) {
            A->val=evens[j];
            j++;
        }
        i++;
        A=A->next;
    }

    return temp1;
}
