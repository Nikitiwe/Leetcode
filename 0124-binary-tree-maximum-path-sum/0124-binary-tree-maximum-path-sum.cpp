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
    int ans = -30000000;
    
    int f(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int l = root->val + f(root->left);
        int r = root->val + f(root->right);
        ans = max(ans, l);
        ans = max(ans, r);
        ans = max(ans, root->val);
        ans = max(ans, l + r - root->val);
        return max(max(l, r), root->val);
    }

    int maxPathSum(TreeNode* root) {
        f(root);
        return ans;
    }
};