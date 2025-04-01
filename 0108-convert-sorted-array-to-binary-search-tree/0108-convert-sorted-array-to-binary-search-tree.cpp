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
    TreeNode* func(vector<int>& nums, int l, int r)
    {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode;
        int m = (l+r)/2;
        root->val = nums[m];
        root->left = func(nums, l, m-1);
        root->right = func(nums, m+1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size()-1);
    }
};