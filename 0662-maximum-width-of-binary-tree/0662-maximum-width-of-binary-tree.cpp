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
    unsigned long long ans = 0;
    unordered_map<int, unsigned long long> mi, ma;

    void f(TreeNode* root)
    {
        if (root == nullptr) return;
        queue<TreeNode*> q;
        queue<unsigned long long> n, p;
        q.push(root);
        n.push(0);
        p.push(1);
        while (q.size() > 0)
        {
            TreeNode* t = q.front();
            int l = n.front();
            unsigned long long pp = p.front();
            q.pop(); n.pop(); p.pop();
            if (mi.count(l) != 0) mi[l] = min(mi[l], pp); else mi[l] = pp;
            if (ma.count(l) != 0) ma[l] = max(ma[l], pp); else ma[l] = pp;
            ans = max(ans, ma[l] - mi[l] + 1);
            if (t->left != nullptr)
            {
                q.push(t->left);
                n.push(l+1);
                p.push(pp*2);
            }
            if (t->right != nullptr)
            {
                q.push(t->right);
                n.push(l+1);
                p.push(pp*2 + 1);
            }
        }
        return;
    }

    int widthOfBinaryTree(TreeNode* root) {
        f(root);
        return ans;
    }
};