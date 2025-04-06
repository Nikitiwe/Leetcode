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
    int ans = 0;
    static const vector<int> no;
    static const vector<int> zero;
    
    vector<int> f(TreeNode* root) // mi, ma, sum
    {
        if (root == nullptr) return zero;
        vector<int> l = f(root->left);
        vector<int> r = f(root->right);
        if (l == no || r == no) return no;
        if (l == zero && r != zero)
        {
            if (root->val < r[0])
            {
                ans = max(ans, root->val + r[2]);
                return {root->val, r[1], root->val + r[2]};
            }
            else return no;
        }
        else if (l != zero && r == zero)
        {
            if (root->val > l[1])
            {
                ans = max(ans, root->val + l[2]);
                return {l[0], root->val, root->val + l[2]};
            }
            else return no;
        }
        else if (l != zero && r != zero)
        {
            if (root->val > l[1] && root->val < r[0])
            {
                ans = max(ans, root->val + l[2] + r[2]);
                return {l[0], r[1], root->val + l[2] + r[2]};
            }
            else return no;
        }
        else
        {
            ans = max(ans, root->val);
            return {root->val, root->val, root->val};
        }
    }

    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
    }
};
const vector<int> Solution::no = { -1 };
const vector<int> Solution::zero = { 0 };