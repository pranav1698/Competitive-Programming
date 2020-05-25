// Remove N node from end
// SlothyCoder16
// May 25, 2020

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
    int sizeOfList(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = sizeOfList(head);
        int toRemove = size-n;
        ListNode* root = head;
        if(toRemove == 0){
            head = head->next;
        } else {
            int count = 1;
            while(count < toRemove){
                root=root->next;
                count++;
            }
            root->next = (root->next)->next;
        }
        return head;
    }
};
