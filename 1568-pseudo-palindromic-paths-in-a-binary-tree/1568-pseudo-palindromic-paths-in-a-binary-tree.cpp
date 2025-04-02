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
    void f(TreeNode* root, vector<int> arr)
    {
        if (root == nullptr) return;
        arr[root->val]++;
        if (root->left == nullptr && root->right == nullptr)
        {
            int odd = 0;
            for (int i=0; i!=10; i++) odd += arr[i]%2;
            if (odd < 2) ans++;
        }
        f(root->left, arr);
        f(root->right, arr);
        return;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> arr(10, 0);
        f(root, arr);
        return ans;
    }
};