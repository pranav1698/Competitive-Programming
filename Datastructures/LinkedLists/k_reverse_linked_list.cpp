// Reversing the list k at a time
// SlothyCoder16
// September 28, 2020


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void insert(ListNode** root, int x) {
    ListNode* temp = new ListNode(x);
    ListNode* ptr = *root;

    if(*root != NULL) {
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
    } else {
        *root=temp;
    }
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    vector<int> arr;
    while(A!=NULL) {
        arr.push_back(A->val);
        A=A->next;
    }

    int i=0;
    int j=B-1;
    while(i<arr.size() && j<arr.size()) {
        reverse(arr.begin()+i, arr.begin()+j+1);
        i=i+B;
        j=j+B;
    }

    ListNode* root = NULL;
    for(int i=0; i<arr.size(); i++) insert(&root, arr[i]);

    return root;
}
