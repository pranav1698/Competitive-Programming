#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node* next;
};

Node* newNode (int x) {
  Node* temp = new Node();
  temp->key = x;
  temp->next = NULL;

  return temp;
}

void push(Node** head, int x) {
  Node* temp = newNode(x);
  Node* ptr;

  if(*head != NULL) {
    ptr = *head;
    while(ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = temp;
  } else {
    *head = temp;
  }
}

void printList(Node* head) {
  while(head != NULL) {
    cout << head->key << endl;
    head = head->next;
  }
}

Node* Merge(Node* a, Node* b) {
  if(a == NULL) {
    return b;
  } else if(b == NULL) {
    return a;
  }

  Node* res = NULL;
  if(a->key <= b->key) {
    res = a;
    res->next = Merge(a->next, b);
  } else {
    res = b;
    res->next = Merge(a, b->next);
  }

  return res;
}

void SplitList(Node* head, Node** startFront, Node** startBack) {
  Node* slow = head;
  Node* fast = head->next;

  while(fast != NULL) {
    fast = fast->next;
    if(fast != NULL) {
      slow = slow->next;
      fast = fast->next;
    }
  }

  *startFront = head;
  *startBack = slow->next;
  slow->next = NULL;
}

void MergeSort(Node** headR) {
  Node* head = *headR;
  Node* a;
  Node* b;

  if(head == NULL || head->next == NULL)
    return;

  SplitList(head, &a, &b);

  MergeSort(&a);
  MergeSort(&b);

  *headR = Merge(a, b);
}



int main() {
  Node* head = NULL;

  push(&head, 40);
  push(&head, 20);
  push(&head, 60);
  push(&head, 10);
  push(&head, 50);
  push(&head, 30);

  MergeSort(&head);

  printList(head);
}
