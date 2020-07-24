// Finding right hand sides nodes of only a binary tree
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* rightMost = NULL;

        while(!q.empty()) {
            int i = q.size();
            while(i--) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

                rightMost = curr;
            }
            res.push_back(rightMost->val);

        }



        return res;
    }
};
