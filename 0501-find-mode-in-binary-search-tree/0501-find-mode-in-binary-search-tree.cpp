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
    unordered_map<int, int> m;
    
    void f (TreeNode* root)
    {
        if (root == nullptr) return;
        m[root->val]++;
        f(root->left);
        f(root->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        f(root);
        int ma = -1;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            ma = max(ma, i->second);
        }
        vector<int> ans;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            if (ma == i->second) ans.push_back(i->first);
        }
        return ans;
    }
};