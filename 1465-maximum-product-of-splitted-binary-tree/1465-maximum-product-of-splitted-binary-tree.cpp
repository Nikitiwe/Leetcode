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
    long long f(TreeNode* root, vector<long long> &arr)
    {
        if (root == nullptr) return 0;
        long long l = f(root->left, arr);
        long long r = f(root->right, arr);
        long long t = l + r + root->val;
        arr.push_back(t);
        return t;
    }

    int maxProduct(TreeNode* root) {
        vector<long long> arr;
        f(root, arr);
        long long ma = *max_element(arr.begin(), arr.end());
        long long ans = 0;
        for (int i=0; i!=arr.size(); i++) ans = max(ans, arr[i]*(ma - arr[i]));
        return ans % 1000000007;
    }
};