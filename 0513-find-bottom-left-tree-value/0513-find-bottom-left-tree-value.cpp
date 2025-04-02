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
    deque<pair<int, int>> q;
    void f(TreeNode* root, int l)
    {
        if (root == nullptr) return;
        q.push_back({root->val, l});
        f(root->left, l+1);
        f(root->right, l+1);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        f(root, 0);
        int l = -1, ans;
        while (q.size() > 0)
        {
            if (q.back().second > l)
            {
                l = q.back().second;
                ans = q.back().first;
            }
            else if (q.back().second == l)
            {
                ans = q.back().first;
            }
            q.pop_back();
        }
        return ans;
    }
};