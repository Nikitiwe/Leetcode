/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void f(Node* root, vector<vector<int>> &ans, int l)
    {
        if (root == nullptr) return;
        if (ans.size() <= l) ans.push_back({});
        ans[l].push_back(root->val);
        for (int i=0; i!=root->children.size(); i++) f(root->children[i], ans, l+1);
        return;
    }

    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        f(root, ans, 0);
        return ans;
    }
};