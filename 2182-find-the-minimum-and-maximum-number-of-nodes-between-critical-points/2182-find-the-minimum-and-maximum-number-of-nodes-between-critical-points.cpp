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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=0, f=-1, prev=-1, last=0, min=10000000;
        ListNode *s=head;
        while (s->next->next!=nullptr)
        {
            if (s->val > s->next->val && s->next->val < s->next->next->val ||
                s->val < s->next->val && s->next->val > s->next->next->val)
                {
                    if (f==-1) f=i;
                    if (prev!=-1)
                    {
                        if (i-prev<min) min=i-prev;
                    }
                    if (prev=-1) prev=i;
                }
            s=s->next;
            i++;
        }
        if (min==10000000) return {-1, -1};
        else return {min, prev-f};
    }
};