// Sorting two BST using Merge Sort
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
    void inorderTraverse(vector<int> &res,TreeNode* root) {
        stack<TreeNode*> s;

        while(!s.empty() || root!=NULL) {
            if(root!=NULL) {
                s.push(root);
                root= root->left;
            } else {
                TreeNode* curr = s.top();
                s.pop();
                res.push_back(curr->val);
                root = curr->right;
            }
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> res;
        int i=0;
        inorderTraverse(res, root1);
        int mid = res.size();
        int j = res.size();
        inorderTraverse(res, root2);
        int high = res.size();

        while(i<mid && j<high) {
            if(res[i] <= res[j]){
                ans.push_back(res[i]);
                i++;
            } else {
                ans.push_back(res[j]);
                j++;
            }
        }

        while(i<mid) {
            ans.push_back(res[i]);
            i++;
        }

        while(j<high) {
            ans.push_back(res[j]);
            j++;
        }

        return ans;
    }
};
