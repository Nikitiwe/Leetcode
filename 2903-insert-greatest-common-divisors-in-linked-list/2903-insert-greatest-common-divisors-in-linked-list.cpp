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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *s=head;
        while (s!=nullptr&&s->next!=nullptr)
        {
            ListNode *a = new ListNode (gcd(s->val, s->next->val), s->next);
            s->next=a;
            s=s->next->next;
        }
        return head;
    }
};