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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = head;
        ListNode* prev = head;
        if (head != nullptr) head = head->next;
        while (head != nullptr)
        {
            if (prev->val == head->val)
            {
                prev->next = head->next;
                head = head->next;
            }
            else
            {
                prev = prev->next;
                head = head->next;
            }
        }
        return ans;
    }
};