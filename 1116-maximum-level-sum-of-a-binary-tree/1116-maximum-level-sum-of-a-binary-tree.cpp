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
    void f(TreeNode* root, int l, vector<pair<int, int>> &q)
    {
        if (root == nullptr) return;
        q.push_back({l, root->val});
        f(root->left, l+1, q);
        f(root->right, l+1, q);
        return;
    }
    
    int maxLevelSum(TreeNode* root) {
        vector<pair<int, int>> q;
        f(root, 1, q);
        sort(q.begin(), q.end());
        int l = 1, sum = 0, ans = -1, maxsum = -2000000000;
        for (int i=0; i<q.size(); i++)
        {
            int add = q[i].second, s = q[i].first;
            if (s != l)
            {
                sum = 0;
                l = s;
            }
            sum += add;
            if (sum > maxsum)
            {
                maxsum = sum;
                ans = l;
            }
        }
        return ans;
    }
};