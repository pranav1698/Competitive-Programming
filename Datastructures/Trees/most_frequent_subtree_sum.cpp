// Finding most frequent subtree sum
// SlothyCoder16
// July 29, 2020

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
    unordered_map<int, int> umap;
    int frequentSubtreeSum(TreeNode* root) {
        if(root == NULL) return 0;

        int sum = root->val;
        int leftSum = frequentSubtreeSum(root->left);
        int rightSum = frequentSubtreeSum(root->right);

        umap[sum + leftSum + rightSum] = umap[sum + leftSum + rightSum] + 1;
        return sum + leftSum + rightSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        frequentSubtreeSum(root);

        unordered_map<int,int>::iterator it = umap.begin();
        int maxFreq = INT_MIN;
        while(it != umap.end()) {
            maxFreq = max(maxFreq, it->second);
            it++;
        }

        it = umap.begin();
        while(it != umap.end()) {
            if(it->second == maxFreq)
                res.push_back(it->first);
            it++;
        }

        return res;
    }
};
