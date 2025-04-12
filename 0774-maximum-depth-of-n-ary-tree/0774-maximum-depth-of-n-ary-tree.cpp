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
    int ans = 0;
    void f(Node* root, int l)
    {
        if (root == nullptr) return;
        ans = max(ans, l);
        for (int i=0; i!=root->children.size(); i++) f(root->children[i], l+1);
        return;
    }

    int maxDepth(Node* root) {
        f(root, 1);
        return ans;
    }
};