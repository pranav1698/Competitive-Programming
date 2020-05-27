// Addition of two linked list in reverse
// SlothyCoder16
// May 27, 2020
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

    int* reverseArray(int* arr, int n) {
        int* new_arr = new int[n];
        int j=0;
        for(int i=n-1; i>=0; i--){
            new_arr[j] = arr[i];
            j++;
        }
        return new_arr;
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

    int sizeOfArray(ListNode* l1){
        int count = 0;
        while(l1 != NULL){
            count++;
            l1 = l1->next;
        }
        return count;
    }

    ListNode* arrayToList(int* arr, int n){
        ListNode* root = NULL;
        for(int i=0;i<n; i++)
            insert(&root, arr[i]);
        return root;
    }

    ListNode* getSum(int* arr1, int n1, int* arr2, int n2){
        int* arr = new int[n1+n2];
        int i=n1-1;
        int j=n2-1;
        int k=0;
        int borrow=0;
        while(i>=0 && j>=0){
            int sum = arr1[i] + arr2[j] + borrow;
            borrow=0;
            if(sum >= 10){
                arr[k] = sum - 10;
                borrow = 1;
            } else {
                arr[k] = sum + borrow;
                borrow = 0;
            }
            // cout << arr[k] << endl;
            k++;
            i--;
            j--;
        }
        while(i>=0){
            int sum = arr1[i] + borrow;
            borrow=0;
            if(sum >= 10){
                arr[k] = sum - 10;
                borrow=1;
            } else {
                arr[k] = sum + borrow;
                borrow = 0;
            }
            k++;
            i--;
        }
        while(j>=0){
            int sum = arr2[j] + borrow;
            borrow=0;
            cout << sum << endl;
            if(sum >= 10){
                arr[k] = sum - 10;
                borrow=1;
            } else {
                arr[k] = sum + borrow;
                borrow = 0;
            }
            k++;
            j--;
        }
        if(borrow!=0){
            arr[k]=borrow;
            borrow=0;
            k++;
        }
        ListNode* l = arrayToList(arr, k);
        return l;
    }



    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = sizeOfArray(l1);
        int* arr1 = listToArray(l1, n1);
        int* rarr1 = reverseArray(arr1, n1);
        int n2 = sizeOfArray(l2);
        int* arr2 = listToArray(l2, n2);
        int* rarr2 = reverseArray(arr2, n2);
        ListNode* l = getSum(rarr1, n1, rarr2, n2);


        return l;
    }
};
