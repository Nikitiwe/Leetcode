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
    TreeNode* f(vector<int> &arr, int l, int r)
    {
        if (l > r) return nullptr;
        TreeNode* n = new TreeNode;
        n->val = arr[(l+r)/2];
        n->left = f(arr, l, (l+r)/2 - 1);
        n->right = f(arr, (l+r)/2 + 1, r);
        return n;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return {};
        vector<int> arr;
        while (head != nullptr)
        {
            arr.push_back(head->val);
            head = head->next;
        }
        return f(arr, 0, arr.size()-1);
    }
};