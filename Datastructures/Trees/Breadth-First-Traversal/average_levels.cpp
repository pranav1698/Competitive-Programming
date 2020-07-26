// Finding average of levels in a binary tree
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;

        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int i = q.size();
            int size = q.size();
            double sum = 0;

            while(i--) {
                TreeNode* curr = q.front();
                q.pop();
                sum = sum + curr->val;

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            res.push_back(sum / size);
        }

        return res;
    }
};
