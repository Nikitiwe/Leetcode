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
    void f(TreeNode* root, string s, vector<string> &ans)
    {
        if (root == nullptr) return;
        string t;
        if (s.size() > 0) t = s + "->" + to_string(root->val);
        else t = to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) ans.push_back(t);
        f(root->left, t, ans);
        f(root->right, t, ans);
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        f(root, "", ans);
        return ans;
    }
};