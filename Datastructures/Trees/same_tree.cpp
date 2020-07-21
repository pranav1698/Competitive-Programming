// Finding if two tree is same or nto
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        if(p == NULL || q == NULL) {
            if(p == NULL && q == NULL) {
                return true;
            } else {
                return false;
            }
        }

        q1.push(p);
        q2.push(q);

        while(!q1.empty() || !q2.empty()) {
            TreeNode* curr1 = q1.front();
            TreeNode* curr2 = q2.front();
            q1.pop();
            q2.pop();

            if(curr1 == NULL || curr2 == NULL) {
                if(curr1 == NULL && curr2 == NULL) {
                    // do nothing
                } else {
                    return false;
                }
            } else {
                if(curr1->val != curr2->val)
                    return false;
            }

            if(curr1) {
                if(curr1->left){
                    q1.push(curr1->left);
                } else {
                    q1.push(NULL);
                }
                if(curr1->right) {
                    q1.push(curr1->right);
                } else {
                    q1.push(NULL);
                }
            }

            if(curr2) {
                if(curr2->left){
                    q2.push(curr2->left);
                } else {
                    q2.push(NULL);
                }
                if(curr2->right) {
                    q2.push(curr2->right);
                } else {
                    q2.push(NULL);
                }
            }

        }

        return true;
    }
};
