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
    void f(TreeNode* root, string &ans)
    {
        if (root == nullptr) return;
        ans += to_string(root->val);
        ans += "(";
        f(root->left, ans);
        ans += ")";
        ans += "(";
        f(root->right, ans);
        ans += ")";
        if (ans.size() > 3 && ans[ans.size()-4] == '(' && ans[ans.size()-3] == ')' 
                            && ans[ans.size()-2] == '(' && ans[ans.size()-1] == ')' )
                            {
                                ans.pop_back();
                                ans.pop_back();
                                ans.pop_back();
                                ans.pop_back();
                            }
        if (ans.size() > 3 && ans[ans.size()-4] != '(' && ans[ans.size()-3] == ')' 
                            && ans[ans.size()-2] == '(' && ans[ans.size()-1] == ')' )
                            {
                                ans.pop_back();
                                ans.pop_back();
                            }
        return;
    }

    string tree2str(TreeNode* root) {
        string ans;
        f(root, ans);
        return ans;
    }
};