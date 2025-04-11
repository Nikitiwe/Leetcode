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
    unordered_map<int, int> m;

    void f(TreeNode* root, int l)
    {
        if (root == nullptr) return;
        m[l] += root->val;
        f(root->left, l+1);
        f(root->right, l+1);
        return;
    }

    void g(TreeNode* root, int l)
    {
        if (root == nullptr) return;
        int c = 0;
        if (root->left != nullptr) c += root->left->val;
        if (root->right != nullptr) c += root->right->val;
        if (root->left != nullptr) root->left->val = m[l+1] - c;
        if (root->right != nullptr) root->right->val = m[l+1] - c;
        g(root->left, l+1);
        g(root->right, l+1);
        return;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        f(root, 0);
        g(root, 0);
        root->val = 0;
        return root;
    }
};