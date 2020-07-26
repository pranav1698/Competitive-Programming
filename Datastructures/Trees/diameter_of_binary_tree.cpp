// Maximum length of path in binary tree
// SlothyCoder16
// July 26, 2020

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
    int ans = INT_MIN;
    int maxHeight(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);

        ans = max(ans, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        maxHeight(root);
        return ans;
    }
};
