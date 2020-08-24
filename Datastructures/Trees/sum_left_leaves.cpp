// Sum of left leaves using Recursion
// SlothyCoder16
// July 25, 2020

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
    int getLeftSum(TreeNode* root) {
        if(root == NULL) return 0;

        if(root->left) {
            if(root->left->left == NULL && root->left->right == NULL)
                return root->left->val + getLeftSum(root->left) + getLeftSum(root->right);
            else
                return getLeftSum(root->left) + getLeftSum(root->right);
        }


        return getLeftSum(root->right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;

        return getLeftSum(root);
    }
};
