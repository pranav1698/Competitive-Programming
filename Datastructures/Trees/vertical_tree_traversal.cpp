// Vertical Traversal for nodes 
// SlothyCoder16
// August 07, 2020

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
    void findCombinations(vector<vector<int>> &res, TreeNode* node, int X, int Y) {
        if(node == NULL) return;

        res.push_back({node->val, X, Y});
        findCombinations(res, node->left, X-1, Y-1);
        findCombinations(res, node->right, X+1, Y-1);

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        findCombinations(res, root, 0, 0);

        sort(res.begin(), res.end(), [](const vector<int> &f, vector<int> &s) {
            if(f[1] == s[1] && f[2] == s[2]) return f[0] < s[0];
            if(f[1] == s[1]) return f[2] > s[2];

            return f[1] < s[1];
        });


        vector<vector<int>> ans;
        for(int i=0; i<res.size();) {
            vector <int> aux;
            do aux.push_back(res[i++][0]); while (i<res.size() and res[i][1] == res[i-1][1]);
            ans.push_back(aux);
        }

        return ans;
    }
};
