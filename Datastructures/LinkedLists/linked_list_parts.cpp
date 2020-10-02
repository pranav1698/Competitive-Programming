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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int N=0;
        ListNode* curr=root;
        while(curr!=NULL) {
            N++;
            curr=curr->next;
        }

        vector<ListNode*> res(k);

        curr=root;
        int i,p,j=0;
        ListNode* l;
        ListNode* startl;
        while(N && curr) {
            p=ceil((float)N/k);
            i=1;
            l=new ListNode(0);
            startl=l;
            while(i<=p && curr) {
                l->next=curr;
                l=l->next;
                i++;
                curr=curr->next;
            }
            l->next=NULL;
            res[j]=startl->next;
            j++;
            N-=p;
            k--;
        }

        return res;
    }
};
