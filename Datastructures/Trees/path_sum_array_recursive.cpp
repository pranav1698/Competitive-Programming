// Finding path in binary tree (root to leaf) for finding required sum
// SlothyCoder16
// July 23, 2020

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
    vector<TreeNode*> findPath(TreeNode* root, vector<TreeNode*> res, int sum) {
        if(root->left == NULL && root->right == NULL) {
            if((sum - root->val) == 0) {
                res.push_back(root);
                return res;
            } else {
                res.clear();
                return res;
            }
        } else {
            res.push_back(root);
        }

        vector<TreeNode*> leftRes;
        vector<TreeNode*> rightRes;
        if(root->left)
            leftRes = findPath(root->left, res, sum - root->val);
        if(root->right)
            rightRes = findPath(root->right, res, sum - root->val);

        res.clear();
        if(!leftRes.empty()){
            for(int i=0; i<leftRes.size(); i++)
                res.push_back(leftRes[i]);
        }
        if(!rightRes.empty()){
            for(int i=0; i<rightRes.size(); i++)
                res.push_back(rightRes[i]);
        }

        return res;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;

        if(root==NULL) return res;
        vector<TreeNode*> treeRes;
        treeRes = findPath(root, treeRes, sum);

        vector<int> branches;
        for(int i=0; i<treeRes.size(); i++){
            while(treeRes[i]->left != NULL || treeRes[i]->right != NULL){
                branches.push_back(treeRes[i]->val);
                i++;
            }
            branches.push_back(treeRes[i]->val);
            res.push_back(branches);
            branches.clear();
        }


        return res;
    }
};
