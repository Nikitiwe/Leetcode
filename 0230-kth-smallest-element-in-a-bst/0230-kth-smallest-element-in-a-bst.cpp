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
    int res = -1;
    int f(TreeNode* root, int k, vector<int> &ans)
    {
        if (root == nullptr) return -1;
        f(root->left, k, ans);
        ans.push_back(root->val);
        if (ans.size() >= k) return res = ans[k-1];
        f(root->right, k, ans);
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        f(root, k, ans);
        return res;
    }
};