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
    TreeNode* f(vector<int>& arr, int l, int r)
    {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode;
        root->val = arr[l];
        int id = l;
        while (id<r && arr[id+1] < arr[l]) id++;
        root->left = f(arr, l+1, id);
        root->right = f(arr, id+1, r);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& arr) {
        int l = 0;
        return f(arr, l, arr.size() - 1);
    }
};