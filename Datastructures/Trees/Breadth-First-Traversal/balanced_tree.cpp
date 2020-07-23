// Finding if tree is balanced or not
// SlothyCoder16
// July 22, 2020

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
    int findHeight(TreeNode* root) {
        if(root == NULL)
            return 0;

        return 1 + max(findHeight(root->left), findHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == NULL) return true;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            int leftHeight = findHeight(curr->left);
            int rightHeight = findHeight(curr->right);

            if(abs(leftHeight-rightHeight) > 1)
                return false;

            if(curr->left){
                q.push(curr->left);
            }

            if(curr->right)
                q.push(curr->right);
        }

        return true;
    }
};
