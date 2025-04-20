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
    void f(TreeNode* root, vector<long long> &arr, int l)
    {
        if (root == nullptr) return;
        if (arr.size() <= l) arr.push_back(0);
        arr[l] += root->val;
        f(root->left, arr, l+1);
        f(root->right, arr, l+1);
        return;
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> arr;
        f(root, arr, 0);
        if (arr.size() < k) return -1;
        sort(arr.rbegin(), arr.rend());
        return arr[k-1];
    }
};