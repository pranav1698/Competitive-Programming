// Implementation if queue using Fiexed Sized Arrays
// SlothyCoder16
// July 19, 2020

#include <bits/stdc++.h>
using namespace std;

class Queue {
public:
  int read, write;
  int queue[7];

  Queue() {
    read = 0;
    write = 0;
  }

  void printList() {
    for(int i=read; i<write; i++)
      cout << queue[i] << endl;
  }

  void enqueue(int val) {
    if((write-read) > 1) {
      this->queue[write] = val;
      write = (write + 1) % 7;
    } else if(read == 0){
      this->queue[write] = val;
      write = (write + 1) % 7;
    } else {
        cout << "Cannot add size full!!" << endl;
    }
  }

  int dequeue() {
    int res = queue[read];
    read = (read + 1) % 7;
    return res;
  }

  bool isEmpty() {
    if(read >= write) {
      return true;
    }

    return false;
  }
};

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  Queue* queue = new Queue();

  for(int i=0; i<5; i++) {
    queue->enqueue(arr[i]);
  }

  queue->enqueue(6);

  cout << queue->dequeue() << endl;
  cout << " " << endl;

  queue->printList();

  cout << queue->isEmpty() << endl;
}
