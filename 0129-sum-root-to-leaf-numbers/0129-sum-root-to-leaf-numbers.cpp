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
    int ans = 0;
    void f(TreeNode* root, int arr)
    {
        if (root == nullptr) return;
        arr *= 10;
        arr += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans += arr;
        }
        f(root->left, arr);
        f(root->right, arr);
        return;
    }

    int sumNumbers(TreeNode* root) {
        int arr = 0;
        f(root, arr);
        return ans;
    }
};