class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=0, t, pr=1;
        while (n>0)
        {
            t=n;
            while (t>0)
            {
                ans+=(t%2)*pr;
                pr*=2;
                t/=2;
            }
            ans%=1000000007;
            pr%=1000000007;
            n--;
        }
        return ans;
    }
};