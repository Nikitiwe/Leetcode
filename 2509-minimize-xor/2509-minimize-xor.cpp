class Solution {
public:
    int minimizeXor(int y, int x) {
        vector<int> b(30, 0), c(30, 0);
        int k=0;
        while (x>0)
        {
            k+=x%2;
            x/=2;
        }
        int l=0;
        while (y>0)
        {
            b[l]=y%2;
            y/=2;
            l++;
        }
        l=29;
        while (k>0&&l>=0)
        {
            if (b[l]==1)
            {
                c[l]=1;
                k--;
            }
            l--;
        }
        l=0;
        while (k>0)
        {
            if (b[l]==0)
            {
                c[l]=1;
                k--;
            }
            l++;
        }
        int ans=0, d=1;
        for (int i=0; i!=c.size(); i++)
        {
            ans+=c[i]*d;
            d*=2;
        }
        return ans;
    }
};