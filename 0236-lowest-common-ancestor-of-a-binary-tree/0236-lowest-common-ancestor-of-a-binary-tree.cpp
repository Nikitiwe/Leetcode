/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool traverse(TreeNode* root, TreeNode* t, unordered_map<TreeNode*, int> &m) {
        if (root == nullptr) return 0;
        if (root == t)
        {
            m[root]++;
            return 1;
        }
        if (traverse(root->left, t, m) || traverse(root->right, t, m))
        {
            m[root]++;
            return 1;
        }
        return 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, int> m;
        traverse(root, p, m);
        traverse(root, q, m);
        TreeNode* t = root;
        while (1)
        {
            if (m[t->left] == 2) t = t->left;
            else if (m[t->right] == 2) t = t->right;
            else break;
        }
        return t;
    }
};