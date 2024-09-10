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
            int t=gcd(s->val, s->next->val);
            ListNode *a = new ListNode (t, s->next);
            s->next=a;
            s=s->next;
            s=s->next;
        }
        return head;
    }
};
/*
    void insertGCDNode(ListNode* node1, ListNode* node2) {

        int gcdVal = gcd(node1->val, node2->val);
        ListNode* gcdNode = new ListNode(gcdVal);
        node1->next = gcdNode;
        gcdNode->next = node2;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr){
            insertGCDNode(prev, curr);
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};*/