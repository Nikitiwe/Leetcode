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
    void trav(TreeNode* root, unordered_map<int, int> &m)
    {
        if (root == nullptr) return;
        m[root->val]++;
        trav(root->left, m);
        trav(root->right, m);
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        unordered_map<int, int> m;
        trav(root1, m);
        trav(root2, m);
        vector<int> ans;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            ans.push_back(i->first);
            if (i->second == 2)
            {
                ans.push_back(i->first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};