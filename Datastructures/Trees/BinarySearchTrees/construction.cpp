#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node* left;
  Node* right;
};

Node* pushInBst(Node* root, int x) {
  if(root == NULL) {
    Node* temp = new Node();
    temp->key = x;
    temp->left = NULL;
    temp->right = NULL;
    root = temp;
    return root;
  }

  if(x >= root->key) {
    root->right = pushInBst(root->right, x);
  } else {
    root->left = pushInBst(root->left, x);
  }

  return root;
}

// Count nodes of a BST
int countNodes(Node* root) {
  if(root == NULL) return 0;

  return 1 + countNodes(root->left) + countNodes(root->right);
}

// Get minimum in BST
int getMin(Node* root) {
  if(root->left == NULL)
    return root->key;

  return getMin(root->left);
}

// Get Maximum in BST
int getMax(Node* root) {
  if(root->right == NULL)
    return root->key;

  return getMax(root->right);
}

// Delete node from a tree
Node* deleteNode(Node* root, int x) {
  if(root == NULL) return NULL;

  if(root->key == x) {
    if(root->left == NULL && root->right == NULL) {
      return NULL;
    } else if(root->left != NULL && root->right == NULL) {
      return root->left;
    } else if(root->left == NULL && root->right != NULL) {
      return root->right;
    } else {
      int minRight = getMin(root->right);
      root->key = minRight;
      root->right = deleteNode(root->right, minRight);
      return root;
    }
  }

  if(root->key > x) {
    root->left = deleteNode(root->left, x);
  } else if (root->key < x) {
    root->right = deleteNode(root->right, x);
  }

  return root;
}

// Search in BST for value
bool is_in_tree(Node* root, int val) {
  if(root == NULL) return false;

  if(root->key == val) return true;

  if(root->key > val) {
    return is_in_tree(root->left, val);
  }

  return is_in_tree(root->right, val);
}

// Is binary Search tree
bool bsUtil(Node* root, long int minValue, long int maxValue) {
  if(root == NULL) return true;

  if(root->key > minValue &&
    root->key < maxValue &&
    bsUtil(root->left, minValue, root->key) &&
    bsUtil(root->right, root->key, maxValue)) {
      return true;
  }

  return false;
}


// Height of BST
int height(Node* root) {
  if(root == NULL) return 0;

  return 1 + max(height(root->left), height(root->right));
}


// Inorder Traversal of BST
void inorderPrint(Node* root) {
  stack<Node*> s;

  while(!s.empty() || root!=NULL) {
    if(root != NULL) {
      s.push(root);
      root = root->left;
    } else {
      Node* curr = s.top();
      s.pop();
      cout << curr->key << endl;
      root = curr->right;
    }
  }
}



int main() {
  int arr[6] = {7,3,1,4,5,8};
  Node* root = NULL;
  for(int i=0; i<6; i++){
      root = pushInBst(root, arr[i]);
  }

  inorderPrint(root);
  cout << "Number of nodes in the tree: " << countNodes(root) << endl;
  cout << "The node 7 is in the tree: " << is_in_tree(root, 7) << endl;
  cout << "Height of the tree: " << height(root) << endl;
  cout << "The minimum element present in the tree: " << getMin(root) << endl;
  cout << "The maximum element present in the tree: " << getMax(root) << endl;
  cout << bsUtil(root, LONG_MIN, LONG_MAX) << endl;

  deleteNode(root, 3);
  cout << "After Deletion " << endl;
  inorderPrint(root);


  free(root);
}
