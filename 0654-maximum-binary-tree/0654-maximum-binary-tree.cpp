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
    TreeNode* f(vector<int>& nums, int l, int r)
    {
        if (l > r) return nullptr;
        int idma = l;
        for (int i=l+1; i <= r; i++)
        {
            if (nums[idma] < nums[i]) idma = i;
        }
        TreeNode* root = new TreeNode;
        root->val = nums[idma];
        root->left = f(nums, l, idma - 1);
        root->right = f(nums, idma + 1, r);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode;
        root = f(nums, 0, nums.size() - 1);
        return root;
    }
};