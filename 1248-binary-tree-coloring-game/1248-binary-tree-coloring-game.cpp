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
    void count(TreeNode* root, int &c)
    {
        if (root == nullptr) return;
        c++;
        count(root->left, c);
        count(root->right, c);
        return;
    }

    void f(TreeNode* root, int x, int &l, int &r, bool isit)
    {
        if (root == nullptr) return;
        if (root->val == x)
        {
            count(root->left, l);
            count(root->right, r);
            return;
        }
        f(root->left, x, l, r, 0);
        f(root->right, x, l, r, 0);
        return;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int l = 0, r = 0, u = 0;
        f(root, x, l, r, 0);
        u = n - 1 - l - r;
        if (u > n/2 || r > n/2 || l > n/2 ) return 1;
        return 0;
    }
};