// Merge k sorted lists
// SlothyCoder16
// May 27, 2020
// 
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
    int* listToArray(ListNode* l, int size){
        int* arr = new int[size];
        int i=0;
        while(l != NULL){
            arr[i] = l->val;
            i++;
            l=l->next;
        }
        return arr;
    }

    int sizeOfArray(ListNode* l1){
        int count = 0;
        while(l1 != NULL){
            count++;
            l1 = l1->next;
        }
        return count;
    }

    void insert(ListNode** root, int item){
        ListNode* temp = new ListNode;
        ListNode* ptr;
        temp->val = item;
        temp->next = NULL;

        if(*root == NULL){
            *root = temp;
        } else {
            ptr = *root;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }

    ListNode* arrayToList(int* arr, int n){
        ListNode* root = NULL;
        for(int i=0;i<n; i++)
            insert(&root, arr[i]);
        return root;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int n1 = sizeOfArray(l1);
        int* arr1 = listToArray(l1, n1);
        int n2 = sizeOfArray(l2);
        int* arr2 = listToArray(l2, n2);
        int* arr = new int[n1 + n2];
        int k=0;
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(arr1[i] <= arr2[j]){
                arr[k] = arr1[i];
                i++;
                k++;
            } else {
                arr[k] = arr2[j];
                j++;
                k++;
            }
        }

        while(i<n1){
            arr[k] = arr1[i];
            k++;
            i++;
        }

        while(j<n2){
            arr[k] = arr2[j];
            k++;
            j++;
        }

        ListNode* l = arrayToList(arr, k);
        return l;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l = arrayToList(new int[0], 0);
        for(int i=0; i<lists.size(); i++){
             l = mergeTwoLists(l, lists[i]);
        }
        return l;
    }
};
