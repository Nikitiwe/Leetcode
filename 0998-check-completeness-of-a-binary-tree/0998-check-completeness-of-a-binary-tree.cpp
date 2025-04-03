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
    queue<TreeNode*> n;
    queue<int> q;
    int a = 0;

    bool f(TreeNode* root)
    {
        if (root == nullptr) return 1;
        n.push(root);
        q.push(1);
        while (n.size() > 0)
        {
            TreeNode* t = n.front(); n.pop();
            int b = q.front(); q.pop();
            if (b == a + 1)
            {
                a++;
                if (t->left != nullptr)
                {
                    n.push(t->left);
                    q.push(b*2);
                }
                if (t->right != nullptr)
                {
                    n.push(t->right);
                    q.push(b*2 + 1);
                }
            }
            else return 0;
        }
        return 1;
    }

    bool isCompleteTree(TreeNode* root) {
        return f(root);
    }
};