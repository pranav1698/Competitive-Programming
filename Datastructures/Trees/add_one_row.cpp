// Adding one row using binary tree
// SlothyCoder16
// July 27, 2020

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
    void dfs(TreeNode* root, int v, int d) {
        if(root == NULL)
            return;

        if(d == 2) {
            TreeNode* newLeft = new TreeNode(v);
            TreeNode* newRight = new TreeNode(v);
            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;
        } else {
            dfs(root->left, v, d-1);
            dfs(root->right, v, d-1);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        } else {
            dfs(root, v, d);
        }

        return root;
    }
};
