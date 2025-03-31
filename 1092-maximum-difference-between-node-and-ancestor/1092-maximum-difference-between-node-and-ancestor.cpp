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
    pair<int, int> f(TreeNode* root)
    {
        if (root == nullptr) return {-1, -1};
        int mi = root->val, ma = root->val;
        if (root->left != nullptr)
        {
            pair<int, int> p = f(root->left);
            mi = min(mi, p.first);
            ma = max(ma, p.second);
        }
        if (root->right != nullptr)
        {
            pair<int, int> p = f(root->right);
            mi = min(mi, p.first);
            ma = max(ma, p.second);
        }
        ans = max(ans, abs(root->val - mi));
        ans = max(ans, abs(root->val - ma));
        return {mi, ma};
    }

    int maxAncestorDiff(TreeNode* root) {
        f(root);
        return ans;
    }
};

/*class Solution {
public:
    int maxDiff;

    void dfs(TreeNode* node, int minVal, int maxVal) {
        if (!node) return;

        // Обновляем максимальную разницу
        maxDiff = max(maxDiff, max(abs(node->val - minVal), abs(node->val - maxVal)));

        // Обновляем минимальное и максимальное значения для потомков
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        // Рекурсивно обходим левое и правое поддерево
        dfs(node->left, minVal, maxVal);
        dfs(node->right, minVal, maxVal);
    }

    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        maxDiff = 0;
        dfs(root, root->val, root->val);
        return maxDiff;
    }
};*/