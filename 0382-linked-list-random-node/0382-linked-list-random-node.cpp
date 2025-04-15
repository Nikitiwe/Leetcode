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
    ListNode* head;
    int l;
    Solution(ListNode* h) {
        head = h;
        l = 0;
        ListNode* t = head;
        while (t != nullptr)
        {
            t = t->next;
            l++;
        }
    }
    
    int getRandom() {
        int a = rand()%l;
        ListNode* t = head;
        for (int i=0; i<a; i++) t = t->next;
        //return a;
        return t->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */