// Implementation of post order traversal 
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        stack<TreeNode*> out;
        vector<int> res;

        s.push(root);
        while(!s.empty()) {
            if(s.top() == NULL)
                break;

            TreeNode* curr = s.top();
            out.push(curr);
            s.pop();

            if(curr->left)
                s.push(curr->left);

            if(curr->right)
                s.push(curr->right);
        }

        while(!out.empty()){
            res.push_back(out.top()->val);
            out.pop();
        }

        return res;
    }
};
