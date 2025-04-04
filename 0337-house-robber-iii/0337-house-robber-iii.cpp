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
    pair<int, int> f(TreeNode* root)
    {
        if (root == nullptr) return {0, 0};
        pair<int, int> l(0,0), r(0,0);
        if (root->left != nullptr)
        {
            l = f(root->left);
        }
        if (root->right != nullptr)
        {
            r = f(root->right);
        }
        return {root->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second)};
    }

    int rob(TreeNode* root) {
        pair<int, int> ans = f(root);
        return max(ans.first, ans.second);
    }
};