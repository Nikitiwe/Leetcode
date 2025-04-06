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
    static const array<int, 4> no;
    static const array<int, 4> zero;
    
    array<int, 4> f(TreeNode* root) // mi, ma, sum, isit
    {
        if (root == nullptr) return zero;
        array<int, 4> l = f(root->left);
        array<int, 4> r = f(root->right);
        if (l == no || r == no) return no;
        if (l == zero && r != zero)
        {
            if (root->val < r[0])
            {
                ans = max(ans, root->val + r[2]);
                return {root->val, r[1], root->val + r[2], 1};
            }
            else return no;
        }
        else if (l != zero && r == zero)
        {
            if (root->val > l[1])
            {
                ans = max(ans, root->val + l[2]);
                return {l[0], root->val, root->val + l[2], 1};
            }
            else return no;
        }
        else if (l != zero && r != zero)
        {
            if (root->val > l[1] && root->val < r[0])
            {
                ans = max(ans, root->val + l[2] + r[2]);
                return {l[0], r[1], root->val + l[2] + r[2], 1};
            }
            else return no;
        }
        else
        {
            ans = max(ans, root->val);
            return {root->val, root->val, root->val, 1};
        }
    }

    int maxSumBST(TreeNode* root) {
        f(root);
        return ans;
    }
};
const std::array<int, 4> Solution::no = {0, 0, 0, -1};
const std::array<int, 4> Solution::zero = {0, 0, 0, 0};