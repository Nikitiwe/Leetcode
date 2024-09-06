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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> m;
        for (int i=0; i!=nums.size(); i++)
        {
            m.insert(nums[i]);
        }
        ListNode *s=head, *f=head;
        vector<int> arr;
        while (s!=nullptr)
        {
            if (m.count(s->val)==0)
            {
                arr.push_back(s->val);
            }
            s=s->next;
        }
        int i=0;
        while (i<arr.size())
        {
            f->val=arr[i];
            i++;
            if (i!=arr.size()) f=f->next;
            else f->next=nullptr;
        }
        return head;
    }
};