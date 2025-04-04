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
    int ma = -1;
    unordered_map<TreeNode*, int> m;
    void f(TreeNode* root, queue<TreeNode*> &q)
    {
        if (root == nullptr) return;
        queue<int> n;
        q.push(root);
        n.push(0);
        m[root] = 0;
        while (q.size() > 0)
        {
            TreeNode* t = q.front();
            int l = n.front();
            q.pop();
            n.pop();
            if (t->left != nullptr)
            {
                q.push(t->left);
                n.push(l+1);
                m[t->left] = l+1;
                ma = max(ma, l+1);
            }
            if (t->right != nullptr)
            {
                q.push(t->right);
                n.push(l+1);
                m[t->right] = l+1;
                ma = max(ma, l+1);
            }
        }
        return;
    }

    TreeNode* g(TreeNode* root, TreeNode* a, TreeNode* b)
    {
        if (root == nullptr) return nullptr;
        if (root == a || root == b) return root;
        bool la = find(root->left, a);
        bool lb = find(root->left, b);
        if (la == 1 && lb == 1) return g(root->left, a, b);
        else if (la == 0 && lb == 0) return g(root->right, a, b);
        return root;
    }

    bool find(TreeNode* root, TreeNode* a)
    {
        if (root == nullptr) return 0;
        if (root == a) return 1;
        return find(root->left, a) || find(root->right, a);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        f(root, q);
        for (auto i = m.begin(); i!=m.end(); i++) if (i->second == ma) q.push(i->first);
        if (q.size() == 0) return root;
        while (q.size() > 1)
        {
            TreeNode* t = q.front();
            q.pop();
            TreeNode* n = g(root, t, q.front());
            q.pop();
            q.push(n);
        }
        return q.front();
    }
};