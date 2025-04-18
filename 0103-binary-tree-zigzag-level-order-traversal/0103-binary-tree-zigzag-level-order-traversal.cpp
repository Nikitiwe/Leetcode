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
    void f(TreeNode* root, vector<vector<int>> &ans, int l)
    {
        if (root == nullptr) return;
        if (ans.size() <= l) ans.push_back({});
        ans[l].push_back(root->val);
        f(root->left, ans, l+1);
        f(root->right, ans, l+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        f(root, ans, 0);
        for (int i=1; i<ans.size(); i += 2)
        {
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};