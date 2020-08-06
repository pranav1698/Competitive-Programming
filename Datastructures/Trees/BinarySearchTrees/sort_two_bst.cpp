// Sorting a bst after merging them
// SlothyCoder16
// August 06, 2020

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
    TreeNode* insertBST(TreeNode* root, int x) {
        if(root == NULL) {
            TreeNode* root = new TreeNode(x);
            return root;
        }

        if(root->val <= x) {
            root->right = insertBST(root->right, x);
        } else {
            root->left = insertBST(root->left, x);
        }

        return root;
    }

    void insertRoot2(TreeNode* root1,TreeNode* root2) {
        if(root2 == NULL) return;

        root1 = insertBST(root1, root2->val);
        insertRoot2(root1, root2->left);
        insertRoot2(root1, root2->right);

    }

    vector<int> inorderTraverse(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        while(!s.empty() || root!=NULL) {
            if(root != NULL) {
                s.push(root);
                root = root->left;
            } else {
                TreeNode* curr = s.top();
                res.push_back(curr->val);
                s.pop();
                root = curr->right;
            }
        }

        return res;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL) return inorderTraverse(root2);
        if(root2 == NULL) return inorderTraverse(root1);

        insertRoot2(root1, root2);
        return inorderTraverse(root1);
    }
};
