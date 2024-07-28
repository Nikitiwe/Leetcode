class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int ans=0, d, f, t;
        int i=sqrt(l);
        if (i*i<l) i++;
        if (i==1) i++;
        while (i*i<=r)
        {
            d=2;
            f=1;
            t=sqrt(i);
            while (t>=d)
            {
                if (i%d==0) {f=0; break;}
                else d++;
            }
            if (f==1) ans++;
            i++;
        }
        return r-l+1-ans;
    }
};