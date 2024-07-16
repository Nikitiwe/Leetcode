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
                ans%=1000000007;
                pr*=2;
                pr%=1000000007;
                t/=2;
            }
            n--;
        }
        return ans;
    }
};