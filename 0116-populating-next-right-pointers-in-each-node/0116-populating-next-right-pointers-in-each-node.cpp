/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    queue<Node*> n;
    queue<int> l;

    void f(Node* root, int a)
    {
        if (root == NULL) return;
        n.push(root);
        l.push(a);
        while (n.size() > 0)
        {
            Node* t = n.front();
            int b = l.front();
            n.pop();
            l.pop();
            if (t->left != NULL)
            {
                n.push(t->left);
                l.push(b+1);
            }
            if (t->right != NULL)
            {
                n.push(t->right);
                l.push(b+1);
            }
            if (l.size() > 0 && l.front() == b) t->next = n.front();
        }
        return;
    }

    Node* connect(Node* root) {
        f(root, 0);
        return root;
    }
};