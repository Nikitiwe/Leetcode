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
    bool f(TreeNode* root, unordered_set<int> &s, int k)
    {
        if (root == nullptr) return 0;
        if (s.count(k - root->val) != 0) return 1;
        s.insert(root->val);
        return f(root->left, s, k) || f(root->right, s, k);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return f(root, s, k);
    }
};