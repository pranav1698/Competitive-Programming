#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
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

// Iterative Postorder Traversal
void postorderTraversal(Node* root) {
  stack<Node*> s;
  stack<Node*> out;

  s.push(root);
  while(!s.empty()) {
    Node* curr = s.top();
    s.pop();
    out.push(curr);

    if(curr->left)
      s.push(curr->left);
    if(curr->right)
      s.push(curr->right);
  }

  while(!out.empty()){
    cout << out.top()->data << endl;
    out.pop();
  }
}

// Iterative Preorder Traversal
void preorderTraversal(Node* root) {
  stack<Node*> s;

  while(!s.empty() || root!=NULL) {
    if(root != NULL) {
      cout << root->data << endl;
      s.push(root);
      root = root->left;
    } else {
      root = s.top()->right;
      s.pop();
    }
  }
}

// Iterative Inorder Traversal
void inorderTraversal(Node* root) {
  stack<Node*> s;

  while(!s.empty() || root!=NULL) {
    if(root != NULL) {
      s.push(root);
      root = root->left;
    } else {
      cout << s.top()->data << endl;
      root = s.top()->right;
      s.pop();
    }
  }
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
