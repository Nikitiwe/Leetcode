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
    TreeNode* root = new TreeNode(0);
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, int> l, r;
        unordered_set<int> ru;
        for (int i=0; i!=d.size(); i++)
        {
            ru.insert(d[i][0]);
            if (d[i][2] == 0) r[d[i][0]] = d[i][1];
            else l[d[i][0]] = d[i][1];
        }
        for (int i=0; i!=d.size(); i++) ru.erase(d[i][1]);
        root->val = *(ru.begin());
        queue<TreeNode*> q;
        q.push(root);
        while (q.size() > 0)
        {
            TreeNode* t = q.front();
            q.pop();
            if (l.count(t->val) != 0)
            {
                TreeNode* n = new TreeNode(l[t->val]);
                t->left = n;
                q.push(n);
            }
            if (r.count(t->val) != 0)
            {
                TreeNode* n = new TreeNode(r[t->val]);
                t->right = n;
                q.push(n);
            }
        }
        return root;
    }
};