// Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        vector<int> levels;
        int count = 0;
        int i;
        if(root == NULL) return res;

        q.push(root);
        while(!q.empty()){
            i = q.size();

            while(i--) {
                TreeNode* curr = q.front();
                q.pop();
                levels.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            count++;
            if((count & 1) == 0) {
                reverse(levels.begin(), levels.end());
                res.push_back(levels);
            } else {
                res.push_back(levels);
            }

            levels.clear();
        }

        return res;
    }
};
