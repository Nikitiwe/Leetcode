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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *f = l1, *s = l2, *temp;
        int add = 0, isit = 0;
        while (f&&s)
        {
            add = f->val + s->val + add;
            f->val=add%10;
            add/=10;
            if (f->next==nullptr) temp=f;
            f=f->next;
            s=s->next;
        }
        if (f!=nullptr) isit=1;
        while (f)
        {
            add = f->val + add;
            f->val=add%10;
            add/=10;
            if (f->next==nullptr) temp=f;
            f=f->next;
        }
        if (isit==0) temp->next=s;
        while (s)
        {
            add = s->val + add;
            s->val=add%10;
            add/=10;
            if (s->next==nullptr) temp=s;
            s=s->next;
        }
        if (add>0)
        {
            ListNode* newnode=new ListNode(add);
            temp->next=newnode;
        }
        return l1;
    }
};