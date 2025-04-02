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
    void f(TreeNode* root, vector<int> &ans, vector<int> &position)
    {
        queue<pair<int, TreeNode*>> q;
        queue<int> pos;
        q.push({0, root});
        pos.push(1);
        while (q.size() > 0)
        {
            int l = q.front().first, p = pos.front();
            TreeNode* n = q.front().second;
            q.pop();
            pos.pop();
            if (ans.size() <= l)
            {
                ans.push_back(n->val);
                position.push_back(p);
            }
            else if (p > position[l]) ans[l] = n->val;
            if (n->left != nullptr)
            {
                q.push({l+1, n->left});
                pos.push(2*p);
            }
            if (n->right != nullptr)
            {
                q.push({l+1, n->right});
                pos.push(2*p + 1);
            }
        }
        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> ans;
        vector<int> position;
        f(root, ans, position);
        return ans;
    }
};