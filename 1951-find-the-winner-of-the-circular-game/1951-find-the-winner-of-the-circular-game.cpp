class Solution {
public:
    int findTheWinner(int n, int k) {
        int cur=0, size=n, i=-1;
        vector<int> isit(n, 1);
        while (size!=1)
        {
            cur=0;
            while (cur<k)
            {
                i=(i+1)%n;
                if (isit[i]==1)
                {
                    cur++;
                }
            }
            isit[i]=0;
            size--;
        }
        cur=0;
        while (isit[cur]==0) cur++;
        return cur+1; 
    }
};























      /*  list<int> que;
        for (int i=1; i<=n; i++) que.push_back(i);
        ListNode *s=que.begin();
        int i=-1;
*/









         