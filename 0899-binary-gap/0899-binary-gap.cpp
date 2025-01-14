class Solution {
public:
    int binaryGap(int n) {
        int t=0, ans=0;
        bool isit=0;
        while (n>0)
        {
            if (n%2==1)
            {
                t++;
                if (isit==1) ans=max(ans, t);
                isit=1;
                t=0;
            }
            else
            {
                if (isit==1)
                {
                    t++;
                    ans=max(ans, t);
                }
            }
            n/=2;
        }
        return ans;
    }
};