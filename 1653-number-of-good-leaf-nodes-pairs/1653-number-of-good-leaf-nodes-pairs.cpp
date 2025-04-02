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
    int res = 0;
    vector<int> f(TreeNode* root, int d)
    {
        if (root == nullptr) return {};
        vector<int> ans, l = f(root->left, d), r = f(root->right, d);
        for (int i=0; i<l.size(); i++)
        {
            for (int j=0; j<r.size(); j++)
            {
                if (l[i] + r[j] + 2 <= d) res++;
            }
            if (l[i]+1 < d) ans.push_back(l[i]+1);
        }
        for (int j=0; j<r.size(); j++)
        {
            if (r[j]+1 < d) ans.push_back(r[j]+1);
        }
        if (root->left == nullptr && root->right == nullptr) ans.push_back(0);
        return ans;
    }

    int countPairs(TreeNode* root, int distance) {
        if (root == nullptr) return 0;
        f(root, distance);
        return res;
    }
};