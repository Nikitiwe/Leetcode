/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool f(TreeNode* root, vector<int> &arr)
    {
        if (root == nullptr) return 0;
        bool t = 0;
        if (root->val == arr[0]) t = g(root, arr, 0);
        if (t == 1) return 1;
        return f(root->left, arr) || f(root->right, arr);
        return 0;
    }

    bool g(TreeNode* root, vector<int> &arr, int l)
    {
        if (l == arr.size()) return 1;
        if (root == nullptr) return 0;
        if (root->val == arr[l]) return g(root->left, arr, l+1) || g(root->right, arr, l+1);
        return 0;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> arr;
        while (head != nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        return f(root, arr);
        return 0;
    }
};