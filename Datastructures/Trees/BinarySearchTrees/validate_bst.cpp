// Finding if given BST is BST or not
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
    bool bsUtil(TreeNode* root, long int minValue, long int maxValue) {
        if(root == NULL) return true;

        if(root->val > minValue &&
           root->val < maxValue &&
           bsUtil(root->left, minValue, root->val) &&
           bsUtil(root->right, root->val, maxValue)) {
            return true;
        }

        return false;
    }

    bool isValidBST(TreeNode* root) {
        return bsUtil(root, LONG_MIN, LONG_MAX);
    }
};
