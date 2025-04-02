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
    queue<int> q, qq, nn;
    queue<TreeNode*> nod;
    void f(TreeNode* root, int l)
    {
        q.push(l);
        nod.push(root);
        while (q.size() > 0)
        {
            int l = q.front();
            TreeNode* n = nod.front();
            q.pop();
            nod.pop();
            qq.push(l);
            nn.push(n->val);
            if (n->left != nullptr)
            {
                q.push(l+1);
                nod.push(n->left);
            }
            if (n->right != nullptr)
            {
                q.push(l+1);
                nod.push(n->right);
            }
        }
        return;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        f(root, 0);
        vector<int> t, zero;
        int l = qq.front();
        while (qq.size() > 0)
        {
            int s = qq.front();
            int v = nn.front();
            qq.pop();
            nn.pop();
            if (l < s)
            {
                ans.push_back(t);
                t = zero;
                l = s;
            }
            t.push_back(v);
        }
        if (t.size() > 0) ans.push_back(t);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};