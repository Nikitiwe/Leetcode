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
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) return 1;
        bool l = 1;
        if (root->left != nullptr)
        {
            if (root->val == root->left->val) l = isUnivalTree(root->left);
            else l = 0;
        }
        if (l == 1 && root->right != nullptr)
        {
            if (root->val == root->right->val) l = isUnivalTree(root->right);
            else l = 0;
        }
        return l;
    }
};