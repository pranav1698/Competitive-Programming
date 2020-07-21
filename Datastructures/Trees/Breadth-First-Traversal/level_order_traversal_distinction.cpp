// Iterative Level Order Traversal with array distinction
// SlothyCoder16
// July 21, 2020

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        vector<int> levels;

        if(root == NULL)
            return res;

        q.push(root);
        while(!q.empty()) {
            int i= q.size();

            while(i--) {
                TreeNode* curr = q.front();
                q.pop();
                levels.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            res.push_back(levels);
            levels.clear();
        }

        return res;
    }
};
