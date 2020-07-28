// Construction of a baseic tree node using node in C++
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

bool is_in_tree(Node* root, int val) {
  if(root == NULL)
    return false;

  if(root->data == val)
    return true;

  return is_in_tree(root->left, val) || is_in_tree(root->right, val);
}


int main() {
  Node* root = makeNode(4);
  root->left = makeNode(3);
  root->right = makeNode(5);
  cout << root->left->data << endl;

  cout << is_in_tree(root, 6) << endl;
}
