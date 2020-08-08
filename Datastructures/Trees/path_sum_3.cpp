// Find required sum in binary tree
// SlothyCoder16
// August 08, 2020

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
    int getCount(TreeNode* root, int sum) {
        if(root == NULL) return 0;

        if(sum == root->val){
            return 1 + getCount(root->left, sum - root->val) + getCount(root->right, sum - root->val);
        }

        int leftRes = getCount(root->left, sum - root->val);
        int rightRes = getCount(root->right, sum - root->val);

        return leftRes + rightRes;
    }

    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;

        return getCount(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
