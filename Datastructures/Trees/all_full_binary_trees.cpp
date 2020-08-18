// Given the number of nodes, find the the number of possible binary trees
// SlothyCoder16
// August 18, 2020

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
    unordered_map<int, vector<TreeNode*>> umap;

    vector<TreeNode*> allPossibleFBT(int N) {
        if(umap[N].size() == 0) {
            vector<TreeNode*> ans;

            if(N==1) {
                ans.push_back(new TreeNode(0));
            } else if((N & 1) == 0) {
                return ans;
            } else {
                for(int nodes_left = 1; nodes_left<N; nodes_left++) {
                    int nodes_right = N - 1 - nodes_left;
                    // traversing for all left nodes with values nodes_left
                    for(auto left: allPossibleFBT(nodes_left)) {
                        for(auto right: allPossibleFBT(nodes_right)) {
                            TreeNode* bns = new TreeNode(0);
                            bns->left = left;
                            bns->right = right;
                            ans.push_back(bns);
                        }
                    }
                }
            }


            umap[N] = ans;
        }

        return umap[N];
    }
};
