class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& s) {
        vector<string> ans(s.size(), "");
        priority_queue<long> q;
        for (int i=0; i!=s.size(); i++)
        {
            long t=s[i]*10001+i;
            q.push(t);
        }
        ans[q.top()%10001]="Gold Medal";
        q.pop();
        if (q.size()>0)
        {
            ans[q.top()%10001]="Silver Medal";
            q.pop();
        }
        if (q.size()>0)
        {
            ans[q.top()%10001]="Bronze Medal";
            q.pop();
        }
        if (q.size()>0) for (int i=3; i<s.size(); i++)
        {
            ans[q.top()%10001]=to_string(i+1);
            q.pop();
        }
        return ans;
    }
};