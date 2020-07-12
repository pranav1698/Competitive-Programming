// Construction of a baseic tree using node in C++
// SlothyCoder16
// July 12, 2020

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


int main() {
  Node* root = makeNode(4);
  root->left = makeNode(3);
  root->right = makeNode(5);
  cout << root->left->data << endl;
}
