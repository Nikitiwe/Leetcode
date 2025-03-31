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
    void f(TreeNode* root, int t)
    {
        if (root == nullptr) return;
        f(root->left, t);
        f(root->right, t);
        if (root->left != nullptr && root->left->val == t && root->left->left == nullptr && root->left->right == nullptr) root->left = nullptr;
        if (root->right != nullptr && root->right->val == t && root->right->left == nullptr && root->right->right == nullptr) root->right = nullptr;
        return;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int t) {
        f(root, t);
        if (root->val == t && root->left == nullptr && root->right == nullptr) return nullptr;
        return root;
    }
};