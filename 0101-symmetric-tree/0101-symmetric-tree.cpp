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
    bool f(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) return 1;
        if (l != nullptr && r == nullptr) return 0;
        if (l == nullptr && r != nullptr) return 0;
        return l->val == r->val && f(l->left, r->right) && f(l->right, r->left);
    }
       
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return 1;
        return f(root->left, root->right);
    }
};