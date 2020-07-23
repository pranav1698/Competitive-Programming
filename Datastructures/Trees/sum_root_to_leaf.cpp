// Sum from Root to Leaf
// SlothyCoder16
// July 23, 2020

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
    int findPath(TreeNode* root, int preSum) {
        int currSum = 10 * preSum + root->val;
        if(root->left == NULL && root->right == NULL) {
            return currSum;
        }

        int leftRes = 0;
        int rightRes = 0;
        if(root->left)
            leftRes = findPath(root->left, currSum);
        if(root->right)
            rightRes = findPath(root->right, currSum);

        return leftRes + rightRes;
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int sum = findPath(root, 0);
        return sum;
    }
};
