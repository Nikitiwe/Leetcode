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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *s=head;
        while (s)
        {
            if (s->val==val&&s==head) {head=s->next; s=s->next;}
            else if (s->next&&s->next->val==val)
            {
                s->next=s->next->next;
                if (s->next&&s->next->val!=val) s=s->next;
            }
            else if (s->next&&s->next->val==val) {s->next=nullptr; s=s->next;}
            else s=s->next;
        }
        return head;
    }
};