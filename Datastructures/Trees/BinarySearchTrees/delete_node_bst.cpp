// Delete node in a BST
// SlothyCoder16
// July 29, 2020

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMin(TreeNode* root) {
        if(root->left == NULL)
            return root->val;

        return getMin(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key) {
            if(root->left == NULL && root->right == NULL) {
                return NULL;
            } else if(root->left != NULL && root->right == NULL) {
                return root->left;
            } else if(root->left == NULL && root->right != NULL) {
                return root->right;
            } else {
                int inorderSuccessor = getMin(root->right);
                root->val = inorderSuccessor;
                root->right = deleteNode(root->right, inorderSuccessor);
                return root;
            }
        }

        if(root->val > key){
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};
