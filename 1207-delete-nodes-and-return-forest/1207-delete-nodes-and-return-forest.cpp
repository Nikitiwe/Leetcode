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
    vector<TreeNode*> ans;
    void f(TreeNode* root, unordered_set<int> &s, int r)
    {
        if (root == nullptr) return;
        if (s.count(root->val) == 0)
        {
            if (root->left != nullptr && s.count(root->left->val) == 1)
            {
                f(root->left, s, 1);
                root->left = nullptr;
            }
            else if (root->left != nullptr && s.count(root->left->val) == 0)
            {
                f(root->left, s, 0);
            }
            if (root->right != nullptr && s.count(root->right->val) == 1)
            {
                f(root->right, s, 1);
                root->right = nullptr;
            }
            else if (root->right != nullptr && s.count(root->right->val) == 0)
            {
                f(root->right, s, 0);
            }
            if (r == 1) ans.push_back(root);
        }
        else
        {
            f(root->left, s, 1);
            f(root->right, s, 1);
        }
        return;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        for (int i=0; i!=to_delete.size(); i++) s.insert(to_delete[i]);
        f(root, s, 1);
        return ans;
    }
};