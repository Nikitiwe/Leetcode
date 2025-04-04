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
    unordered_set<TreeNode*> q;
    int f(TreeNode* root, int k, int s)
    {
        if (root == nullptr) return 0;
        s += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (s < k) q.insert(root);
            return root->val;
        }
        int l;
        int r;
        if (root->left != nullptr && root->right != nullptr)
        {
            l = f(root->left, k, s);
            r = f(root->right, k, s);
            if (s + l < k && s + r < k) q.insert(root);
            return max(l, r) + root->val;
        }
        else if (root->left == nullptr && root->right != nullptr)
        {
            r = f(root->right, k, s);
            if (s + r < k) q.insert(root);
            return r + root->val;
        }
        else if (root->left != nullptr && root->right == nullptr)
        {
            l = f(root->left, k, s);
            if (s + l < k) q.insert(root);
            return l + root->val;
        }
        return 0;
    }

    void g(TreeNode* root)
    {
        if (root == nullptr) return;
        if (root->left != nullptr)
        {
            if (q.count(root->left) != 0) root->left = nullptr;
            else g(root->left);
        }
        if (root->right != nullptr)
        {
            if (q.count(root->right) != 0) root->right = nullptr;
            else g(root->right);
        }
        return;
    }

    TreeNode* sufficientSubset(TreeNode* root, int k) {
        f(root, k, 0);
        g(root);
        if (q.count(root) != 0) return {};
        return root;
    }
};