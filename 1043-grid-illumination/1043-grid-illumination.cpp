class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& l, vector<vector<int>>& q) {
        unordered_map<int, int> r, c, rb, lb;
        long long d=1000000001;
        unordered_set<long long> m;
        for (int i=0; i!=l.size(); i++)
        {
            long long t=(long long)l[i][0]*d+(long long)l[i][1];
            if (m.count(t)==0)
            {
                m.insert(t);
                r[l[i][0]]++;
                c[l[i][1]]++;
                lb[l[i][0]+l[i][1]]++;
                rb[l[i][0]-l[i][1]]++;
            }
        }
        vector<int> ans(q.size(), 0);
        for (int i=0; i!=q.size(); i++)
        {
            if (r.count(q[i][0])>0||c.count(q[i][1])>0||lb.count(q[i][0]+q[i][1])>0||rb.count(q[i][0]-q[i][1])>0) ans[i]=1;
            {
                int a=q[i][0], b=q[i][1];
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
            if (q[i][0]>0&&q[i][1]>0)
            {
                int a=q[i][0]-1, b=q[i][1]-1;
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
            if (q[i][0]>0)
            {
                int a=q[i][0]-1, b=q[i][1];
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
            if (q[i][1]>0)
            {
                int a=q[i][0], b=q[i][1]-1;
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
            if (q[i][0]<n-1&&q[i][1]<n-1)
            {
                int a=q[i][0]+1, b=q[i][1]+1;
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
            if (q[i][0]<n-1)
            {
                int a=q[i][0]+1, b=q[i][1];
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
            if (q[i][1]<n-1)
            {
                int a=q[i][0], b=q[i][1]+1;
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
            if (q[i][0]<n-1&&q[i][1]>0)
            {
                int a=q[i][0]+1, b=q[i][1]-1;
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
            if (q[i][0]>0&&q[i][1]<n-1)
            {
                int a=q[i][0]-1, b=q[i][1]+1;
                long long t=(long long)a*d+(long long)b;
                if (m.count(t)>0)
                {
                    m.erase(t);
                    r[a]--; if (r[a]==0) r.erase(a);
                    c[b]--; if (c[b]==0) c.erase(b);
                    lb[a+b]--; if (lb[a+b]==0) lb.erase(a+b);
                    rb[a-b]--; if (rb[a-b]==0) rb.erase(a-b);
                }
            }
        }
        return ans;
    }
};