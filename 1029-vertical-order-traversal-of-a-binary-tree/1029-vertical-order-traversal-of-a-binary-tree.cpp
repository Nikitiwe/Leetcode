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
    
    void f(TreeNode* root, pair<int, int> p, vector<vector<pair<int, int>>>& arr)
    {
        if (root == nullptr) return;
        arr[p.second + 1000].push_back({p.first, root->val});
        if (root->left != nullptr) f(root->left, {p.first+1, p.second-1}, arr);
        if (root->right != nullptr) f(root->right, {p.first+1, p.second+1}, arr);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<vector<pair<int, int>>> arr(2001);
        f(root, {0, 0}, arr);
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i].size() > 0)
            {
                sort(arr[i].begin(), arr[i].end());
                vector<int> t;
                for (int j=0; j!=arr[i].size(); j++) t.push_back(arr[i][j].second);
                ans.push_back(t);
            }
        }
        return ans;
    }
};