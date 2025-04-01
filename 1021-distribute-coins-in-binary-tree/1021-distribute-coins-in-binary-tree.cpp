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
    int tran(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int l = tran(root->left);
        int r = tran(root->right);
        ans += abs(l) + abs(r);
        root->val += l + r;
        return root->val - 1;
    }

    int distributeCoins(TreeNode* root) {
        tran(root);
        return ans;
    }
};