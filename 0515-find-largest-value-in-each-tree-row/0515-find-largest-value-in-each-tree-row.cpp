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
    void f(TreeNode* root, vector<int> &ans)
    {
        if (root == nullptr) return;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (q.size() > 0)
        {
            int s = q.front().first;
            TreeNode* root = q.front().second;
            if (ans.size() <= s) ans.push_back(root->val);
            else ans[s] = max(ans[s], root->val);
            q.pop();
            if (root->left != nullptr) q.push({s+1, root->left});
            if (root->right != nullptr) q.push({s+1, root->right});
        }
        return;
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        f(root, ans);
        return ans;
    }
};