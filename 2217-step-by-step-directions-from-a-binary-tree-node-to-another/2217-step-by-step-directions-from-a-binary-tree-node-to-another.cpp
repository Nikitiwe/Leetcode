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
    bool f(TreeNode* root, int s, string &c)
    {
        if (root == nullptr) return 0;
        if (root->val == s) return 1;
        c += 'L';
        if (f(root->left, s, c) == 1) return 1;
        c.pop_back();
        c += 'R';
        if (f(root->right, s, c) == 1) return 1;
        c.pop_back();
        return 0;
    }

    TreeNode* g(TreeNode* root, int s, int d)
    {
        if (root == nullptr) return nullptr;
        if (root->val == s || root->val == d) return root;
        TreeNode* l = g(root->left, s, d);
        TreeNode* r = g(root->right, s, d);

        if (l && r) return root;

        return l ? l : r;
    }

    string getDirections(TreeNode* root, int s, int d) {
        root = g(root, s, d);
        string a = "", b = "";
        f(root, s, a);
        f(root, d, b);
        for (int i = 0; i<a.size(); i++)
        {
            if (a[i] != 'U') a[i] = 'U';
        }
        return a + b;
    }
};