class Solution {
public:
    vector<int> closestPrimes(int l, int r) {
        if (l<=2&&r>=3) return {2, 3};
        vector<int> ans{-1, -1};
        if (l%2==0||l==1) l++;
        int prev=-1, n=-1, d=1000000;
        for (int i=l; i<=r; i+=2)
        {
            int t=i, q=sqrt(t), k=3;
            bool isit=1;
            while (k<=q)
            {
                if (t%k==0)
                {
                    isit=0;
                    break;
                }
                k+=2;
            }
            if (isit==1)
            {
                if (prev==-1) prev=i;
                else if (n==-1)
                {
                    n=i;
                    if (n-prev<d)
                    {
                        ans[0]=prev;
                        ans[1]=n;
                        d=ans[1]-ans[0];
                        if (d==2) return ans;
                    }
                }
                else
                {
                    prev=n;
                    n=i;
                    if (n-prev<d)
                    {
                        ans[0]=prev;
                        ans[1]=n;
                        d=ans[1]-ans[0];
                        if (d==2) return ans;
                    }
                }
            }
        }
        return ans;
    }
};