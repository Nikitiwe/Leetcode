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
    long long a = -1, mi = -1;
    
    void f(TreeNode* root)
    {
        if (root == nullptr) return;
        if (a == -1)
        {
            mi = (long long)root->val;
            a = 100000000000;
        }
        else if (root->val != mi) a = min(a, (long long)root->val);
        f(root->left);
        f(root->right);
        return;
    }

    int findSecondMinimumValue(TreeNode* root) {
        f(root);
        if (a != mi && a != 100000000000) return a;
        else return -1;
    }
};