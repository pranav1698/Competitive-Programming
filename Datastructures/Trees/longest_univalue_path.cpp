// Longest Univalue Path in Binary Tree
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
    int getLength(TreeNode* root, int count, int x) {
        if(root == NULL) return count;

        if(root->val != x) return count;

        count++;
        return max(getLength(root->left, count, x), getLength(root->right, count, x));
    }

    int UnivalueLength(TreeNode* root) {
        if(root == NULL) return 0;

        int leftRes = getLength(root->left, 0, root->val);
        int rightRes = getLength(root->right, 0, root->val);

        if(root->left && root->right) {
            if(root->left->val == root->val && root->right->val == root->val)
                return leftRes + rightRes;
        }

        return max(leftRes, rightRes);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;

        return max(max(UnivalueLength(root), longestUnivaluePath(root->left)), longestUnivaluePath(root->right));
    }
};
