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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* nextSum=temp;
        while (nextSum!=nullptr)
        {
            int sum=0;
            while (nextSum->val!=0)
            {
                sum=sum+nextSum->val;
                nextSum=nextSum->next;
            }
            temp->val=sum;
            nextSum=nextSum->next;
            temp->next=nextSum;
            temp=temp->next;
        }
        return head->next;
    }
};