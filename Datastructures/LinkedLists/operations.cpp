// Operations on a Linked List
// SlothyCoder16
// May 28, 2020

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

// Push Back
void pushBack(ListNode** root, int val){
    ListNode* temp = new ListNode();
    ListNode* ptr;
    temp->val = val;
    temp->next = NULL;

    if(*root != NULL) {
        ptr = *root;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    } else {
        *root = temp;
    }
}

void printList(ListNode* root){
    while(root != NULL){
        cout << root->val << endl;
        root = root->next;
    }
}

ListNode* arrayToList(int* arr, int n){
    ListNode* root = NULL;
    for(int i=0; i<n; i++)
        pushBack(&root, arr[i]);
    return root;
}

// Size()
int size(ListNode* root) {
    int count = 0;
    while(root != NULL){
        count++;
        root = root->next;
    }
    return count;
}

//Empty()
bool empty(ListNode* root){
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

// Value at Index
int valueAtIndex(ListNode* root, int index) {
    int i=0;
    if(empty(root))
        return -1;
    while(root != NULL){
        if(i == (index-1)){
            return root->val;
        }
        root = root->next;
        i++;
    }
    return -1;
}

// Push Front
void pushFront(ListNode** root, int  val){
    ListNode* temp = new ListNode;
    temp->val = val;
    temp->next = *root;
    *root = temp;
}

// Pop Front
int popFront(ListNode** root) {
    int val = (*root)->val;
    *root = (*root)->next;
    return val;
}

// front
int front(ListNode* root) {
    return root->val;
}

// Back
int back(ListNode** root){
    ListNode* ptr = *root;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    int val = ptr->val;
    ptr = NULL;
    return val;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    ListNode* l = arrayToList(arr, 5);
    cout << size(l) << endl;
    cout << empty(l) << endl;
    cout << "value " << valueAtIndex(l, 1) << endl;
    pushFront(&l, 0);
    cout << "popped value " << popFront(&l) << endl;
    pushBack(&l, 6);
    cout << "back " << back(&l) << endl;
    cout << "front " << front(l) << endl;
    printList(l);
}
