// Construction of a basic binary tree using tree nodes in C++
// SlothyCoder16
// July , 2020

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

Node* makeNode(int key) {
  Node* new_node = new Node();
  new_node->data = key;

  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

Node* depthOrder(int* arr, Node* root, int index, int n) {
  if(index >= n)
    return root;

  Node* temp = makeNode(arr[index]);
  root = temp;

  root->left = depthOrder(arr, root->left, 2*index+1, n);
  root->right = depthOrder(arr, root->right, 2*index+2, n);

  return root;
}


int main() {
  int arr[6] = {1,2,3,4,5,6};
  Node* root;
  root = depthOrder(arr, root, 0, 6);

  cout << root->left->data << endl;

}
