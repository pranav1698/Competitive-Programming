// Kth smallest element in the BST
// SlothyCoder16
// July 31, 2020

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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;

        int res;
        priority_queue<int, vector<int>, greater<int>> pq;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            pq.push(curr->val);

            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }

        int i=0;
        while(i != k) {
            res = pq.top();
            pq.pop();
            i = i+1;
        }

        return res;
    }
};
