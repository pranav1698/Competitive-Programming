// Finding Sum of nodes in BST range
// SlothyCoder16
// August 18, 2020

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
    int getSum(TreeNode* root, int L, int R) {
        if(root == NULL) return 0;


        if(root->val < L) {
            return getSum(root->right, L, R);
        } else if(root->val > R) {
            return getSum(root->left, L, R);
        }

        return root->val + getSum(root->right, L, R) + getSum(root->left, L, R);
    }

    int rangeSumBST(TreeNode* root, int L, int R) {
        return getSum(root, L, R);
    }
};
