// Finding out tilt of a binary tree using Recursion
// SlothyCoder16
// July 26,2020

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
    int ans = 0;
    int findTiltValue(TreeNode* root) {
        if(root == NULL)
            return 0;

        int leftSum = 0;
        int rightSum = 0;

        if(root->left)
            leftSum = root->left->val + findTiltValue(root->left);
        if(root->right)
            rightSum = root->right->val + findTiltValue(root->right);

        ans = ans + abs(leftSum - rightSum);

        return leftSum + rightSum;
    }


    int findTilt(TreeNode* root) {
        findTiltValue(root);
        return ans;
    }
};
