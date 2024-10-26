class Solution {
public:
    int maxDistance(vector<int>& p, int k) {
        sort(p.begin(), p.end());
        int l=1, r=999999999, m;
        while (l<r)
        {
            m=(l+r)/2;
            int c=1, pr=p[0];
            for (int i=1; i<p.size(); i++)
            {
                if (p[i]-pr>=m)
                {
                    c++;
                    pr=p[i];
                }
            }
            if (c<k) r=m-1;
            else l=m+1;
        }
        {
            m=r+1;
            int c=1, pr=p[0];
            for (int i=1; i<p.size(); i++)
            {
                if (p[i]-pr>=m)
                {
                    c++;
                    pr=p[i];
                }
            }
            if (c>=k) return m;
            else m--;
        }
        {
            int c=1, pr=p[0];
            for (int i=1; i<p.size(); i++)
            {
                if (p[i]-pr>=m)
                {
                    c++;
                    pr=p[i];
                }
            }
            if (c>=k) return m;
            else m--;
        }
        {
            int c=1, pr=p[0];
            for (int i=1; i<p.size(); i++)
            {
                if (p[i]-pr>=m)
                {
                    c++;
                    pr=p[i];
                }
            }
            if (c>=k) return m;
            else return m-1;
        }
        return -1;
    }
};