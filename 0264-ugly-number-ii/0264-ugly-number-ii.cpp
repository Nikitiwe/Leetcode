class Solution {
public:
    int nthUglyNumber(int n) {
        if (n==1) return 1;
        long l=1, r=2123366400, m, ans=r;
        while (l<=r)
        {
            m=(l+r)/2;
            unordered_set<int> q, prev;
            long a=1;
            while (a<=m)
            {
                q.insert(a);
                a*=2;
            }
            prev=q;
            for (auto i=prev.begin(); i!=prev.end(); i++)
            {
                long a=3, b=*i;
                while (b*a<=m)
                {
                    q.insert(b*a);
                    a*=3;
                }
            }
            prev=q;
            for (auto i=prev.begin(); i!=prev.end(); i++)
            {
                long a=5, b=*i;
                while (b*a<=m)
                {
                    q.insert(b*a);
                    a*=5;
                }
            }
            if (q.size()==n) {ans=min(ans, m); r=m-1;}
            else if (q.size()<n) l=m+1;
            else r=m-1;
        }
        return ans;
    }
};