// Finding maximum of house robbers loot using recursion
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
    int rob(TreeNode* root) {
        if(root == NULL) return 0;

        int option1 = 0;
        if(root->left)
            option1 = option1 + rob(root->left->left) + rob(root->left->right);
        if(root->right)
            option1 = option1 + rob(root->right->left) + rob(root->right->right);
        option1 = option1 + root->val;

        int option2 = rob(root->left) + rob(root->right);
        int ans = max(option1, option2);

        return ans;
    }
};
