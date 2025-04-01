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
    void f(TreeNode* root, int ma)
    {
        if (root == nullptr) return;
        if (root->val >= ma) ans++;
        f(root->left, max(ma, root->val));
        f(root->right, max(ma, root->val));
        return;
    }

    int goodNodes(TreeNode* root) {
        f(root, root->val);
        return ans;
    }
};