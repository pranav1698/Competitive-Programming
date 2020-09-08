// Convert to int from root to leaf
// SlothyCoder16
// September 08, 2020

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
    int convertToInt(string binary) {
        int ans=0;
        int len = binary.size();
        int count=0;

        while(len!=0) {
            int curr = binary[len-1] - '0';
            ans += curr*pow(2,count);
            count++;
            len--;
        }

        return ans;
    }

    int binarySum(TreeNode* root, string binary) {
        if(root == NULL) return 0;

        if(root->left == NULL && root->right == NULL) {
            binary += to_string(root->val);
            return convertToInt(binary);
        }

        binary += to_string(root->val);
        return binarySum(root->left, binary) + binarySum(root->right, binary);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL) return 0;

        return binarySum(root, "");
    }
};
