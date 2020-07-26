// Construct srting from binary tree using preorder traversal with following pattern
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
    string preTreeString(TreeNode* parent, TreeNode* node) {
        if(node == NULL) {
            if(node == parent->left) {
                if(parent->right) {
                    return "()";
                } else {
                    return "";
                }
            } else {
                return "";
            }
        }

        string ans="";
        if(parent == NULL){
            ans = to_string(node->val);
        } else {
            ans = "(" + to_string(node->val);
        }
        string leftString = preTreeString(node, node->left);
        string rightString = preTreeString(node, node->right);

        if(parent == NULL)
            return ans + leftString + rightString;

        return ans + leftString + rightString + ")";
    }

    string tree2str(TreeNode* t) {
        if(t == NULL) return "";
        return preTreeString(NULL, t);
    }
};
