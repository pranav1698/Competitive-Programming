// Iterative Level Order Traversal
// SlothyCoder16
// July 21, 2020

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int val) {
  Node* root = new Node();
  root->data = val;
  root->left = NULL;
  root->right = NULL;

  return root;
}

Node* createTree(vector<int> v, Node* root, int index) {
  if(index >= v.size())
    return root;

  Node* temp = createNode(v[index]);
  root = temp;

  root->left = createTree(v, root->left, 2*index + 1);
  root->right = createTree(v, root->right, 2*index + 2);

  return root;
}

// Level Order Iterative
void levelOrder(Node* root) {
  queue<Node*> q;
  q.push(root);

  while(!q.empty()) {
    Node* curr = q.front();
    q.pop();
    cout << curr->data << endl;

    if(curr->left)
      q.push(curr->left);

    if(curr->right)
      q.push(curr->right);
  }
}

int main() {
  vector<int> v{1,2,3,4,5,6};
  Node* root;
  root = createTree(v, root, 0);

  // Level Order Traversal
  levelOrder(root);
}
