// Constructing binary tree from preorder and inorder arrays
// SlothyCoder16
// July 24, 2020

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
    TreeNode* buildTraverseTree(vector<int> preorder, int preStart, int preEnd, map<int, int> m, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = m[preorder[preStart]];
        int numsLeft = inRoot - inStart;

        root->left = buildTraverseTree(preorder, preStart + 1, preStart + numsLeft, m, inStart, inRoot-1);
        root->right = buildTraverseTree(preorder, preStart + numsLeft + 1, preEnd, m, inRoot + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m;
        for(int i=0; i<inorder.size(); i++) {
            m[inorder[i]] = i;
        }
        TreeNode* root = buildTraverseTree(preorder, 0, preorder.size()-1, m, 0, inorder.size() - 1);
        return root;
    }
};
