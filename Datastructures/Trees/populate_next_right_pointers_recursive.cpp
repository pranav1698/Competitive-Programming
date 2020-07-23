// Populating next right pointers for Perfect Binary Tree using Recursion
// SlothyCoder16
// July 23, 2020

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void populateNext(Node* node, Node* parent) {
        if(node == NULL)
            return;

        if(parent == NULL){
            node->next = NULL;
        } else {
            if(node == parent->left)
                node->next = parent->right;
            if(node == parent->right)
                node->next = (parent->next ? parent->next->left : parent->next);
        }

        populateNext(node->left, node);
        populateNext(node->right, node);
    }

    Node* connect(Node* root) {
        if(root == NULL) return root;
        populateNext(root, NULL);
        return root;

    }
};
