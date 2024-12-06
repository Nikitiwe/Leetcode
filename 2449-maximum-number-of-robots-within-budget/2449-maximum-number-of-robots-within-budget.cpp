class Solution {
public:
    int maximumRobots(vector<int>& t, vector<int>& c, long long b) {
        int ans=0, l=1, r=c.size(), m;
        while (l<r)
        {
            m=(l+r)/2;
            long long s=0;
            priority_queue<int> cur, old;
            for (int i=0; i<m; i++)
            {
                s+=c[i];
                cur.push(t[i]);
            }
            if ((long long)cur.top()+(long long)m*s<=b)
            {
                ans=max(m, ans);
                l=m+1;
            }
            else
            {
                for (int i=m; i<c.size(); i++)
                {
                    s+=c[i];
                    s-=c[i-m];
                    cur.push(t[i]);
                    old.push(t[i-m]);
                    while (old.size()>0&&cur.top()==old.top())
                    {
                        cur.pop();
                        old.pop();
                    }
                    if ((long long)cur.top()+(long long)m*s<=b)
                    {
                        ans=max(m, ans);
                        l=m+1;
                        break;
                    }
                }
            }
            if (ans<m) r=m-1;
        }
        /*if (ans>0) ans--;
        if (ans>0) ans--;
        for (int k=1; k<=3; k++)*/
        {
            m=ans+1;
            long long s=0;
            priority_queue<int> cur, old;
            for (int i=0; i<m; i++)
            {
                s+=c[i];
                cur.push(t[i]);
            }
            if ((long long)cur.top()+(long long)m*s<=b)
            {
                ans=max(m, ans);
            }
            else
            {
                for (int i=m; i<c.size(); i++)
                {
                    s+=c[i];
                    s-=c[i-m];
                    cur.push(t[i]);
                    old.push(t[i-m]);
                    while (old.size()>0&&cur.top()==old.top())
                    {
                        cur.pop();
                        old.pop();
                    }
                    if ((long long)cur.top()+(long long)m*s<=b)
                    {
                        ans=max(m, ans);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};