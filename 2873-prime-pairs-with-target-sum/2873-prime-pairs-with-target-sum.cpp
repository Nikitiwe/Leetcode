class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        if (n==4) return {{2,2}};
        if (n%2==1&&n>4)
        {
            int t=n-2, d=3;
            bool isit=1;
            for (d; d<=sqrt(n-2); d+=2)
            {
                if (t%d==0)
                {
                    t/=d;
                    if (t>1)
                    {
                        isit=0;
                        break;
                    }
                }
            }
            if (isit==1) return {{2,n-2}};
            else return ans;
        }
        for (int i=3; i<=n/2; i+=2)
        {
            int t=i, tt=n-i, d=3, dd=3;
            bool isit=1;
            for (d; d<=sqrt(i); d+=2)
            {
                if (t%d==0)
                {
                    t/=d;
                    if (t>1)
                    {
                        isit=0;
                    };
                    break;
                }
            }
            if (isit==1) for (dd; dd<=sqrt(n-i); dd+=2)
            {
                if (tt%dd==0)
                {
                    tt/=dd;
                    if (tt>1)
                    {
                        isit=0;
                    };
                    break;
                }
            }
            if (isit==1) ans.push_back({i, n-i});
        }
        return ans;
    }
};