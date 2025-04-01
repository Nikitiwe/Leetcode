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
    void func(TreeNode* root, int v)
    {
        if (root == nullptr) return;
        if (root->val > v)
        {
            if (root->left != nullptr) func(root->left, v);
            else
            {
                TreeNode* n = new TreeNode;
                root->left = n;
                n->val = v;
            }
        }
        if (root->val < v)
        {
            if (root->right != nullptr) func(root->right, v);
            else
            {
                TreeNode* n = new TreeNode;
                root->right = n;
                n->val = v;
            }
        }
        return;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            TreeNode* n = new TreeNode;
            n->val = val;
            return n;
        }
        func(root, val);
        return root;
    }
};