// Finding maximum in a row for a tree using BFS
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;

        if(root == NULL) return res;

        q.push(root);
        while(!q.empty()) {
            int i = q.size();
            int maxRow = INT_MIN;

            while(i--) {
                TreeNode* curr = q.front();
                q.pop();

                maxRow = max(maxRow, curr->val);

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            res.push_back(maxRow);
        }

        return res;
    }
};
