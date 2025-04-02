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
    void f(TreeNode* root, queue<int> &q)
    {
        if (root == nullptr) return;
        q.push(root->val);
        f(root->left, q);
        f(root->right, q);
        return;
    }

    void g(TreeNode* root, queue<int> &q)
    {
        q.pop();
        while (q.size() > 0)
        {
            root->left = nullptr;
            if (root->right == nullptr)
            {
                TreeNode* n = new TreeNode;
                n->val = q.front();
                root->right = n;
                root = n;
            }
            else
            {
                root->right->val = q.front();
                root = root->right;
            }
            q.pop();      
        }
        return;
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        queue<int> q;
        f(root, q);
        TreeNode* ans = new TreeNode;
        g(root, q);
        root;
    }
};