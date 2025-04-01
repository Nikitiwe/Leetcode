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
    void fun(TreeNode* root, queue<pair<int, double>> &q, int l)
    {
        if (root == nullptr) return;
        q.push({l, root->val});
        fun(root->left, q, l+1);
        fun(root->right, q, l+1);
        return;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<int> c;
        queue<pair<int, double>> q;
        fun(root, q, 0);
        while(q.size() > 0)
        {
            int n = q.front().first;
            double add = q.front().second;
            q.pop();
            if (ans.size() <= n)
            {
                ans.push_back(add);
                c.push_back(1);
            }
            else
            {
                ans[n] += add;
                c[n]++;
            }
        }
        for (int i=0; i!=ans.size(); i++) ans[i] /= c[i];
        return ans;
    }
};