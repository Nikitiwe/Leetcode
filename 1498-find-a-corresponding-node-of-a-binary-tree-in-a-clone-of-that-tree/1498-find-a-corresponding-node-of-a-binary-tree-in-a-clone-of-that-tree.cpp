/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* traverse(TreeNode* root, int v) {
        if (root == NULL) return NULL;        
        if (root->val == v) return root;
        if (traverse(root->left, v) != NULL) return traverse(root->left, v);
        return traverse(root->right, v);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return traverse(cloned, target->val);
    }
};