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
    unordered_map<TreeNode*, int> d, n;
    
    void f(TreeNode* root)
    {
        if (root == nullptr) return;
        int ld = 0, ln = 0, rd = 0, rn = 0;
        if (root->left != nullptr)
        {
            f(root->left);
            ld = d[root->left];
            ln = n[root->left];
        }
        if (root->right != nullptr)
        {
            f(root->right);
            rd = d[root->right];
            rn = n[root->right];
        }
        d[root] = root->val + ln + rn;
        n[root] = max(ln, ld) + max(rn, rd);
        return;
    }

    int rob(TreeNode* root) {
        f(root);
        return max(d[root], n[root]);
    }
};