// Odd Even Linked List
// SlothyCoder16
// October 02, 2020

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* l1=new ListNode(0);
        ListNode* l2=new ListNode(0);

        ListNode* startl1=l1;
        ListNode* startl2=l2;

        while(head) {
            l1->next=head;
            l2->next=head->next;
            l1=l1->next;
            l2=l2->next;
            if(head->next) head=head->next->next;
            else head=head->next;
        }

        if(l2) l2->next=NULL;
        l1->next=startl2->next;
        return startl1->next;
    }
};
