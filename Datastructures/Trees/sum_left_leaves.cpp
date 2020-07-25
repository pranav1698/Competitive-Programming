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
    int findLeftSum(TreeNode* parent, TreeNode* node, int sum) {
        if(node->left == NULL && node->right == NULL) {
            if(node == parent->left){
                sum = sum + node->val;
                return sum;
            }
        }

        int leftSum = 0;
        int rightSum = 0;

        if(node->left)
            leftSum = findLeftSum(node, node->left, sum);
        if(node->right)
            rightSum = findLeftSum(node, node->right, sum);

        return leftSum + rightSum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;

        if(root->left == NULL && root->right == NULL)
            return 0;

        return findLeftSum(NULL, root, 0);
    }
};
