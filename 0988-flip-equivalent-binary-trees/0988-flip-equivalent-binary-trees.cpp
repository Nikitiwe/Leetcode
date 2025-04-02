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
    void f(TreeNode* root, map<int, int> &m)
    {
        if (root == nullptr) return;
        int l = 0, r = 0;
        if (root->left != nullptr) l += root->left->val;
        if (root->right != nullptr) r += root->right->val;
        m[root->val] = 1000*min(l, r) + max(l, r);
        f(root->left, m);
        f(root->right, m);
        return;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        map<int, int> m1, m2;
        f(root1, m1);
        f(root2, m2);
        if (m1 == m2) return 1;
        return 0;
    }
};