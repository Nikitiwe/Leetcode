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
    void f(TreeNode* root, vector<vector<int>> &ans, vector<int> t, int sum, int k)
    {
        if (root == nullptr) return;
        t.push_back(root->val);
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr && sum == k) ans.push_back(t);
        f(root->left, ans, t, sum, k);
        f(root->right, ans, t, sum, k);
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int k) {
        vector<vector<int>> ans;
        f(root, ans, {}, 0, k);
        return ans;
    }
};