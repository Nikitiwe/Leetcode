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
    void f(TreeNode* root, string t, string &ans)
    {
        if (root == nullptr) return;
        t += 'a' + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            string rt = t;
            reverse(rt.begin(), rt.end());
            ans = min(ans, rt);
        }
        f(root->left, t, ans);
        f(root->right, t, ans);
        return;
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans(9000, 'z');
        f(root, "", ans);
        return ans;
    }
};