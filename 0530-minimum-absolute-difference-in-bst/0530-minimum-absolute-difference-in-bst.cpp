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
    void f(TreeNode* root, vector<int> &arr)
    {
        if (root == nullptr) return;
        arr.push_back(root->val);
        f(root->left, arr);
        f(root->right, arr);
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        f(root, arr);
        int ans = 1000000;
        sort(arr.begin(), arr.end());
        for (int i=0; i<arr.size()-1; i++) ans = min(ans, arr[i+1] - arr[i]);
        return ans;
    }
};