// Insertion Sort on LinkedList
// SlothyCoder16
// August 09, 2020

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
    struct Node {
        int key;
        Node* next;
        Node* back;
    };

    void swap(Node* a, Node* b) {
        int temp = a->key;
        a->key = b->key;
        b->key = temp;
    }

    Node* newNode(int x) {
        Node* temp = new Node();
        temp->key = x;
        temp->next = NULL;
        temp->back = NULL;

        return temp;
    }

    void push(Node** root, int x) {
        Node* temp = newNode(x);
        Node* ptr;

        if(*root != NULL) {
            ptr = *root;
            while(ptr->next != NULL)
                ptr = ptr->next;
            temp->back = ptr;
            ptr->next = temp;
        } else {
            *root=temp;
        }
    }

    void pushList(ListNode** head, int x) {
        ListNode* temp = new ListNode(x);
        ListNode* ptr;

        if(*head != NULL) {
            ptr = *head;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        } else {
            *head = temp;
        }
    }

    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;

        Node* root = NULL;
        while(head != NULL) {
            push(&root, head->val);
            head = head->next;
        }

        Node* ptr1 = root;
        Node* ptr2 = NULL;
        while(ptr1->next != NULL) {
            ptr2 = ptr1->next;
            while(ptr2->back != NULL) {
                if(ptr2->key < ptr2->back->key){
                    swap(ptr2, ptr2->back);
                }
                ptr2 = ptr2->back;
            }
            ptr1 = ptr1->next;
        }

        while(ptr2 != NULL){
            pushList(&head, ptr2->key);
            ptr2 = ptr2->next;
        }

        return head;
    }
};
