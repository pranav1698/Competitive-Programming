// Finding binary paths of a tree (root to leaf) using recursion
// SlothyCoder16
// July 25, 2020

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
    string binaryTreeStrings(TreeNode* root, vector<string> &res, string path) {
        if(root->left == NULL && root->right == NULL) {
            path = path + "->";
            path = path + to_string(root->val);
            return path;
        }

        if(path == "") {
            path = path + to_string(root->val);
        } else {
            path = path + "->";
            path = path + to_string(root->val);
        }

        string leftRes = "";
        string rightRes = "";
        if(root->left)
            leftRes = binaryTreeStrings(root->left, res, path);
        if(root->right)
            rightRes = binaryTreeStrings(root->right, res, path);

        if(leftRes.size() != 0)
            res.push_back(leftRes);
        if(rightRes.size() != 0)
            res.push_back(rightRes);

        path = "";
        return path;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;

        if(root->left == NULL && root->right == NULL){
            res.push_back(to_string(root->val));
        } else {
            string path =  binaryTreeStrings(root, res, "");
        }

        return res;
    }
};
