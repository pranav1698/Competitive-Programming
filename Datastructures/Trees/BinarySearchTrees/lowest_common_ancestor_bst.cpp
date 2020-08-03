// Finding Lowest Common Ancestor of two nodes using recursion
// SlothyCoder16
// August 03, 2020

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isInSubtree(TreeNode* root, int x) {
        if(root == NULL) return false;

        if(root->val == x) return true;

        if(root->val < x)
            return isInSubtree(root->right, x);

        return isInSubtree(root->left, x);
    }

    TreeNode* getParent(TreeNode* parent, TreeNode* root, int x) {
        if(root == NULL) return NULL;

        if(root->val == x) return parent;

        if(root->val < x)
            return getParent(root, root->right, x);

        return getParent(root, root->left, x);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val == q->val)
            return p;

        if(isInSubtree(p, q->val)) {
            return p;
        } else if( isInSubtree(q, p->val)) {
            return q;
        }

        TreeNode* p_parent = getParent(NULL, root, p->val);
        TreeNode* q_parent = getParent(NULL, root, q->val);

        return lowestCommonAncestor(root, p_parent, q_parent);

    }
};
