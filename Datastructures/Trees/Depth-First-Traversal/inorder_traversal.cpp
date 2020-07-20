// Inorder traversal of tree nodes
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        while(!s.empty() || root!=NULL) {
            if(root != NULL) {
                s.push(root);
                root = root->left;
            } else {
                res.push_back(s.top()->val);
                root = s.top()->right;
                s.pop();
            }
        }

        return res;
    }
};
