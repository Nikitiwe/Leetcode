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
    int f(TreeNode* root, priority_queue<int> &q)
    {
        if (root == nullptr) return 0;
        int l = f(root->left, q);
        int r = f(root->right, q);
        int m = -1;
        if (l == r && l >= 0) m = l + r + 1;
        if (m > 0) q.push(m);
        return m;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int> q;
        f(root, q);
        if (q.size() < k) return -1;
        for (int i=1; i<k; i++) q.pop();
        return q.top();
    }
};