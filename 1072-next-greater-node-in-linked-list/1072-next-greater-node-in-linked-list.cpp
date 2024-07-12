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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *s=head;
        vector<int> ans, isit;
        int temp;
        while (s!=nullptr)
        {
            temp=s->val;
            for (int i=0; i!=ans.size(); i++)
            {
                if (isit[i]==0) if (temp>ans[i]) {ans[i]=temp; isit[i]=1;}
            }
            ans.push_back(temp);
            isit.push_back(0);
            s=s->next;
        }
        for (int i=0; i!=ans.size(); i++)
        {
            if (isit[i]==0) ans[i]=0;
        }
        return ans;
    }
};