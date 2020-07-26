// Serialize and Deserailize tree using Recursion
// SlothyCoder16
// July 26, 2020

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "X,"  ;

        string leftSubtree = serialize(root->left);
        string rightSubtree = serialize(root->right);

        return to_string(root->val) + "," + leftSubtree + rightSubtree;
    }

    TreeNode* deserializeHelper(queue<string> &q) {
        string curr = q.front();
        q.pop();

        if(curr == "X")
            return NULL;

        stringstream s(curr);
        int x;
        s >> x;
        TreeNode* root = new TreeNode(x);
        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);


        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = new TreeNode();
        queue<string> q;

        string delimiter = ",";
        size_t pos = 0;
        std::string token;
        while ((pos = data.find(delimiter)) != std::string::npos) {
            token = data.substr(0, pos);
            q.push(token);
            data.erase(0, pos + delimiter.length());
        }

        return deserializeHelper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
