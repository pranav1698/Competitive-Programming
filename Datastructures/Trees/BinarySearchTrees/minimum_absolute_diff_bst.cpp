// Finding minimum absolute difference in BST
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
    int diff = INT_MAX;
    int getMax(TreeNode* root) {
        if(root->right == NULL) return root->val;

        return getMax(root->right);
    }

    int getMin(TreeNode* root) {
        if(root->left == NULL) return root->val;

        return getMin(root->left);
    }

    void traverseNodes(TreeNode* root) {
        if(root == NULL) return;

        int leftRes = INT_MAX;
        int rightRes = INT_MAX;
        if(root->right)
            leftRes = abs(root->val - getMin(root->right));
        if(root->left)
            rightRes = abs(root->val - getMax(root->left));

        diff = min(min(diff, leftRes), rightRes);

        traverseNodes(root->left);
        traverseNodes(root->right);

    }

    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return 0;
        traverseNodes(root);

        return diff;
    }
};
