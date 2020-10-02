// Return from the mid of linked list
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
    ListNode* middleNode(ListNode* head) {
        int N=0;
        ListNode* curr=head;
        while(curr) {
            N++;
            curr=curr->next;
        }

        int mid=N/2;
        curr=head;
        int i=1;
        while(i<=mid) {
            i++;
            curr=curr->next;
        }

        return curr;
    }
};
