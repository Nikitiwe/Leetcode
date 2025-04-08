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
class FindElements {
public:
    unordered_set<int> m;
    void f(TreeNode* root, int v)
    {
        if (root == nullptr) return;
        m.insert(v);
        f(root->left, v*2 + 1);
        f(root->right, v*2 + 2);
        return;
    }

    FindElements(TreeNode* root) {
        f(root, 0);
        return;
    }
    
    bool find(int t) {
        return m.count(t);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */