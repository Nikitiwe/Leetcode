class Solution {
public:
    int shipWithinDays(vector<int>& w, int d) {
        int l=*min_element(w.begin(), w.end()), r=25000001, m;
        while (l<r-1)
        {
            m=(l+r)/2;
            int s=1, t=0;
            for (int i=0; i!=w.size(); i++)
            {
                if (t+w[i]<=m) t+=w[i];
                else
                {
                    s++;
                    t=w[i];
                    if (t>m)
                    {
                        s=100000;
                        break;
                    }
                }
            }
            if (s>d) l=m+1;
            else r=m;
        }

        int s=1, t=0, n=m-1;
        {
            for (int i=0; i!=w.size(); i++)
            {
                if (t+w[i]<=n) t+=w[i];
                else
                {
                    s++;
                    t=w[i];
                    if (t>n)
                    {
                        s=100000;
                        break;
                    }
                }
            }
        }
        if (s<=d) return n;
        else
        {
        s=1; t=0;
        {
            for (int i=0; i!=w.size(); i++)
            {
                if (t+w[i]<=m) t+=w[i];
                else
                {
                    s++;
                    t=w[i];
                    if (t>m)
                    {
                        s=100000;
                        break;
                    }
                }
            }
        }
        if (s<=d) return m;
        else
        {
            int mm=m+1;
            s=1; t=0;
            for (int i=0; i!=w.size(); i++)
            {
                if (t+w[i]<=mm) t+=w[i];
                else
                {
                    s++;
                    t=w[i];
                    if (t>mm)
                    {
                        s=100000;
                        break;
                    }
                }
            }
            if (s<=d) return mm;
            else return mm+1;
        }
        }
        return -1;
    }
};