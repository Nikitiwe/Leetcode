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
    void traverse(TreeNode* root, unordered_map<int, int> &m, int l) {
        if (root == nullptr) return;
        m[l] += root->val;
        if (root->left) traverse(root->left, m, l+1);
        if (root->right) traverse(root->right, m, l+1);
        return;
    }

    int deepestLeavesSum(TreeNode* root) {
        unordered_map<int, int> m;
        traverse(root, m, 0);
        int ans = 0, l = -1;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->first > l)
            {
                ans = it->second;
                l = it->first;
            }
        }
        return ans;
    }
};