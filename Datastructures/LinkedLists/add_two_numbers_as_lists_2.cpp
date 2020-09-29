// Add two numbers as list 
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
    ListNode* reverse(ListNode* l) {
        ListNode* curr=l;
        ListNode* prev=NULL;
        ListNode* next=NULL;

        while(curr!=NULL) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* A=reverse(l1);
        ListNode* B=reverse(l2);

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

        ListNode* res=reverse(startl->next);
        return res;

    }
};
