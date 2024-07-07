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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *s=head, *f=head;
        int i=1;
        while (f!=nullptr)
        {
            f=f->next;
            i++;            
        }
        f=head;
        for (int j=1; j!=k; j++)
        {
            s=s->next;
        }
        for (int j=1; j!=i-k; j++)
        {
            f=f->next;
        }
        swap (s->val, f->val);
        return head;

    }
};