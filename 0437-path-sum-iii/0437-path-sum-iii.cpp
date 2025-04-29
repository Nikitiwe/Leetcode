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
    vector<long> f(int &ans, TreeNode* root, int k)
    {
        if (root == nullptr) return {};
        vector<long> l = f(ans, root->left, k);
        vector<long> r = f(ans, root->right, k);
        long v = root->val;
        for (int i=0; i<l.size(); i++)
        {
            l[i] += v;
            if (l[i] == k) ans++;
        }
        for (int i=0; i<r.size(); i++)
        {
            r[i] += v;
            if (r[i] == k) ans++;
            l.push_back(r[i]);
        }
        l.push_back(v);
        if (v == k) ans++;
        return l;
    }

    int pathSum(TreeNode* root, int k) {
        int ans = 0;
        f(ans, root, k);
        return ans;
    }
};