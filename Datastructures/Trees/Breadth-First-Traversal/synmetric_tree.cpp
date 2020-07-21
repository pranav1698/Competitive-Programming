// Check if tree is synmetric or not
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
    bool isPalindrome(vector<string> v) {
        int n = v.size();
        bool res = true;
        for (int i = 0; i <= n / 2 && n != 0; i++) {
            if (v[i] != v[n - i - 1]) {
                res = false;
                break;
            }
        }

        return res;
    }

    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        vector<string> levels;
        if(root == NULL) return true;
        bool res = true;

        q.push(root);
        while(!q.empty()) {
            int i = q.size();

            while(i--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr) {
                    levels.push_back(to_string(curr->val));
                } else {
                    levels.push_back("null");
                }


                if(curr) {
                   if(curr->left){
                        q.push(curr->left);
                    } else {
                        q.push(NULL);
                    }

                    if(curr->right){
                        q.push(curr->right);
                    } else {
                        q.push(NULL);
                    }
                }
            }

            res = res && isPalindrome(levels);
            levels.clear();
        }

        return res;
    }
};
