// Merge K sorted lists using Heap
// SlothyCoder16
// August 1, 2020

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
    void insert(ListNode** root, int x) {
        ListNode* temp = new ListNode(x);
        ListNode* ptr;

        if(*root != NULL) {
            ptr = *root;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        } else {
            *root = temp;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        vector<ListNode*>::iterator it = lists.begin();
        while(it != lists.end()) {
            ListNode* head = *it;
            while(head != NULL) {
                pq.push(head->val);
                head = head->next;
            }
            it++;
        }
        ListNode* ans = NULL;
        while(!pq.empty()) {
            insert(&ans, pq.top());
            pq.pop();
        }

        return ans;
    }
};
