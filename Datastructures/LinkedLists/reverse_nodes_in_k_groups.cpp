// Reverse Nodes in K groups
// SlothyCoder16
// September 29, 2020

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, int k, int rem) {
        if(rem<k) return head;

        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        int N=0;
        while(N<k && curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            N++;
        }

        if(next) {
            head->next = reverse(next, k, rem-k);
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int N=0;
        ListNode* temp=head;

        while(temp!=NULL) {
            N++;
            temp=temp->next;
        }

        return reverse(head, k, N);
    }
};
