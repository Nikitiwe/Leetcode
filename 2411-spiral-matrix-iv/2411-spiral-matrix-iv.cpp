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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> arr;
        ListNode* s=head;
        int i=0;
        while (s!=nullptr)
        {
            arr.push_back(s->val);
            i++;
            s=s->next;
        }
        i=0;
        int x=0, y=0;
        vector<vector<int>> ans(m, vector<int> (n, -1));
        ans[y][x]=arr[i];
        while (i<arr.size()-1)
        {
            while (x+1<n&&ans[y][x+1]==-1&&i<arr.size()-1)
            {
                x++;
                i++;
                ans[y][x]=arr[i];
            }
            while (y+1<m&&ans[y+1][x]==-1&&i<arr.size()-1)
            {
                y++;
                i++;
                ans[y][x]=arr[i];
            }
            while (x-1>=0&&ans[y][x-1]==-1&&i<arr.size()-1)
            {
                x--;
                i++;
                ans[y][x]=arr[i];
            }
            while (y-1>=0&&ans[y-1][x]==-1&&i<arr.size()-1)
            {
                y--;
                i++;
                ans[y][x]=arr[i];
            }
        }
        return ans;
    }
};