// Finding path sum for the
// SlothyCoder16
// July 27, 2020

class Solution {
public:
    vector<int> v;
    int count=0;
    int pathSum(TreeNode* root, int sum)
    {
        helper(root,sum);
        return count;
    }
    void helper(TreeNode* root,int sum)
    {
        if(root==NULL)
            return;
        v.push_back(root->val);
        helper(root->left,sum);
        helper(root->right,sum);
        int temp=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            temp=temp+v[i];
            if(temp==sum)
                count++;
        }
        v.pop_back();
    }
};
