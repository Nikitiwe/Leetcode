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
    int f(TreeNode* root, unordered_map<int, int> &m)
    {
        if (root == nullptr) return 0;
        int l = f(root->left, m);
        int r = f(root->right, m);
        m[root->val + l + r]++;
        return root->val + l + r;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> m;
        f(root, m);
        int ma = -1;
        for (auto i = m.begin(); i!=m.end(); i++)
        {
            ma = max(ma, i->second);
        }
        for (auto i = m.begin(); i!=m.end(); i++)
        {
            if (ma == i->second) ans.push_back(i->first);
        }
        return ans;
    }
};