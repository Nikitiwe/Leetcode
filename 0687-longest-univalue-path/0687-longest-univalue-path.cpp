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
    int ans = 0;
    int f(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int l = f(root->left), r = f(root->right);
        if (root->left != nullptr)
        {
            if (root->left->val == root->val) l++;
            else l = 1;
        }
        if (root->right != nullptr)
        {
            if (root->right->val == root->val)
            {
                r++;
                if (root->left != nullptr && root->left->val == root->val) ans = max(ans, r + l - 1);
            }
            else r = 1;
        }
        int t = max(l, r);
        t = max(t, 1);
        ans = max(ans, t);
        return t;

    }
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        f(root);
        return ans - 1;
    }
};