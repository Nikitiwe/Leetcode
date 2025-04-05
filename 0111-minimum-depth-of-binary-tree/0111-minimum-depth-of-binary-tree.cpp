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
    int ans = 1000000;

    void f(TreeNode* root, int l)
    {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) ans = min(ans, l);
        f(root->left, l+1);
        f(root->right, l+1);
        return;
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        f(root, 1);
        return ans;
    }
};