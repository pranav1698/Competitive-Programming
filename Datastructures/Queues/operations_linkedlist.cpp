// Implementation if queue using LinkedList
// SlothyCoder16
// July 19, 2020

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int data;
  ListNode* next;
};

class LinkedList {
public:
  ListNode *head, *tail;

  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  void printList() {
    ListNode* ptr = this->head;

    while(ptr != NULL){
      cout << ptr->data << endl;
      ptr = ptr->next;
    }
  }

  void enqueue(int val) {
    ListNode* temp = new ListNode();
    temp->data = val;
    temp->next = NULL;

    if(this->head != NULL) {
      this->tail->next = temp;
      this->tail = this->tail->next;
    } else {
      this->head = temp;
      this->tail = temp;
    }
  }

  // o(n) operation: expensive
  // void enqueue(int val) {
  //   ListNode* temp = new ListNode();
  //   temp->data = val;
  //   temp->next = NULL;
  //   ListNode* ptr;
  //
  //   if(this->head != NULL) {
  //     ptr = this->head;
  //
  //     while(ptr->next != NULL)
  //       ptr = ptr->next;
  //
  //     ptr->next=temp;
  //     this->tail = temp;
  //   } else {
  //       this->head = temp;
  //       this->tail = temp;
  //   }
  // }

  int dequeue() {
    int res = this->head->data;
    this->head = this->head->next;
    return res;
  }

  bool isEmpty() {
    if(this->head != NULL) {
      return false;
    }

    return true;
  }
};



int main() {
  int arr[] = {1, 2, 3, 4, 5};
  LinkedList* queue = new LinkedList();

  for(int i=0; i<5; i++) {
    queue->enqueue(arr[i]);
  }

  queue->enqueue(6);

  cout << queue->dequeue() << endl;
  cout << " " << endl;

  queue->printList();

  cout << queue->isEmpty() << endl;
}
