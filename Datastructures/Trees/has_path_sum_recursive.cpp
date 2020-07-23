// Recursive implementation for has path sum (root to leaf)
// SlothyCoder16
// July 22, 2020

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
   bool hasPathSum(TreeNode* root, int n) {
        if(root == NULL) return false;

        if(root->left == NULL && root->right == NULL) {
            if((n - root->val) == 0){
                return true;
            } else {
                return false;
            }
        }

         bool leftRes = hasPathSum(root->left, n - root->val);
         bool rightRes = hasPathSum(root->right, n - root->val);

        return leftRes || rightRes;
    }
};
