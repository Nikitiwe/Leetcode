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
    void f(TreeNode* root, int l, int val, int d)
    {
        if (root == nullptr) return;
        queue<TreeNode*> n;
        queue<int> lev;
        n.push(root);
        lev.push(l);
        while (n.size() > 0)
        {
            TreeNode* t = n.front();
            n.pop();
            int l = lev.front();
            lev.pop();
            if (l < d - 1 )
            {
                if (t->left != nullptr)
                {
                    n.push(t->left);
                    lev.push(l+1);
                }
                if (t->right != nullptr)
                {
                    n.push(t->right);
                    lev.push(l+1);
                }
            }
            else if (l == d - 1)
            {
                TreeNode* a = new TreeNode(val);
                a->left = t->left;
                t->left = a;
                TreeNode* b = new TreeNode(val);
                b->right = t->right;
                t->right = b;
            }
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if (d == 1)
        {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        else
        {
            f(root, 1, val, d);
        }
        return root;
    }
};