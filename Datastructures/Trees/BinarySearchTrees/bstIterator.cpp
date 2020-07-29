// BST iterator using BST trees
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
class BSTIterator {
public:
    TreeNode* root;
    stack<TreeNode*> s;
    queue<int> q;

    BSTIterator(TreeNode* root) {
        this->root = root;

        while(!this->s.empty() || this->root != NULL) {
            if(this->root != NULL) {
                this->s.push(this->root);
                this->root = this->root->left;
            } else {
                TreeNode* curr = this->s.top();
                this->s.pop();
                this->q.push(curr->val);
                this->root = curr->right;
            }
        }
    }

    /** @return the next smallest number */
    int next() {
        int ans = q.front();
        q.pop();
        return ans;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
