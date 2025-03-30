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
    int sum(TreeNode* root) {
        if (root == nullptr) return 0;
        int s = root->val;
        if (root->left)
        {
            s += sum(root->left);
        }
        if (root->right)
        {
            s += sum(root->right);
        }
        return s;
    }

    int count(TreeNode* root) {
        if (root == nullptr) return 0;
        int c = 1;
        if (root->left)
        {
            c += count(root->left);
        }
        if (root->right)
        {
            c += count(root->right);
        }
        return c;
    }

    void traverse(TreeNode* root, int &ans) {
        if (root == nullptr) return;
        int s = root->val;
        int c = 1;
        if (root->left)
        {
            s += sum(root->left);
            c += count(root->left);
        }
        if (root->right)
        {
            s += sum(root->right);
            c += count(root->right);
        }
        if (root->left) traverse(root->left, ans);
        if (root->right) traverse(root->right, ans);
        if (root->val == s/c) ans++;
        return;
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
};