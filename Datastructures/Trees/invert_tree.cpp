// Inverting binary tree using recursion
// SlothyCoder16
// July 24, 2020

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
    TreeNode* makeNode(TreeNode* root) {
        if(root == NULL)
            return NULL;

        TreeNode* ans = new TreeNode(root->val);
        ans->left = makeNode(root->right);
        ans->right = makeNode(root->left);

        return ans;
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode* res;
        res = makeNode(root);
        return res;
    }
};
