// DFS Inorder Traversal on binary tree
// SlothyCoder16
// July 20, 2020

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

Node* makeNode(int val) {
  Node* root = new Node();
  root->data = val;
  root->left = NULL;
  root->right = NULL;

  return root;
}

Node* createTree(vector<int> v, Node* root, int index) {
  if(index >= v.size())
    return root;

  Node* temp = makeNode(v[index]);
  root = temp;

  root->left = createTree(v, root->left, 2*index + 1);
  root->right = createTree(v, root->right, 2*index + 2);

  return root;
}

// Postorder Traversal Recursive
void postorderTraversal(Node* root) {
  if(root == NULL)
    return;

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << endl;
}


// Preorder Traversal Recursive
void preorderTraversal(Node* root) {
  if(root == NULL)
    return;

  cout << root->data << endl;
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


// Inorder Traversal Recursive
void inorderTraversal(Node* root) {
  if(root == NULL)
    return;

  inorderTraversal(root->left);
  cout << root->data << endl;
  inorderTraversal(root->right);
}

int main() {
  vector<int> v{1,2,3,4,5,6};
  Node* root;
  root = createTree(v, root, 0);
  // cout << root->right->data << endl;

  cout << "Inorder Traversal: " << endl;
  inorderTraversal(root);

  cout << "Preorder Traversal: " << endl;
  preorderTraversal(root);

  cout << "Postorder Traversal: " << endl;
  postorderTraversal(root);
}
