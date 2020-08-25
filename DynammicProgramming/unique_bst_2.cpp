// Unique BST arrays in BST
// SlothyCoder16
// August 25, 2020

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
    TreeNode* increaseRight(int x, TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* temp = new TreeNode(root->val + x);
        temp->left = increaseRight(x, root->left);
        temp->right = increaseRight(x, root->right);

        return temp;
    }

    void print(TreeNode* root) {
        if(root == NULL) {
            cout << "null" << " ";
            return;
        }
        cout << root->val << " ";
        print(root->left);
        print(root->right);
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        dp[0].push_back(NULL);
        TreeNode* first = new TreeNode(1);
        dp[1].push_back(first);

        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++) {
                for(int k=0; k<dp[j-1].size(); k++) {
                    TreeNode* root = new TreeNode(j);
                    root->left = dp[j-1][k];
                    for(int l=0; l<dp[i-j].size(); l++) {
                        root->right = increaseRight(j, dp[i-j][l]);
                        print(root);
                        cout << endl;
                        TreeNode* temp = root;
                        dp[i].push_back(temp);
                    }
                }
            }

        }

        return dp[n];
    }
};
