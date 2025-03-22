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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> prev, next, zero;
        prev.push(root);
        while (prev.size() > 0)
        {
            vector<int> temp;
            while (prev.size() > 0)
            {
                if (prev.front()->left != nullptr) next.push(prev.front()->left);
                temp.push_back(prev.front()->val);
                if (prev.front()->right != nullptr) next.push(prev.front()->right);
                prev.pop();
            }
            prev = next;
            next = zero;
            ans.push_back(temp);
        }
        return ans;
    }
};