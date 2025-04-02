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
    pair<int, int> f(TreeNode* root, int &ans)
    {
        if (root == nullptr) return {0, 0};
        int l = f(root->left, ans).second, r = f(root->right, ans).first;
        ans = max(ans, l);
        ans = max(ans, r);
        return {l+1, r+1};
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;
        f(root, ans);
        return ans;
    }
};