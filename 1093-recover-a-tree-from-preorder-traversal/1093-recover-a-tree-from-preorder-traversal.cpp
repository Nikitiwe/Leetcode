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
    TreeNode* f(queue<int> &val, queue<int> &deep)
    {
        TreeNode* root = new TreeNode;
        root->val = val.front();
        int h = deep.front();
        val.pop();
        deep.pop();
        if (deep.size() > 0 && deep.front() == h + 1) root->left = f(val, deep);
        if (deep.size() > 0 && deep.front() == h + 1) root->right = f(val, deep);
        return root;
    }

    TreeNode* recoverFromPreorder(string s) {
        s += '-';
        queue<int> val, deep;
        int l = 0, v = 0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] == '-') l++;
            else
            {
                v *= 10;
                v += s[i] - '0';
                if (s[i+1] == '-')
                {
                    val.push(v);
                    deep.push(l);
                    v = 0;
                    l = 0;
                }
            }
        }
        return f(val, deep);
    }
};