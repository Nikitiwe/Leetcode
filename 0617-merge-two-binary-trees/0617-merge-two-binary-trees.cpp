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
    TreeNode* f(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr && root2 == nullptr) return nullptr;
        TreeNode* root = new TreeNode;
        if (root1 != nullptr) root->val += root1->val;
        if (root2 != nullptr) root->val += root2->val;
        if (root1 != nullptr && root2 != nullptr)
        {
            if (root1->left != nullptr && root2->left != nullptr) root->left = f(root1->left, root2->left);
            else if (root1->left != nullptr) root->left = root1->left;
            else if (root2->left != nullptr) root->left = root2->left;
            if (root1->right != nullptr && root2->right != nullptr) root->right = f(root1->right, root2->right);
            else if (root1->right != nullptr) root->right = root1->right;
            else if (root2->right != nullptr) root->right = root2->right;
        }
        else if (root1 != nullptr)
        {
            if (root1->left != nullptr) root->left = root1->left;
            if (root1->right != nullptr) root->right = root1->right;
        }
        else if (root2 != nullptr)
        {
            if (root2->left != nullptr) root->left = root2->left;
            if (root2->right != nullptr) root->right = root2->right;
        }
        return root;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return f(root1, root2);
    }
};