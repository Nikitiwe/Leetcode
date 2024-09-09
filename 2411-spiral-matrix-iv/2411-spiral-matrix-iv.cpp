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
        vector<int> arr(n*m, -1);
        ListNode* s=head;
        int i=0;
        while (s!=nullptr)
        {
            arr[i]=s->val;
            i++;
            s=s->next;
        }
        i=0;
        int x=0, y=0;
        vector<vector<int>> ans(m, vector<int> (n, -2));
        ans[y][x]=arr[i];
        while (i<arr.size()-1)
        {
            while (x+1<n&&ans[y][x+1]==-2)
            {
                x++;
                i++;
                ans[y][x]=arr[i];
            }
            //if (i==arr.size()) break;
            while (y+1<m&&ans[y+1][x]==-2)
            {
                y++;
                i++;
                ans[y][x]=arr[i];
            }
            //if (i==arr.size()) break;
            while (x-1>=0&&ans[y][x-1]==-2)
            {
                x--;
                i++;
                ans[y][x]=arr[i];
            }
            //if (i==arr.size()) break;
            while (y-1>=0&&ans[y-1][x]==-2)
            {
                y--;
                i++;
                ans[y][x]=arr[i];
            }
            //if (i==arr.size()) break;
        }
        return ans;
    }
};