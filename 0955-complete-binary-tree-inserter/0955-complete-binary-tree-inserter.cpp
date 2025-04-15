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
    void f(TreeNode* root, int l, vector<TreeNode*> &arr, vector<TreeNode*> &next, int &id, int h)
    {
        queue<TreeNode*> q;
        queue<int> lev;
        q.push(root);
        lev.push(l);
        while(q.size() > 0)
        {
            TreeNode* t = q.front();
            int ll = lev.front();
            q.pop(); lev.pop();
            if (h == ll)
            {
                arr.push_back(t);
            }
            else if (h + 1 == ll)
            {
                next.push_back(t);
            }
            else if (h + 2 == ll)
            {
                h++;
                arr = next;
                next.clear();
                next.push_back(t);
            }
            if (t->left != nullptr)
            {
                q.push(t->left);
                lev.push(ll+1);
            }
            if (t->right != nullptr)
            {
                q.push(t->right);
                lev.push(ll+1);
            }
        }
    }

class CBTInserter {
public:
    TreeNode* root;
    vector<TreeNode*> arr, next;
    int id, h;
    CBTInserter(TreeNode* n) {
        root = n;
        h = 0;
        id = 0;
        f(root, 0, arr, next, id, h);
    }
    
    int insert(int v) {
        while (id < arr.size())
        {
            if (arr[id]->left == nullptr)
            {
                TreeNode* n = new TreeNode;
                n->val = v;
                n->left = nullptr;
                n->right = nullptr;
                arr[id]->left = n;
                next.push_back(n);
                return arr[id]->val;
            }
            else if (arr[id]->right == nullptr)
            {
                TreeNode* n = new TreeNode;
                n->val = v;
                n->left = nullptr;
                n->right = nullptr;
                arr[id]->right = n;
                next.push_back(n);
                return arr[id]->val;
            }
            else id++;
        }
        if (id == arr.size())
        {
            id = 0;
            arr = next;
            next.clear();
            {
                TreeNode* n = new TreeNode;
                n->val = v;
                n->left = nullptr;
                n->right = nullptr;
                arr[0]->left = n;
                next.push_back(n);
                return arr[0]->val;
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */