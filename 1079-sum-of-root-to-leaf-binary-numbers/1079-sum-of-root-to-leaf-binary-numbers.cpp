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
    void f(TreeNode* root, int s)
    {
        if (root == nullptr) return;
        s *= 2;
        s += root->val;
        if (root->left == nullptr && root->right == nullptr) ans += s;
        else
        {
            f(root->left, s);
            f(root->right, s);
        }
        return;
    }

    int sumRootToLeaf(TreeNode* root) {
        f(root, 0);
        return ans;
    }
};