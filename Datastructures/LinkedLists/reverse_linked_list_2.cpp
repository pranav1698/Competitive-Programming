// Reverse a linked list 2
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(head==NULL || head->next==NULL) return head;
      ListNode* temp=head;

      int i=1;
      while(i<(m-1) && temp) {
          i++;
          temp=temp->next;
      }

      ListNode* curr;
      if(m==1) curr=temp;
      else curr=temp->next;
      ListNode* prev=NULL;
      ListNode* next=NULL;

      i=0;
      while(i<=(n-m) && curr!=NULL) {
          next=curr->next;
          curr->next=prev;
          prev=curr;
          curr=next;
          i++;
      }

      ListNode* a=prev;
      while(prev->next!=NULL) prev=prev->next;
      if(next) prev->next=next;
      if(m==1) return a;
      temp->next=a;

      return head;
    }
};
