// Partition a list to get numbers above a given node
// SlothyCoder16
// September 28, 2020

// O(N) space solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    vector<int> greater;
    vector<int> smaller;
    ListNode* temp=A;
    while(temp!=NULL) {
        if(temp->val >= B) greater.push_back(temp->val);
        else smaller.push_back(temp->val);
    }

    ListNode* temp1=A;
    for(int i=0; i<smaller.size(); i++) {
        A->val=smaller[i];
        A=A->next;
    }

    for(int i=0; i<greater.size(); i++) {
        A->val=greater[i];
        A=A->next;
    }

    return temp1;
}


// O(1) space solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* l1=new ListNode(0);
    ListNode* l2=new ListNode(0);

    ListNode* start1=l1;
    ListNode* start2=l2;

    while(A!=NULL) {
        if(A->val < B) {
            l1->next=A;
            l1=l1->next;
            A=A->next;
        } else {
            l2->next=A;
            l2=l2->next;
            A=A->next;
        }
    }

    l2->next=NULL;
    l1->next=start2->next;

    return start1->next;

}
